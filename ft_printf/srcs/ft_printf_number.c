/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:04:03 by hyunyoo           #+#    #+#             */
/*   Updated: 2020/11/03 13:03:17 by hyunyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		move_sign(char *number_str, t_format_tag *tag, bool negative)
{
	char *addr;
	char temp;
	//05와 같이 0을 채워야하는 경우 숫자 앞에 부호가 붙으면 잘못된것이기 때문에 -00001과 같이 바꾸어주려고 move_sign을 사용함
	if (!number_str || !*number_str || !tag) //에러 처리
		return (false);
	if (!tag->fill_zero || (!negative && !tag->sign && !tag->sign_space)) //필수 조건 : 0플래그 사용, 부호를 붙일 필요가 없는 경우는 그냥 패스
		return (true);
	if (!(addr = ft_strchrset(number_str, tag->sign_space ? "+- " : "+-"))) //' ' 플래그가 들어간 경우
		return (false);
	temp = *addr; // addr은 + - ' ' 중 하나의 값이 들어가있음
	*addr = *number_str;
	*number_str = temp; // swap과정을 진행
	return (true);
}

bool	ft_specifier_others(char **number_str, int *len, t_format_tag *tag)
{
	char	*dupstr;

	if (ft_strchr("diuxX", tag->specifier)) //문자열 제외하고는 비슷한 처리방법
	{
		if (tag->precision > (int)*len) //정밀도가 길이보다 긴 경우 나머지를 0으로 채워준다.
		{
			if (!(dupstr = malloc(tag->precision + 1)))
				return (false);
			ft_memset(dupstr, '0', tag->precision - *len); // 00000채우는 위치
			ft_strlcpy(dupstr + tag->precision - *len, *number_str, *len + 1); //0을 채운 다음위치인 숫자 복사
			free(*number_str); //원래 숫자는 필요 없으므로 해제
			*number_str = dupstr; //새로운 정밀도 추가한 숫자 대입
			*len = tag->precision;
		}
		else if (tag->precision == 0 && **number_str == '0') // ("%0d", 0)인 경우를 처리해 줌 이때 공백이 나와야 함
		{
			if (!(dupstr = ft_strdup(""))) //공백
				return (false);
			free(*number_str);
			*number_str = dupstr; // number_str에 공백을 채움.
			*len = tag->precision;
		}
		return (true);
	}
	return (true);
}

int		write_number(char **number_str, t_format_tag *tag, t_data *data)
{
	bool	negative; // 들어온 숫자(지금은 문자열로 변환되어있음)가 음수인지를 확인하기 위함.
	int		len;
	char	*temp;

	negative = false;
	if (!number_str || !*number_str || !tag || !data)
		return (0);
	if (**number_str == '-') //문자열의 처음이 -라면
	{
		negative = true;
		if (!(temp = ft_strdup((*number_str) + 1))) //음수인 경우 정밀도 처리할 때 -가 방해되므로 나중에 처리해주고 우선은 숫자만 뽑아낸다.
			return (0);
		free(*number_str);
		*number_str = temp; // - 를 제외한 문자열을 넣어주었음.
	}
	len = ft_strlen(*number_str);
	if (!apply_precision(number_str, &len, tag) || //우선 정밀도 처리해서 출력할 문자열을 정확하게 한 뒤 진행
	!apply_sign(number_str, &len, tag, negative) || //부호(위에서 없앤 -, +/' '플래그) 붙이기
		!apply_left_align(number_str, &len, tag) ||
		(tag->precision < 0 && !move_sign(*number_str, tag, negative))) //정밀도를 사용안할 때 일부 케이스에서 부호를 옮겨줘야한다.
		return (0); //
	data->total_len += len;
	return (ft_putstr_fd(*number_str, 1));
}

int		print_number(t_data *data, t_format_tag *tag)
{
	int			result;
	char		*str;
	long long	value;

	if (!data || !tag)
		return (0);
	value = (int)va_arg(data->ap, int);
	if (!(str = ft_lltoa(value))) //문자열로 변환
		return (0);
	result = write_number(&str, tag, data); //result가 0이면 실패로 처리됨. 그 이외의 숫자는 상관없음.
	return (result);
}
