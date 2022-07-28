/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:59:41 by hyunyoo           #+#    #+#             */
/*   Updated: 2020/11/03 13:25:35 by hyunyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool			print_specifier(t_data *data, t_format_tag *tag)
{
	if (data == NULL || tag == NULL) // 에러처리
		return (NULL);
	if (tag->specifier == 'd' || tag->specifier == 'i') //d 와 i는 출력상의 차이가 없어서 그대로 number에 대입 scanf를 사용할때가 아니면 상관없음.
		return (print_number(data, tag));
	else if (tag->specifier == 'c')
		return (print_character(data, tag));
	else if (tag->specifier == 's')
		return (print_str(data, tag));
	else if (tag->specifier == 'p')
		return (print_pointer(data, tag));
	else if (tag->specifier == 'u')
		return (print_unsigned_number(data, tag));
	else if (tag->specifier == 'x')
		return (print_hexa_number(data, tag, true));
	else if (tag->specifier == 'X')
		return (print_hexa_number(data, tag, false));
	else if (tag->specifier == '%')
		return (print_general_character(data, tag, '%'));
	return (true);
}

t_format_tag	*get_tags(char *start, t_data *data)
{
	t_format_tag	*tag; //새로 생성할 구조체 변수
	char			*end; //서식 지정자 위치
	char			*duptag; //%~서식지정자까지를 sentense에서 자른 것(깊은 복사)
	char			*duptag_start; //duptag가 뒤로 이동하기 때문에 free를 해주기 위해서 맨 처음 duptag 위치를 저장해놓는다.

	if (start == NULL || data == 0 //에러처리
 	|| !(end = ft_strchrset(++start, TAG_SPECIFIER_SET))) //++start 하는 이유 : TAG_SPECIFIER_SET에 %가 있는데 현재 start가 %(시작위치)이므로 start 다음부터 나오는 TAG_SPECIFIER_SET를 찾아야한다.
		return (NULL);
	if (!(duptag = ft_strndup(start, end - start + 1))) // %부터 서식 지정자까지 dup를 통해 복사해준다.
		return (NULL);
	duptag_start = duptag; // free를 위해 pointer값을 미리 저장해 놓는다.
	tag = init_tags(); // tag를 사용하기 전에 모든 값을 초기화 해준다. 이때 presicion은 -1로 초기화 하는것에 유념한다.
	if (!(duptag = parse_option_2(duptag, tag, data))
	|| !(duptag = parse_specifier(duptag, tag)))
	{
		free(tag);
		tag = NULL;
	}
	free(duptag_start);
	data->sentense += (end - start) + 2;
	return (tag);
}

int				print_sentence(t_data *data, int len)
{
	int written_len; //출력한 평문 길이

	if (!data || len < 0) //오류 처리
		return (0);
	if ((written_len = write(1, data->sentense, len)) < 0) //write_len이 0보다 작으면 write()에서 출력에서 오류가 난 것이므로 에러처리
		return (0);
	data->total_len += written_len; //평문을 출력한 만큼 len에 더해줌
	data->sentense += written_len; //포인터 이동
	return (1);
}

bool			ft_printlen(t_data *data)
{
	char			*target; //현재 커서의 위치
	t_format_tag	*tag; //플래그,서식지정자 저장 구조체

	if (data == NULL || data->sentense == NULL) //오류 처리
		return (false);
	while ((target = ft_strchr(data->sentense, '%')) != NULL) //%가 나오는 구간을 찾는다.
	{
		if (!print_sentence(data, target - data->sentense) //%가 나오면 이전 커서위치~taget위치까지는 평문이므로 출력해야한다.
		|| !(tag = get_tags(target, data))) //플래그,서식지정자를 tag에 넣는다.
			return (NULL);
		print_specifier(data, tag); //서식지정자에 맞춰서 출력과정 진행
	}
	print_sentence(data, ft_strlen(data->sentense)); //마지막 %이후에 평문이 나올 수도 있고, 애초에 평문만 출력할 경우 위 과정이 진행되지 않기 때문에 sentense 끝까지 출력을 한번 해줘야 한다.
	return (true);						//"%d hi" 일때 hi를 출력.	"ㅁㄴㅇㄹ" 이면 바로 print로
}

int				ft_printf(const char *str, ...)
{
	t_data data; //구조체 사용 이유 : 다른 함수에서도 계속 사용되는 데이터들이어서 하나로 묶음.
				//norm맞추는데 이득.
				//변수의 양을 줄이고 통일성이 있도록 한다.
	if (*str == 0) //문자열 자체가 안들어오면 출력할 내용도 없다. ""
		return (0);
	va_start(data.ap, str); //가변인자 사용을 위해 va_list 초기화
	data.sentense = str; // 앞의 문자열에 str을 입력
	data.total_len = 0; // total_len 을 0으로 초기화 해준다
	if (!ft_printlen(&data))
		data.total_len = 0; //출력 실패 시 중간까지 성공한 내용도 없애야하므로 길이를 0으로 수정
	va_end(data.ap);
	return (data.total_len);
}
