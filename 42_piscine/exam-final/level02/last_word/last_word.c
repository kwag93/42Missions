#include <unistd.h>

int is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return 1;
	return 0;
}
int main(int ac, char **av)
{
	char *arr= av[1];
	int i = 0;

	int len = 0;
	if(ac == 2)
	{
		while(*arr)
			arr++;
		arr--;
		while(is_space(*arr))
			arr--;
		while(*arr &&!(is_space(*arr)))
			arr--;
		arr++;
		while(*arr && !(is_space(*arr)))
			write(1, arr++, 1);
	}
	write(1, "\n", 1);
	return 0;
}
