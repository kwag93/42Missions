/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:59:19 by bkwag             #+#    #+#             */
/*   Updated: 2020/11/25 16:29:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_flags_char(t_data *data, t_format_tag *tag)
{
	char	*flag_result;
	char	c;

	if (!tag)
		return (NULL);
	if ((size_t)tag->width <= 1)
		return (ft_strdup(""));
	if (!(flag_result = (char *)malloc(sizeof(char) * tag->width)))
		return (NULL);
	if (!tag->left_align && tag->fill_zero)
	{
		c = '0';
	}
	else
		c = ' ';
	ft_memset(flag_result, c, tag->width - 1);
	flag_result[tag->width - 1] = '\0';
	data->total_len += tag->width - 1;
	return (flag_result);
}

int		print_general_character(t_data *data, t_format_tag *tag, char c)
{
	char	*flags_str;
	int		result_char;
	int		result_str;

	if (!data || !tag)
		return (0);
	if (!(flags_str = print_flags_char(data, tag)))
		return (0);
	if (tag->left_align)
	{
		result_char = ft_putchar_fd(c, 1);
		result_str = ft_putstr_fd(flags_str, 1);
		data->total_len += 1;
	}
	else
	{
		result_str = ft_putstr_fd(flags_str, 1);
		result_char = ft_putchar_fd(c, 1);
		data->total_len += 1;
	}
	free(flags_str);
	if (result_char != 1 || result_str < 0)
		return (0);
	return (1);
}

int		print_character(t_data *data, t_format_tag *tag)
{
	char letter;

	if (!data || !tag)
		return (0);
	letter = (char)va_arg(data->ap, int);
	return (print_general_character(data, tag, letter));
}
