/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:59:51 by bkwag             #+#    #+#             */
/*   Updated: 2020/11/25 16:40:32 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool			print_specifier(t_data *data, t_format_tag *tag)
{
	if (data == NULL || tag == NULL)
		return (NULL);
	if (tag->specifier == 'd' || tag->specifier == 'i')
		return (print_number(data, tag));
	else if (tag->specifier == 'c')
		return (print_character(data, tag));
	else if (tag->specifier == 's')
		return (print_str(data, tag));
	else if (tag->specifier == 'p')
		return (print_pointer(data, tag));
	else if (tag->specifier == 'u')
		return (print_unsigned_number(data, tag));
	else if (tag->specifier == 'x')
		return (print_hexa_number(data, tag, true));
	else if (tag->specifier == 'X')
		return (print_hexa_number(data, tag, false));
	else if (tag->specifier == '%')
		return (print_general_character(data, tag, '%'));
	return (true);
}

t_format_tag	*get_tags(char *start, t_data *data)
{
	t_format_tag	*tags;
	char			*end;
	char			*duptag;
	char			*duptag_start;

	if (start == NULL || data == 0 ||
	!(end = ft_strchrset(++start, TAG_SPECIFIER_SET)))
		return (NULL);
	if (!(duptag = ft_strndup(start, end - start + 1)))
		return (NULL);
	duptag_start = duptag;
	tags = init_tags();
	if (!(duptag = parse_option_2(duptag, tags, data))
	|| !(duptag = parse_specifier(duptag, tags)))
	{
		free(tags);
		tags = NULL;
	}
	free(duptag_start);
	data->sentense += (end - start) + 2;
	return (tags);
}

int				print_sentence(t_data *data, int len)
{
	int written_len;

	if (!data || len < 0)
		return (0);
	if ((written_len = write(1, data->sentense, len)) < 0)
		return (0);
	data->total_len += written_len;
	data->sentense += written_len;
	return (1);
}

bool			ft_printlen(t_data *data)
{
	char			*target;
	t_format_tag	*tag;

	if (data == NULL || data->sentense == NULL)
		return (false);
	while ((target = ft_strchr(data->sentense, '%')) != NULL)
	{
		if (!print_sentence(data, target - data->sentense)
		|| !(tag = get_tags(target, data)))
			return (NULL);
		print_specifier(data, tag);
		free(tag);
	}
	print_sentence(data, ft_strlen(data->sentense));
	return (true);
}

int				ft_printf(const char *str, ...)
{
	t_data data;

	if (*str == 0)
		return (0);
	va_start(data.ap, str);
	data.sentense = str;
	data.total_len = 0;
	if (!ft_printlen(&data))
		data.total_len = 0;
	va_end(data.ap);
	return (data.total_len);
}
