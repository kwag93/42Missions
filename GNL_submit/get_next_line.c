/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:20:45 by bkwag             #+#    #+#             */
/*   Updated: 2020/12/27 18:02:16 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		split_save(char **save, char **line, char *enter_addr)
{
	char	*new;
	size_t	len;

	if (!(*line = malloc(enter_addr - *save + 1)))
		return (-1);
	ft_strlcpy(*line, *save, enter_addr - *save + 1);
	len = ft_strlen(enter_addr + 1);
	if (len == 0)
	{
		free(*save);
		*save = 0;
		return (1);
	}
	if (!(new = malloc(len + 1)))
		return (-1);
	ft_strlcpy(new, enter_addr + 1, len + 1);
	free(*save);
	*save = new;
	return (1);
}

static int		ft_strjoin(char **save, char buf[BUFFER_SIZE + 1], int read_size)
{
	char	*new;
	size_t	size;
	size_t	all_size;

	if (read_size <= 0)
		return (-1);
	if (*save == 0)
	{
		if (!(*save = malloc(read_size + 1)))
			return (-1);
		return (ft_strlcpy(*save, buf, read_size + 1));
	}
	size = ft_strlen(*save) + read_size + 1;
	if (!(new = malloc(size)))
		return (-1);
	all_size = ft_strlcpy(new, *save, size);
	ft_strlcpy(new + all_size, buf, size);
	free(*save);
	*save = new;
	return (1);
}

static int		return_all(char **save, char **line, int read_size)
{
	if (read_size < 0)
		return (-1);
	if (*save != 0)
	{
		*line = *save;
		*save = 0;
		return (0);
	}
	if ((*line = malloc(1)) == 0)
		return (-1);
	(*line)[0] = 0;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*enter_addr;
	int			read_size;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((enter_addr = ft_strchr(save[fd], '\n')) == 0)
	{
		if ((read_size = read(fd, buf, BUFFER_SIZE)) <= 0)
			return (return_all(&save[fd], line, read_size));
		buf[read_size] = 0;
		if (ft_strjoin(&save[fd], buf, read_size) == -1)
			return (-1);
	}
	return (split_save(&save[fd], line, enter_addr));
}

