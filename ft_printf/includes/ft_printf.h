/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 22:25:48 by hyunyoo           #+#    #+#             */
/*   Updated: 2020/11/03 10:38:52 by hyunyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TAG_SPECIFIER_SET "cspdiuxXnfge%"
# define TAG_FLAG_SET "-+ #0"
# define DECIMAL_SET "0123456789"
# include "../libft/libft.h"
# include <wchar.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct	s_data
{
	va_list		ap; //가변인자
	const char	*sentense; //printf format(사용할 문자열)
	int			total_len; // 리턴하는 문자열 길이
}				t_data;

typedef struct	s_format_tag
{
	char	specifier; //서식자
	int		width; //플래그
	int		precision; //정밀자
	int		length; 
	bool	left_align; //좌측정렬 여부
	bool	sign; //음수처리
	bool	sign_space; //부호자리 공백
	bool	sharp;
	bool	fill_zero; //0채우기
}				t_format_tag;

t_format_tag	*init_tags(void);
int				apply_left_align(char **number_str, int *len,
t_format_tag *tag);
int				apply_sign(char **str, int *len, t_format_tag *tag, bool minus);
bool			apply_precision(char **number_str, int *len, t_format_tag *tag);
char			*parse_flags(char *duptag, t_format_tag *tag);
char			*parse_width(char *duptag, t_format_tag *tag, t_data *data);
char			*parse_precision(char *duptag, t_format_tag *tag, t_data *data);
char			*parse_option_2(char *duptag, t_format_tag *tag, t_data *data);
char			*parse_specifier(char *duptag, t_format_tag *tag);
char			*print_flags_char(t_data *data, t_format_tag *tag);
int				print_general_character(t_data *data, t_format_tag
*tag, char c);
int				print_character(t_data *data, t_format_tag *tag);
int				write_hexa_number(char **number_str,
t_format_tag *tag, t_data *data);
int				print_hexa_number(t_data *data,
t_format_tag *tag, bool islowercase);
int				move_sign(char *number_str,
t_format_tag *tag, bool negative);
bool			ft_specifier_others(char **number_str,
int *len, t_format_tag *tag);
int				write_number(char **number_str,
t_format_tag *tag, t_data *data);
int				print_number(t_data *data, t_format_tag *tag);
bool			apply_0x(char **str, int *len);
bool			apply_precision_pointer(char **pointer_str,
int *len, t_format_tag *tag);
int				apply_left_align_pointer(char **p_str,
int *len, t_format_tag *tag);
int				write_pointer(char **pointer_str,
t_format_tag *tag, t_data *data);
int				print_pointer(t_data *data, t_format_tag *tag);
bool			apply_precision_str(char **str,
t_data *data, t_format_tag *tag);
char			*print_flags_str(char *str, t_data *data, t_format_tag *tag);
int				print_general_str(t_data *data, t_format_tag *tag, char *str);
int				print_str(t_data *data, t_format_tag *tag);
int				write_unsigned_number(char **str,
t_format_tag *tag, t_data *data);
int				print_unsigned_number(t_data *data, t_format_tag *tag);
bool			print_specifier(t_data *data, t_format_tag *tag);
t_format_tag	*get_tags(char *start, t_data *data);
int				print_sentence(t_data *data, int len);
bool			ft_printlen(t_data *data);
int				ft_printf(const char *str, ...);

#endif
