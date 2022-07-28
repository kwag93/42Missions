#include "includes/ft_printf.h"

int main()
{
	int x = -1;
	ft_printf("%3.0p\n", &x);
	printf("%3.0p\n", &x);
}
