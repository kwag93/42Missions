/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:14:25 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/17 17:25:18 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			char_is_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int			count_word(char *str, char *charset)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (!(char_is_sep(str[i], charset)) && char_is_sep(str[i + 1], charset))
			word++;
		i++;
	}
	return (word);
}

void		fill_word(char *string, char *str, char *charset)
{
	int i;

	i = 0;
	while (!(char_is_sep(str[i], charset)))
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
}

void		fill_string(char **string, char *str, char *charset)
{
	int start;
	int next;
	int word;

	word = 0;
	start = 0;
	while (str[start])
	{
		if (char_is_sep(str[start], charset))
			start++;
		else
		{
			next = 0;
			while (!(char_is_sep(str[start + next], charset)))
				next++;
			string[word] = (char *)malloc(sizeof(char) * (next + 1));
			fill_word(string[word], str + start, charset);
			start += next;
			word++;
		}
	}
}

char		**ft_split(char *str, char *charset)
{
	char	**string;
	int		words;

	words = count_word(str, charset);
	if (!(string = (char **)malloc(sizeof(char*) * (words + 1))))
		return (0);
	string[words] = 0;
	fill_string(string, str, charset);
	return (string);
}
