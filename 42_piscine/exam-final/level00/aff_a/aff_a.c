#include <unistd.h>

int check(char *str)
{
	while (*str)
	{
		if (*str++ == 'a')
			return (1);
	}
	return 0;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "a", 1);
	else
	{
		while(check(argv[1]))
			{
			write(1, "a", 1);
			break;
			}
	}
	write(1, "\n", 1);
}
