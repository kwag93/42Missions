/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:59:38 by bkwag             #+#    #+#             */
/*   Updated: 2020/11/25 16:33:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	apply_0x(char **str, int *len)
{
	char *new_str;

	if (!str || !*str)
		return (false);
	if (!(new_str = malloc(*len + 3)))
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
	if (tag->precision < 0)
		return (true);
	if (tag->precision > (int)*len)
	{
		if (!(dupstr = malloc(tag->precision + 1)))
			return (false);
		ft_memset(dupstr, '0', tag->precision - *len);
		ft_strlcpy(dupstr + tag->precision - *len, *pointer_str, *len + 1);
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

	if (!p_str || !*p_str || len < 0 || !tag)
		return (0);
	if (tag->width <= *len)
		return (1);
	if (!(new_pointer = malloc(tag->width + 1)))
		return (0);
	if (tag->left_align)
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
	if (!apply_precision_pointer(pointer_str, &len, tag) ||
		!apply_0x(pointer_str, &len) ||
		!apply_left_align_pointer(pointer_str, &len, tag))
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
	value = va_arg(data->ap, size_t);
	if (value == 0 && tag->precision == 0)
	{
		if (!(result = ft_strdup("")))
			return (0);
	}
	else
		result = ft_lltoa_base((unsigned long long)value, "0123456789abcdef");
	answer = write_pointer(&result, tag, data);
	free(result);
	return (answer);
}
