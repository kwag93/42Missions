#include <unistd.h>

void	repeat(char *str)
{
	int i = 0;
	int j = 0;
	int k;

	while (str[i])
	{
		j = 0;
		k = 1;
		if(str[i] >= 'A' && str[i] <= 'Z')
		 	k = str[i] - 'A' + 1;
		else if(str[i] >= 'a' && str[i] <= 'z')
			k = str[i] - 'a' + 1;
		while(j < k)
		{
			write(1, &str[i], 1);
			j++;	
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		repeat(argv[1]);
		write(1, "\n", 1);
	}

}
