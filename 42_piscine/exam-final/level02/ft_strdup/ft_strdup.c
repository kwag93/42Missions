#include <stdlib.h>

char *ft_strdup(char *src)
{
	char *temp;
	int i = 0;
	int len = 0;

	while(src[len])
		len++;
	if(!(temp = (char *)malloc(sizeof(char) * len + 1)))
		return 0;
	while(src[i])
	{
		temp[i] = src[i];
		i++;
		return 0;
	}
	temp[i] = '\0';
	return temp;
}
