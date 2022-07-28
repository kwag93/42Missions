/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:42:14 by hyunyoo           #+#    #+#             */
/*   Updated: 2020/11/03 13:13:19 by hyunyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	apply_0x(char **str, int *len)
{
	char *new_str;

	if (!str || !*str)
		return (false);
	if (!(new_str = malloc(*len + 3))) //0x + eof 길이 : 3
		return (false);
	ft_strlcpy(new_str, "0x", 3);
	ft_strlcpy(new_str + 2, *str, *len + 1);
	free(*str);
	*str = new_str;
	*len += 2;
	return (true);
}

bool	apply_precision_pointer(char **pointer_str, int *len, t_format_tag *tag)
{
	char *dupstr;

	if (!pointer_str || !*pointer_str || !tag)
		return (false);
	if (tag->precision < 0) //정밀도 사용 안 하는 경우
		return (true);
	if (tag->precision > (int)*len) // 정밀도가 len보다 크다면 그 값만큼 0을 채워준다.
	{
		if (!(dupstr = malloc(tag->precision + 1)))
			return (false);
		ft_memset(dupstr, '0', tag->precision - *len); // 정밀도가 len보다 큰 숫자 만큼 0을 채워준다.
		ft_strlcpy(dupstr + tag->precision - *len, *pointer_str, *len + 1); //0이후에 숫자를 복사해준다.
		free(*pointer_str);
		*pointer_str = dupstr;
		*len = tag->precision;
	}
	else if (tag->precision == 0) // precision이 0이라면 빈 문자열을 출력해준다. undefined behavior부분임.
	{
		if (!(dupstr = ft_strdup("")))
			return (false);
		free(*pointer_str);
		*pointer_str = dupstr;
		*len = tag->precision;
	}
	return (true);
}

int		apply_left_align_pointer(char **p_str, int *len, t_format_tag *tag)
{
	char space_char;
	char *new_pointer;

	if (!p_str || !*p_str || len < 0 || !tag) //에러 처리
		return (0);
	if (tag->width <= *len) //len보다 짧은 너비인 경우 출력할 여분이 없으므로 통과.
		return (1);
	if (!(new_pointer = malloc(tag->width + 1)))
		return (0);
	if (tag->left_align) // 좌측정렬은 숫자를 먼저 출력하고 공백 또는 0을 붙여준다.
	{
		ft_strlcpy(new_pointer, *p_str, *len + 1);
		ft_memset(new_pointer + *len, ' ', tag->width - *len + 1);
		new_pointer[tag->width] = '\0';
	}
	else
	{
		space_char = (tag->fill_zero && tag->precision < 0) ? '0' : ' ';
		ft_memset(new_pointer, space_char, tag->width - *len + 1);
		ft_strlcpy(new_pointer + (tag->width - *len), *p_str, *len + 1);
	}
	free(*p_str);
	*p_str = new_pointer;
	*len = tag->width;
	return (1);
}

int		write_pointer(char **pointer_str, t_format_tag *tag, t_data *data)
{
	int len;

	if (!pointer_str || !*pointer_str || !tag || !data)
		return (0);
	len = ft_strlen(*pointer_str);
	if (!apply_precision_pointer(pointer_str, &len, tag) || //정밀도부터
		!apply_0x(pointer_str, &len) || //다음 앞에 0x를 붙여서 기본 출력 틀 완성
		!apply_left_align_pointer(pointer_str, &len, tag)) //정렬, 너비 관련 처리
		return (0);
	data->total_len += len;
	return (ft_putstr_fd(*pointer_str, 1));
}

int		print_pointer(t_data *data, t_format_tag *tag)
{
	size_t	value;
	char	*result;
	int		answer;

	if (!data || !tag)
		return (0);
	value = va_arg(data->ap, size_t); //최대값인 size_t로 받아주었다
	if (value == 0 && tag->precision == 0) // 값이 없고, precision을 0으로 주면 공백을 출력한다
	{
		if (!(result = ft_strdup("")))
			return (0);
	}
	else
		result = ft_lltoa_base((unsigned long long)value, "0123456789abcdef");
	answer = write_pointer(&result, tag, data);
	return (answer);
}
