/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:59:27 by bkwag             #+#    #+#             */
/*   Updated: 2020/11/25 16:33:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		move_sign(char *number_str, t_format_tag *tag, bool negative)
{
	char	*addr;
	char	temp;

	if (!number_str || !*number_str || !tag)
		return (false);
	if (!tag->fill_zero || (!negative && !tag->sign && !tag->sign_space))
		return (true);
	if (!(addr = ft_strchrset(number_str, tag->sign_space ? "+- " : "+-")))
		return (false);
	temp = *addr;
	*addr = *number_str;
	*number_str = temp;
	return (true);
}

bool	ft_specifier_others(char **number_str, int *len, t_format_tag *tag)
{
	char *dupstr;

	if (ft_strchr("diuxX", tag->specifier))
	{
		if (tag->precision > (int)*len)
		{
			if (!(dupstr = malloc(tag->precision + 1)))
				return (false);
			ft_memset(dupstr, '0', tag->precision - *len);
			ft_strlcpy(dupstr + tag->precision - *len, *number_str, *len + 1);
			free(*number_str);
			*number_str = dupstr;
			*len = tag->precision;
		}
		else if (tag->precision == 0 && **number_str == '0')
		{
			if (!(dupstr = ft_strdup("")))
				return (false);
			free(*number_str);
			*number_str = dupstr;
			*len = tag->precision;
		}
		return (true);
	}
	return (true);
}

int		write_number(char **number_str, t_format_tag *tag, t_data *data)
{
	bool	negative;
	int		len;
	char	*temp;

	negative = false;
	if (!number_str || !*number_str || !tag || !data)
		return (0);
	if (**number_str == '-')
	{
		negative = true;
		if (!(temp = ft_strdup((*number_str) + 1)))
			return (0);
		free(*number_str);
		*number_str = temp;
	}
	len = ft_strlen(*number_str);
	if (!apply_precision(number_str, &len, tag) ||
		!apply_sign(number_str, &len, tag, negative) ||
		!apply_left_align(number_str, &len, tag) ||
		(tag->precision < 0 && !move_sign(*number_str, tag, negative)))
		return (0);
	data->total_len += len;
	return (ft_putstr_fd(*number_str, 1));
}

int		print_number(t_data *data, t_format_tag *tag)
{
	int			result;
	char		*str;
	long long	value;

	if (!data || !tag)
		return (0);
	value = (int)va_arg(data->ap, int);
	if (!(str = ft_lltoa(value)))
		return (0);
	result = write_number(&str, tag, data);
	free(str);
	return (result);
}
