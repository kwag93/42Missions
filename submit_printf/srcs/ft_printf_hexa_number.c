/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:59:23 by bkwag             #+#    #+#             */
/*   Updated: 2020/11/25 16:29:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_hexa_number(char **number_str, t_format_tag *tag, t_data *data)
{
	int	len;

	if (!number_str || !*number_str || !tag || !data)
		return (0);
	len = ft_strlen(*number_str);
	if (!apply_precision(number_str, &len, tag) ||
		!apply_left_align(number_str, &len, tag))
		return (0);
	data->total_len += len;
	return (ft_putstr_fd(*number_str, 1));
}

int	print_hexa_number(t_data *data, t_format_tag *tag, bool islowercase)
{
	int				result;
	char			*str;
	unsigned int	value;

	if (!data || !tag)
		return (0);
	value = va_arg(data->ap, unsigned int);
	if (!(str = ft_lltoa_base((long long)value, islowercase ?
	"0123456789abcdef" : "0123456789ABCDEF")))
		return (0);
	result = write_hexa_number(&str, tag, data);
	free(str);
	return (result);
}
