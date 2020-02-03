#include <stdio.h>
#include "include/ft_printf.h"
int main()
{
	char *s = "Hello";
	int d = 42;
	printf("%-0\n", s);
	ft_printf("%-0s%.*d", s);
}
