/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:59:31 by bkwag             #+#    #+#             */
/*   Updated: 2020/11/03 13:59:31 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*parse_flags(char *duptag, t_format_tag *tag)
{
	char		*addr;
	char		flag;

	if (duptag == NULL || tag == NULL)
		return (NULL);
	while ((addr = ft_strchr(TAG_FLAG_SET, *duptag)))
	{
		flag = TAG_FLAG_SET[addr - TAG_FLAG_SET];
		if (flag == '-')
			tag->left_align = true;
		else if (flag == '+')
			tag->sign = true;
		else if (flag == ' ')
			tag->sign_space = true;
		else if (flag == '#')
			tag->sharp = true;
		else if (flag == '0')
			tag->fill_zero = true;
		else
			return (NULL);
		duptag++;
	}
	return (duptag);
}

char		*parse_width(char *duptag, t_format_tag *tag, t_data *data)
{
	char	*addr;
	int		n;

	if (!duptag || !tag || !data)
		return (NULL);
	if (*duptag == '*')
	{
		n = va_arg(data->ap, int);
		if (n < 0)
		{
			tag->left_align = true;
			n *= -1;
		}
		tag->width = n;
		return (++duptag);
	}
	if (!ft_isdigit(*duptag) || *duptag == '0')
		return (duptag);
	while ((addr = ft_strchr(DECIMAL_SET, *duptag)))
	{
		tag->width = tag->width * 10 + (DECIMAL_SET[addr - DECIMAL_SET] - '0');
		duptag++;
	}
	return (duptag);
}

char		*parse_precision(char *duptag, t_format_tag *tag, t_data *data)
{
	char	*addr;
	int		n;

	if (!duptag || !tag || !data)
		return (NULL);
	if (*duptag != '.')
		return (duptag);
	duptag++;
	if (*duptag == '*')
	{
		n = va_arg(data->ap, int);
		if (n < 0)
			n = -1;
		tag->precision = n;
		return (++duptag);
	}
	tag->precision = 0;
	while ((addr = ft_strchrset(duptag, DECIMAL_SET)))
	{
		tag->precision = tag->precision * 10 +
		(DECIMAL_SET[addr - DECIMAL_SET] - '0');
		duptag++;
	}
	return (duptag);
}

char		*parse_option_2(char *duptag, t_format_tag *tag, t_data *data)
{
	if (duptag == NULL || tag == NULL)
		return (NULL);
	if (!(duptag = parse_flags(duptag, tag)) ||
		!(duptag = parse_width(duptag, tag, data)) ||
		!(duptag = parse_precision(duptag, tag, data)))
		return (NULL);
	return (duptag);
}

char		*parse_specifier(char *duptag, t_format_tag *tag)
{
	char	*addr;

	if (duptag == NULL || tag == NULL ||
	!(addr = ft_strchr(TAG_SPECIFIER_SET, *duptag)))
		return (NULL);
	tag->specifier = TAG_SPECIFIER_SET[addr - TAG_SPECIFIER_SET];
	duptag++;
	return (duptag);
}
