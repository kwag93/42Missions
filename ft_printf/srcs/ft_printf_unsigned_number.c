/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_number.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:55:35 by hyunyoo           #+#    #+#             */
/*   Updated: 2020/11/03 13:25:33 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_unsigned_number(char **str, t_format_tag *tag, t_data *data)
{
	int len;

	if (!str || !*str || !tag || !data)
		return (0);
	len = ft_strlen(*str);
	if (!apply_precision(str, &len, tag) || //precision과 left_align 모두 동일한 방식으로 작동한다.
		!apply_left_align(str, &len, tag))
		return (0);
	data->total_len += len;
	return (ft_putstr_fd(*str, 1));
}

int		print_unsigned_number(t_data *data, t_format_tag *tag)
{
	int				result;
	char			*str;
	unsigned int	value;

	if (!data || !tag)
		return (0);
	value = va_arg(data->ap, unsigned int); //unsigned int 로 값을 받아 저장해줌
	if (!(str = ft_lltoa((long long)value)))
		return (0);
	result = write_unsigned_number(&str, tag, data);
	return (result);
}
