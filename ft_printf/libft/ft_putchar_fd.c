/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:15:09 by hyunyoo           #+#    #+#             */
/*   Updated: 2020/10/22 15:12:51 by hyunyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putchar_fd(char c, int fd)
{
	int result;

	if (fd < 0)
		return (-1);
	result = write(fd, &c, 1);
	return (result);
}
