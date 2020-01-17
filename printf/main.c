#include <stdio.h>
#include "ft_printf.h"
int main()
{
	char *s = "Hello";
	printf("real%p\n", s);
	ft_printf("mine%s\n",s);
}
