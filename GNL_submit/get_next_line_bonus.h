/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:25:53 by bkwag             #+#    #+#             */
/*   Updated: 2020/12/27 18:04:56 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

int			get_next_line(int fd, char **line);
size_t		ft_strlcpy(char *str1, const char *str2, size_t str1size);
size_t		ft_strlen(const char *s);
char		*ft_strchr(char *str, int c);

#endif
