/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:05:32 by hyunyoo           #+#    #+#             */
/*   Updated: 2020/11/03 11:38:01 by hyunyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*parse_flags(char *duptag, t_format_tag *tag)
{
	char		*addr;
	char		flag;

	if (duptag == NULL || tag == NULL) //에러 처리
		return (NULL);
	while ((addr = ft_strchr(TAG_FLAG_SET, *duptag))) //duptag(%이후부터 문자 1개)가 TAG_FLAG_SET에서 어느 인덱스에 위치해있는지 찾는다.
	{
		flag = TAG_FLAG_SET[addr - TAG_FLAG_SET]; //인덱스 판단
		if (flag == '-')
			tag->left_align = true;
		else if (flag == '+')
			tag->sign = true;
		else if (flag == ' ')
			tag->sign_space = true;
		else if (flag == '#')
			tag->sharp = true;
		else if (flag == '0')
			tag->fill_zero = true;
		else
			return (NULL);
		duptag++; //flag가 여러 개 들어올 수 있으므로 다음 문자 확인
	}
	return (duptag);
}

char		*parse_width(char *duptag, t_format_tag *tag, t_data *data)
{
	char	*addr;
	int		n;

	if (!duptag || !tag || !data) //에러처리
		return (NULL);
	if (*duptag == '*') //asterisk 사용시 sentense가 아니라 인자를 통해 너비를 전달 받는다. ("%*d", 5, 5)
	{
		n = va_arg(data->ap, int); //너비는 int형 범위를 갖는다.
		if (n < 0) //음수인 경우 -는 좌측정렬 플래그로 파악한다.
		{
			tag->left_align = true;
			n *= -1; //-를 떼낸 후 양수로 전환
		}
		tag->width = n; //너비 입력
		return (++duptag); //너비 끝났으므로 다음 문자로 이동 후 반환
	}
	if (!ft_isdigit(*duptag) || *duptag == '0') //숫자가 아니거나 0이면은 너비의 의미가 없으므로 종료
		return (duptag);
	while ((addr = ft_strchr(DECIMAL_SET, *duptag))) //duptag가 문자열이므로 문자열->숫자 변환이 필요하다.
	{
		tag->width = tag->width * 10 + (DECIMAL_SET[addr - DECIMAL_SET] - '0'); //atoi와 동일한 방식으로 자리수를 올려가며 더해준다
		duptag++;
	}
	return (duptag);
}

char		*parse_precision(char *duptag, t_format_tag *tag, t_data *data)
{
	char	*addr;
	int		n;

	if (!duptag || !tag || !data) //에러 처리
		return (NULL);
	if (*duptag != '.') //정밀도 사용안한 거니까 종료
		return (duptag);
	duptag++; //.을 지나침
	if (*duptag == '*') //asterisk 사용시 인자로 정밀도 값이 들어온다.
	{
		n = va_arg(data->ap, int);
		if (n < 0) //음수이면 너비와 달리 정밀도를 사용 안하는 걸로 처리한다.
			n = -1;
		tag->precision = n;
		return (++duptag);
	}
	tag->precision = 0; // precision이 존재하면 0으로 초기화해줌
	while ((addr = ft_strchrset(duptag, DECIMAL_SET))) //duptag에서 precision 내용을 정수로 변환
	{
		tag->precision = tag->precision * 10 +
		(DECIMAL_SET[addr - DECIMAL_SET] - '0'); // precision값을 자리값맞춰주는 과정
		duptag++;
	}
	return (duptag);
}

char		*parse_option_2(char *duptag, t_format_tag *tag, t_data *data)
{
	if (duptag == NULL || tag == NULL)
		return (NULL);
	if (!(duptag = parse_flags(duptag, tag)) || //flag 변환
		!(duptag = parse_width(duptag, tag, data)) || //width 변환
		!(duptag = parse_precision(duptag, tag, data))) //정밀도 변환
		return (NULL);
	return (duptag);
}

char		*parse_specifier(char *duptag, t_format_tag *tag)
{
	char	*addr;

	if (duptag == NULL || tag == NULL ||
	!(addr = ft_strchr(TAG_SPECIFIER_SET, *duptag))) //TAG_SPECIFIER_SET 중에서 duptag가 가리키는 문자가 어디있는지 파악
		return (NULL);
	tag->specifier = TAG_SPECIFIER_SET[addr - TAG_SPECIFIER_SET];
	duptag++;
	return (duptag);
}
