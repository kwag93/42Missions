/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_option2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:58:29 by hyunyoo           #+#    #+#             */
/*   Updated: 2020/11/03 12:36:15 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format_tag	*init_tags(void)
{
	t_format_tag *new_tag;

	if (!(new_tag = (t_format_tag *)malloc(sizeof(t_format_tag))))
		return (0);
	new_tag->specifier = 0;
	new_tag->width = 0;
	new_tag->precision = -1; // precision은 0이 될수 있기 때문. 	ft_printf("%.0d\n", 0); 이 경우 공백을 출력해야 함
	new_tag->length = 0;
	new_tag->left_align = false;
	new_tag->sign = false;
	new_tag->sign_space = false;
	new_tag->sharp = false;
	new_tag->fill_zero = false;
	return (new_tag);
}

int				apply_left_align(char **number_str, int *len, t_format_tag *tag)
{
	char space_char; //공백에 사용할 문자
	char *new_num; //공백만큼 문자열이 늘어나므로 새로운 문자열을 만들어서 사용한다.

	if (!number_str || !*number_str || !len || !tag) //에러 처리
		return (0);
	if (tag->width <= *len) //문자열 길이보다 너비가 작거나 같은 경우 공백을 넣을 공간이 없으므로 종료. 대신 실패한 건 아니고 출력할 공간이 없는 것이므로 이후 작업을 위해 성공으로 처리한다.
		return (1);
	if (!(new_num = malloc(tag->width + 1))) //전체 너비+eof
		return (0);
	if (tag->left_align) //좌측 정렬인 경우 선 숫자, 후 공백
	{
		ft_strlcpy(new_num, *number_str, *len + 1); //얕은복사와 깊은복사에 대한 실수가 나왔던 부분.
		ft_memset(new_num + *len, ' ', tag->width - *len);
		new_num[tag->width] = '\0';
	}
	else //우측 정렬인 경우 선 공백, 후 숫자
	{
		space_char = (tag->fill_zero && tag->precision < 0) ? '0' : ' '; //0플래그가 사용중인 경우 0 아닌 경우 공백 출력 예정(0플래그는 정밀도와 중복 사용이 불가)
		ft_memset(new_num, space_char, tag->width - *len);
		ft_strlcpy(new_num + (tag->width - *len), *number_str, *len + 1);
	}
	free(*number_str); //기존 문자열 해제
	*number_str = new_num; //새로운 문자열 연결
	*len = tag->width; //공백 포함 전체 너비로 길이 변경
	return (1);
}

int				apply_sign(char **str, int *len, t_format_tag *tag, bool minus)
{
	char *new_num;

	if (!str || !*str || !tag) //에러처리
		return (false);
	if (!minus && !tag->sign && !tag->sign_space) //만약 음수가 아니고, +플래그와 ' '플래그를 사용하지 않은 경우 부호를 적용할 필요가 없으므로 성공으로 처리
		return (true);
	if (!(new_num = malloc(*len + 2))) //+2인 이유 : 원래 문자열 + 부호 + eof
		return (false);
	if (minus)
	{
		*new_num = '-';
		ft_strlcpy(new_num + 1, *str, *len + 1);
	}
	else
	{
		*new_num = tag->sign ? '+' : ' ';
		ft_strlcpy((new_num + 1), *str, *len + 1);
	}
	free(*str);
	*str = new_num;
	*len += 1;
	return (true);
}

bool			apply_precision(char **number_str, int *len, t_format_tag *tag)
{
	if (!number_str || !*number_str || !tag)
		return (false);
	if (tag->precision < 0) //초기값이 -1이므로 precision이 존재하지 않는경우 return
		return (true);
	return (ft_specifier_others(number_str, len, tag));
}
