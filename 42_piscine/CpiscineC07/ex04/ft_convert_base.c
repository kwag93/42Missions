/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 18:16:16 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/17 11:02:21 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_len(char *str)
{
	int count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

int		is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int		error_check(char *str)
{
	int i;
	int j;
	int len;

	len = ft_len(str);
	i = 0;
	if (len == 1 || len == 0)
		return (1);
	while (str[i] != '\0')
	{
		j = i + 1;
		if (is_space(str[i]))
			return (1);
		if ((str[i] == '+') || (str[i] == '-'))
			return (1);
		while (str[j] != '\0')
		{
			if (str[i] == str[j++])
				return (1);
		}
		i++;
	}
	return (0);
}

int		base_check(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int result;
	int sign;
	int radix;
	int id;

	radix = ft_len(base);
	result = 0;
	sign = 1;
	if (error_check(base))
		return (0);
	while (is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ((id = base_check(base, *str)) != -1)
	{
		result *= radix;
		result += id;
		str++;
	}
	return (result * sign);
}
