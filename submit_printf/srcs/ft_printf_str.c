/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:59:42 by bkwag             #+#    #+#             */
/*   Updated: 2020/11/25 16:41:06 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	apply_precision_str(char **str, t_data *data, t_format_tag *tag)
{
	char *new_str;

	if (!str || !*str || !data || !tag)
		return (false);
	if (tag->precision < 0 || tag->precision >= (int)ft_strlen(*str))
		return (true);
	if (!(new_str = (char *)malloc(sizeof(char *) * (tag->precision + 1))))
		return (false);
	ft_strlcpy(new_str, *str, tag->precision + 1);
	free(*str);
	*str = new_str;
	return (true);
}

char	*print_flags_str(char *str, t_data *data, t_format_tag *tag)
{
	char	*flag_result;
	int		str_len;
	char	c;

	str_len = (int)ft_strlen(str);
	if (!tag || !str)
		return (NULL);
	if (tag->width <= str_len)
		return (ft_strdup(""));
	if (!(flag_result = (char *)malloc(sizeof(char)
					* tag->width - str_len + 1)))
		return (NULL);
	if (!tag->left_align && tag->fill_zero)
		c = '0';
	else
		c = ' ';
	ft_memset(flag_result, c, tag->width - str_len);
	flag_result[tag->width - str_len] = '\0';
	data->total_len += tag->width - ft_strlen(str);
	return (flag_result);
}

int		print_general_str(t_data *data, t_format_tag *tag, char *str)
{
	char	*flags_str;
	int		result_text;
	int		result_str;

	if (!data || !tag || !str)
		return (0);
	if (!(flags_str = print_flags_str(str, data, tag)))
		return (0);
	if (tag->left_align)
	{
		result_text = ft_putstr_fd(str, 1);
		result_str = ft_putstr_fd(flags_str, 1);
		data->total_len += ft_strlen(str);
	}
	else
	{
		result_str = ft_putstr_fd(flags_str, 1);
		result_text = ft_putstr_fd(str, 1);
		data->total_len += ft_strlen(str);
	}
	free(flags_str);
	if (result_str < 0 || result_text < 0)
		return (0);
	return (1);
}

int		print_str(t_data *data, t_format_tag *tag)
{
	char	*str;
	char	*newstr;
	int		result;

	if (!data || !tag)
		return (false);
	str = va_arg(data->ap, char *);
	if (str == NULL)
	{
		if (!(newstr = ft_strdup("(null)")))
			return (false);
	}
	else
		newstr = ft_strdup(str);
	apply_precision_str(&newstr, data, tag);
	result = print_general_str(data, tag, newstr);
	free(newstr);
	return (result);
}
