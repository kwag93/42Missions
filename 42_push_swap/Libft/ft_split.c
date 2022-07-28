/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:37:20 by bkwag             #+#    #+#             */
/*   Updated: 2020/07/22 16:03:09 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_malloc_error(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
	return (NULL);
}

int			count_word(char *str, char c)
{
	int word;
	int i;

	i = 0;
	word = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] == c)
		{
			word++;
			while (str[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (str[i - 1] != c)
		word++;
	return (word);
}

int			numchar(char *str, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (str[i] != c && str[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char	**write_string(char **string, char *str, char c, int words)
{
	int word;
	int start;
	int i;

	word = 0;
	start = 0;
	while (str[start] && word < words)
	{
		i = 0;
		while (str[start] == c)
			start++;
		if (!(string[word] = (char *)malloc(sizeof(char) *
						(numchar(str, c, start) + 1))))
			return (ft_malloc_error(string));
		while (str[start] != c && str[start])
			string[word][i++] = str[start++];
		string[word][i] = '\0';
		word++;
	}
	string[word] = NULL;
	return (string);
}

char		**ft_split(char const *str, char c)
{
	char	**string;
	char	*new_str;
	int		words;

	if (!(str))
		return (NULL);
	new_str = (char *)str;
	words = count_word(new_str, c);
	if (!(string = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	return (write_string(string, new_str, c, words));
}
