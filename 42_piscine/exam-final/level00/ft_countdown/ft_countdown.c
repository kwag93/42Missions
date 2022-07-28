#include <unistd.h>

int main(void)
{
	write(1, "9876543210\n", 12);
	return 0;
}

