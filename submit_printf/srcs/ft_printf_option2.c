/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_option2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:59:35 by bkwag             #+#    #+#             */
/*   Updated: 2020/11/03 13:59:35 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format_tag	*init_tags(void)
{
	t_format_tag *new_tag;

	if (!(new_tag = (t_format_tag *)malloc(sizeof(t_format_tag))))
		return (0);
	new_tag->specifier = 0;
	new_tag->width = 0;
	new_tag->precision = -1;
	new_tag->length = 0;
	new_tag->left_align = false;
	new_tag->sign = false;
	new_tag->sign_space = false;
	new_tag->sharp = false;
	new_tag->fill_zero = false;
	return (new_tag);
}

int				apply_left_align(char **number_str, int *len, t_format_tag *tag)
{
	char space_char;
	char *new_num;

	if (!number_str || !*number_str || !len || !tag)
		return (0);
	if (tag->width <= *len)
		return (1);
	if (!(new_num = malloc(tag->width + 1)))
		return (0);
	if (tag->left_align)
	{
		ft_strlcpy(new_num, *number_str, *len + 1);
		ft_memset(new_num + *len, ' ', tag->width - *len);
		new_num[tag->width] = '\0';
	}
	else
	{
		space_char = (tag->fill_zero && tag->precision < 0) ? '0' : ' ';
		ft_memset(new_num, space_char, tag->width - *len);
		ft_strlcpy(new_num + (tag->width - *len), *number_str, *len + 1);
	}
	free(*number_str);
	*number_str = new_num;
	*len = tag->width;
	return (1);
}

int				apply_sign(char **str, int *len, t_format_tag *tag, bool minus)
{
	char *new_num;

	if (!str || !*str || !tag)
		return (false);
	if (!minus && !tag->sign && !tag->sign_space)
		return (true);
	if (!(new_num = malloc(*len + 2)))
		return (false);
	if (minus)
	{
		*new_num = '-';
		ft_strlcpy(new_num + 1, *str, *len + 1);
	}
	else
	{
		*new_num = tag->sign ? '+' : ' ';
		ft_strlcpy((new_num + 1), *str, *len + 1);
	}
	free(*str);
	*str = new_num;
	*len += 1;
	return (true);
}

bool			apply_precision(char **number_str, int *len, t_format_tag *tag)
{
	if (!number_str || !*number_str || !tag)
		return (false);
	if (tag->precision < 0)
		return (true);
	return (ft_specifier_others(number_str, len, tag));
}
