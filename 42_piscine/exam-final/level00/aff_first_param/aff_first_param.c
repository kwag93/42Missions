#include <unistd.h>

void putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		write(1, "\n", 1);
	else
	{
		putstr(argv[1]);
		write(1, "\n", 1);
	}
}
