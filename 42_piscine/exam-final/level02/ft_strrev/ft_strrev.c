#include <stdio.h>

char	*ft_strrev(char *str)
{
	int i = 0;
	int len = 0;
	char temp;

	while(str[len])
		len++;
	while(i < len / 2)
	{
		temp = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = temp;
		i++;
	}
	return str;
}

int main()
{
	char str[] = "12345678";
	printf("%s", ft_strrev(str));
	return 0;
}
