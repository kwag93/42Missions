/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_number.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:59:46 by bkwag             #+#    #+#             */
/*   Updated: 2020/11/25 16:30:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_unsigned_number(char **str, t_format_tag *tag, t_data *data)
{
	int	len;

	if (!str || !*str || !tag || !data)
		return (0);
	len = ft_strlen(*str);
	if (!apply_precision(str, &len, tag) ||
		!apply_left_align(str, &len, tag))
		return (0);
	data->total_len += len;
	return (ft_putstr_fd(*str, 1));
}

int	print_unsigned_number(t_data *data, t_format_tag *tag)
{
	int				result;
	char			*str;
	unsigned int	value;

	if (!data || !tag)
		return (0);
	value = va_arg(data->ap, unsigned int);
	if (!(str = ft_lltoa((long long)value)))
		return (0);
	result = write_unsigned_number(&str, tag, data);
	free(str);
	return (result);
}
