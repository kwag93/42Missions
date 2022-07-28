/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:58:31 by hyunyoo           #+#    #+#             */
/*   Updated: 2020/11/03 12:45:31 by hyunyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_flags_char(t_data *data, t_format_tag *tag)
{
	char *flag_result; // 문자를 제외한 플레그에 들어갈 값만 저장해주는것. 00000c 라면 00000부분만 가져온다.
	char c;

	if (!tag)
		return (NULL);
	if ((size_t)tag->width <= 1) // width가 1보다 작거나 같으면 문자를 그대로 출력
		return (ft_strdup(""));
	if (!(flag_result = (char *)malloc(sizeof(char) * tag->width))) // 플래그를 넣을 flag_result값을 width만큼 잡아준다
		return (NULL);
	if (!tag->left_align && tag->fill_zero)
	{
		c = '0';
	}
	else
		c = ' ';
	ft_memset(flag_result, c, tag->width - 1);
	flag_result[tag->width - 1] = '\0';
	data->total_len += tag->width - 1; // c를 제외한 플래그 문자만 길이에 더해준다.
	return (flag_result);
}

int		print_general_character(t_data *data, t_format_tag *tag, char c)
{
	char	*flags_str; //플래그(좌측정렬, 너비, 공백)을 모두 처리한 문자열(출력할 문자 제외)
	int		result_char; // 문자
	int		result_str; // 문자열

	if (!data || !tag)
		return (0);
	if (!(flags_str = print_flags_char(data, tag)))
		return (0);
	if (tag->left_align) //좌측정렬일 경우 문자를 먼저 출력하고 플레그에 따른 0 또는 공백을 출력해준다
	{
		result_char = ft_putchar_fd(c, 1);
		result_str = ft_putstr_fd(flags_str, 1);
		data->total_len += 1;
	}
	else
	{
		result_str = ft_putstr_fd(flags_str, 1);
		result_char = ft_putchar_fd(c, 1);
		data->total_len += 1;
	}
	free(flags_str);
	if (result_char != 1 || result_str < 0) //문자 or 공백 중 하나라도 잘못 된 경우 실패처리
		return (0);
	return (1);
}

int		print_character(t_data *data, t_format_tag *tag)
{
	char letter;

	if (!data || !tag)
		return (0);
	letter = (char)va_arg(data->ap, int); //va_arg는 char로 받을 수 없으므로 우선 int로 받고 형변환으로 char형으로 변환
	return (print_general_character(data, tag, letter));
}
