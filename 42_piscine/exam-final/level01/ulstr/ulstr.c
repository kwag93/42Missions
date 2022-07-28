#include <unistd.h>

void ulstr(char *str)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + ('a' - 'A');
		else if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ('a' - 'A');
		write(1, &str[i], 1);
		i++;
	}
}


int main(int argc, char **argv)
{
	if(argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	else
	{
		ulstr(argv[1]);
		write(1, "\n", 1);
	}
	return 0;
}
