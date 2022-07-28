/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:21:07 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/02 12:19:10 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			is_char_check(char c)
{
	if ((c >= 'A' && c <= 'Z'))
	{
		return (3);
	}
	else if (c >= '0' && c <= '9')
	{
		return (2);
	}
	else if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
		return (0);
}

char		*ft_strcapitalize(char *str)
{
	int i;

	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	while (str[i] != '\0')
	{
		if (is_char_check(str[i - 1]) > 0)
		{
			if (is_char_check(str[i]) == 3)
				str[i] += 32;
		}
		else
		{
			if (is_char_check(str[i]) == 1)
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
