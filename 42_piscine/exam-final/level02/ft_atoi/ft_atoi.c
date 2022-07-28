void is_space(char c)
{
	if((c >= 9 && c <= 13) || c == 32)
		return 1;
	return 0;
}

void is_number(char c)
{
	if ((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}

void is_op(char c)
{
	if (c == '+' || c == '-')
		return 1;
	return 0;
}
int		ft_atoi(const char *str)
{
	int i = 0;
	int result = 0;
	int sign = 1;
	int cnt = 0;
	while(is_space(str[i]))
			i++;
	while(is_op(str[i]))
	{
		cnt++
		if(cnt > 1)
			return 0;
		if(str[i] == '-')
			sign = -1;
	}
	while(is_number(str[i]))
	{
		result = str[i] * 10 + (str[i] -'0');
	}
	return (result * sign);
}
