#include <stdio.h>
#include "include/ft_printf.h"
int main()
{
	char *s = "Hello";
	int d = 42;
	//printf("%d", ft_atoi("050"));
	//printf("%c%s%u%x%X|%p", 'a', "Hello", 32, 32, -32, s);
	ft_printf("%.-12s", "Hello");

}
