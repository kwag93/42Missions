/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:07:21 by hyunyoo           #+#    #+#             */
/*   Updated: 2020/11/02 16:35:45 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_hexa_number(char **number_str, t_format_tag *tag, t_data *data)
{
	int	len;

	if (!number_str || !*number_str || !tag || !data)
		return (0);
	len = ft_strlen(*number_str);
	if (!apply_precision(number_str, &len, tag) || // precision과 left_align의 경우 기존의 함수작동과 동일하다. lltoa_base로 이미 문자열로 바꿔서 보내기에 차이가 없음.
		!apply_left_align(number_str, &len, tag))
		return (0);
	data->total_len += len;
	return (ft_putstr_fd(*number_str, 1));
}

int		print_hexa_number(t_data *data, t_format_tag *tag, bool islowercase)
{
	int				result;
	char			*str;
	unsigned int	value;

	if (!data || !tag)
		return (0);
	value = va_arg(data->ap, unsigned int); //l,ll,h,hh 안쓰므로 제일 큰 자료형은 unsigned int
	if (!(str = ft_lltoa_base((long long)value, islowercase ? // 처음에는 ll까지 하려고 해서 최대값인 lltoa로 만들어놨으나 구현은 하지 않음.
	"0123456789abcdef" : "0123456789ABCDEF"))) //16진수로 변환하는데 x/X에 따라 알파벳이 달라지므로 삼항연산자를 사용해서 구분해준다.
		return (0);
	result = write_hexa_number(&str, tag, data); //변환된 문자열 출력
	return (result);
}
