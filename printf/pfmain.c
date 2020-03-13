/* ************************************************************************** */
/*                                                                                        LE - /                  */
/*                                                                                                  /                   */
/*   pfmain.c                                                                 .::    .:/ .      .::   */
/*                                                                         +:+:+   +:    +:  +:+:+    */
/*   By: lelegros <lelegros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                                         #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 11:40:07 by lelegros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 15:30:58 by lelegros    ###    #+. /#+    ###.fr     */
/*                                                                                       /                        */
/*                                                                                      /                         */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"
#define BLUE dprintf(1, "\e[36m");
#define EOC dprintf(1, "\e[39m");
#define KO dprintf(1, "Valeur de retour : \e[31m[KO]\e[39m\n");
#define OK dprintf(1, "\e[32m[OK]\e[39m\n");
#define N dprintf(1, "\n");
#define TOTAL 206

int main()
{
	int i;
	int j;
	int o;

	i = 0;
	j = 0;
	o = 0;
	i = dprintf(1, "[Salut]");
	N
	j = ft_printf("[Salut]");
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	N
	BLUE
	dprintf(1, "//////////////////////////////////////////////\n");
	dprintf(1, "/                     %%c                     /\n");
	dprintf(1, "//////////////////////////////////////////////\n");
	EOC
	i = dprintf(1, "[%c]", 'a');
	N
	j = ft_printf("[%c]", 'a');
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%15c]", 'a');
	N
	j = ft_printf("[%15c]", 'a');
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1c]", 'a');
	N
	j = ft_printf("[%1c]", 'a');
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-20c]", 'a');
	N
	j = ft_printf("[%-20c]", 'a');
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%c]", 0);
	N
	j = ft_printf("[%c]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "//////////////////////////////////////////////\n");
	dprintf(1, "/                     %%s                     /\n");
	dprintf(1, "//////////////////////////////////////////////\n");
	EOC
	i = dprintf(1, "[%s]", "Salut");
	N
	j = ft_printf("[%s]", "Salut");
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%15s]", "Salut");
	N
	j = ft_printf("[%15s]", "Salut");
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%20.3s]", "Salut");
	N
	j = ft_printf("[%20.3s]", "Salut");
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%20.10s]", "Salut");
	N
	j = ft_printf("[%20.10s]", "Salut");
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%20.10s]", NULL);
	N
	j = ft_printf("[%20.10s]", NULL);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.4s]", NULL);
	N
	j = ft_printf("[%.4s]", NULL);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "//////////////////////////////////////////////\n");
	dprintf(1, "/                     %%d                     /\n");
	dprintf(1, "//////////////////////////////////////////////\n");
	EOC
	i = dprintf(1, "[%d]", 1);
	N
	j = ft_printf("[%d]", 1);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%d]", -2);
	N
	j = ft_printf("[%d]", -2);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%d]", 0);
	N
	j = ft_printf("[%d]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%d]", -214748364);
	N
	j = ft_printf("[%d]", -214748364);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%d]", 2147483647);
	N
	j = ft_printf("[%d]", 2147483647);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10d]", 5);
	N
	j = ft_printf("[%10d]", 5);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10d]", -6);
	N
	j = ft_printf("[%10d]", -6);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%0d]", 7);
	N
	j = ft_printf("[%0d]", 7);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%0d]", 0);
	N
	j = ft_printf("[%0d]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%0d]", -8);
	N
	j = ft_printf("[%0d]", -8);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1d]", 10);
	N
	j = ft_printf("[%1d]", 10);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1d]", -11);
	N
	j = ft_printf("[%1d]", -11);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1d]", 0);
	N
	j = ft_printf("[%1d]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.0d]", 12);
	N
	j = ft_printf("[%.0d]", 12);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.0d]", -13);
	N
	j = ft_printf("[%.0d]", -13);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.0d]", 0);
	N
	j = ft_printf("[%.0d]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.5d]", 14);
	N
	j = ft_printf("[%.5d]", 14);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.5d]", -15);
	N
	j = ft_printf("[%.5d]", -15);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.5d]", 0);
	N
	j = ft_printf("[%.5d]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.2d]", 16);
	N
	j = ft_printf("[%.2d]", 16);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.2d]", -17);
	N
	j = ft_printf("[%.2d]", -17);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.1d]", -18);
	N
	j = ft_printf("[%.1d]", -18);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.3d]", -19);
	N
	j = ft_printf("[%.3d]", -19);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.2d]", -20);
	N
	j = ft_printf("[%.2d]", -20);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.1d]", -21);
	N
	j = ft_printf("[%.1d]", -21);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.3d]", -22);
	N
	j = ft_printf("[%.3d]", -22);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1.3d]", 23);
	N
	j = ft_printf("[%1.3d]", 23);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1.3d]", -24);
	N
	j = ft_printf("[%1.3d]", -24);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1.3d]", 0);
	N
	j = ft_printf("[%1.3d]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10.3d]", 24);
	N
	j = ft_printf("[%10.3d]", 24);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10.3d]", -24);
	N
	j = ft_printf("[%10.3d]", -24);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10.15d]", 25);
	N
	j = ft_printf("[%10.15d]", 25);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10.15d]", -26);
	N
	j = ft_printf("[%10.15d]", -26);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10.15d]", 0);
	N
	j = ft_printf("[%10.15d]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-d]", 27);
	N
	j = ft_printf("[%-d]", 27);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-d]", -28);
	N
	j = ft_printf("[%-d]", -28);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5d]", 29);
	N
	j = ft_printf("[%-5d]", 29);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5d]", -30);
	N
	j = ft_printf("[%-5d]", -30);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5d]", 0);
	N
	j = ft_printf("[%-5d]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5.3d]", 31);
	N
	j = ft_printf("[%-5.3d]", 31);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5.3d]", -32);
	N
	j = ft_printf("[%-5.3d]", -32);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5.8d]", 33);
	N
	j = ft_printf("[%-5.8d]", 33);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5.8d]", -34);
	N
	j = ft_printf("[%-5.8d]", -34);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5.8d]", 0);
	N
	j = ft_printf("[%-5.8d]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%5.0d]", 0);
	N
	j = ft_printf("[%5.0d]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%0.0d]", 0);
	N
	j = ft_printf("[%0.0d]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1.0d]", 0);
	N
	j = ft_printf("[%1.0d]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%05d]", 37);
	N
	j = ft_printf("[%05d]", 37);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%05d]", -38);
	N
	j = ft_printf("[%05d]", -38);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00d]", 39);
	N
	j = ft_printf("[%00d]", 39);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00d]", -40);
	N
	j = ft_printf("[%00d]", -40);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00d]", 0);
	N
	j = ft_printf("[%00d]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00.5d]", 41);
	N
	j = ft_printf("[%00.5d]", 41);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00.5d]", -42);
	N
	j = ft_printf("[%00.5d]", -42);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00.0d]", 43);
	N
	j = ft_printf("[%00.0d]", 43);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%010.5d]", 44);
	N
	j = ft_printf("[%010.5d]", 44);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%010.5d]", -45);
	N
	j = ft_printf("[%010.5d]", -45);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%010.0d]", 46);
	N
	j = ft_printf("[%010.0d]", 46);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "//////////////////////////////////////////////\n");
	dprintf(1, "/                     %%x                     /\n");
	dprintf(1, "//////////////////////////////////////////////\n");
	EOC
	i = dprintf(1, "[%x]", 1);
	N
	j = ft_printf("[%x]", 1);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%x]", -2);
	N
	j = ft_printf("[%x]", -2);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%x]", 0);
	N
	j = ft_printf("[%x]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%x]", -214748364);
	N
	j = ft_printf("[%x]", -214748364);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%x]", 2147483647);
	N
	j = ft_printf("[%x]", 2147483647);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10x]", 5);
	N
	j = ft_printf("[%10x]", 5);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10x]", -6);
	N
	j = ft_printf("[%10x]", -6);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%0x]", 7);
	N
	j = ft_printf("[%0x]", 7);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%0x]", 0);
	N
	j = ft_printf("[%0x]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%0x]", -8);
	N
	j = ft_printf("[%0x]", -8);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1x]", 10);
	N
	j = ft_printf("[%1x]", 10);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1x]", -11);
	N
	j = ft_printf("[%1x]", -11);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1x]", 0);
	N
	j = ft_printf("[%1x]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.0x]", 12);
	N
	j = ft_printf("[%.0x]", 12);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.0x]", -13);
	N
	j = ft_printf("[%.0x]", -13);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.0x]", 0);
	N
	j = ft_printf("[%.0x]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.5x]", 14);
	N
	j = ft_printf("[%.5x]", 14);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.5x]", -15);
	N
	j = ft_printf("[%.5x]", -15);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.5x]", 0);
	N
	j = ft_printf("[%.5x]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.2x]", 16);
	N
	j = ft_printf("[%.2x]", 16);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.2x]", -17);
	N
	j = ft_printf("[%.2x]", -17);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.1x]", -18);
	N
	j = ft_printf("[%.1x]", -18);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.3x]", -19);
	N
	j = ft_printf("[%.3x]", -19);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.2x]", -20);
	N
	j = ft_printf("[%.2x]", -20);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.1x]", -21);
	N
	j = ft_printf("[%.1x]", -21);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.3x]", -22);
	N
	j = ft_printf("[%.3x]", -22);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1.3x]", 23);
	N
	j = ft_printf("[%1.3x]", 23);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1.3x]", -24);
	N
	j = ft_printf("[%1.3x]", -24);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1.3x]", 0);
	N
	j = ft_printf("[%1.3x]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10.3x]", 24);
	N
	j = ft_printf("[%10.3x]", 24);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10.3x]", -24);
	N
	j = ft_printf("[%10.3x]", -24);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10.15x]", 25);
	N
	j = ft_printf("[%10.15x]", 25);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10.15x]", -26);
	N
	j = ft_printf("[%10.15x]", -26);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10.15x]", 0);
	N
	j = ft_printf("[%10.15x]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-x]", 27);
	N
	j = ft_printf("[%-x]", 27);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-x]", -28);
	N
	j = ft_printf("[%-x]", -28);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5x]", 29);
	N
	j = ft_printf("[%-5x]", 29);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5x]", -30);
	N
	j = ft_printf("[%-5x]", -30);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5x]", 0);
	N
	j = ft_printf("[%-5x]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5.3x]", 31);
	N
	j = ft_printf("[%-5.3x]", 31);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5.3x]", -32);
	N
	j = ft_printf("[%-5.3x]", -32);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5.8x]", 33);
	N
	j = ft_printf("[%-5.8x]", 33);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5.8x]", -34);
	N
	j = ft_printf("[%-5.8x]", -34);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5.8x]", 0);
	N
	j = ft_printf("[%-5.8x]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%5.0x]", 0);
	N
	j = ft_printf("[%5.0x]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%0.0x]", 0);
	N
	j = ft_printf("[%0.0x]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1.0x]", 0);
	N
	j = ft_printf("[%1.0x]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%05x]", 37);
	N
	j = ft_printf("[%05x]", 37);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%05x]", -38);
	N
	j = ft_printf("[%05x]", -38);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00x]", 39);
	N
	j = ft_printf("[%00x]", 39);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00x]", -40);
	N
	j = ft_printf("[%00x]", -40);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00x]", 0);
	N
	j = ft_printf("[%00x]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00.5x]", 41);
	N
	j = ft_printf("[%00.5x]", 41);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00.5x]", -42);
	N
	j = ft_printf("[%00.5x]", -42);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00.0x]", 43);
	N
	j = ft_printf("[%00.0x]", 43);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%010.5x]", 44);
	N
	j = ft_printf("[%010.5x]", 44);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%010.5x]", -45);
	N
	j = ft_printf("[%010.5x]", -45);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%010.0x]", 46);
	N
	j = ft_printf("[%010.0x]", 46);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "//////////////////////////////////////////////\n");
	dprintf(1, "/                     %%X                     /\n");
	dprintf(1, "//////////////////////////////////////////////\n");
	EOC
	i = dprintf(1, "[%X]", 1);
	N
	j = ft_printf("[%X]", 1);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%X]", -2);
	N
	j = ft_printf("[%X]", -2);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%X]", 0);
	N
	j = ft_printf("[%X]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%X]", -214748364);
	N
	j = ft_printf("[%X]", -214748364);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%X]", 2147483647);
	N
	j = ft_printf("[%X]", 2147483647);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10X]", 5);
	N
	j = ft_printf("[%10X]", 5);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10X]", -6);
	N
	j = ft_printf("[%10X]", -6);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%0X]", 7);
	N
	j = ft_printf("[%0X]", 7);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%0X]", 0);
	N
	j = ft_printf("[%0X]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%0X]", -8);
	N
	j = ft_printf("[%0X]", -8);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1X]", 10);
	N
	j = ft_printf("[%1X]", 10);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1X]", -11);
	N
	j = ft_printf("[%1X]", -11);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1X]", 0);
	N
	j = ft_printf("[%1X]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.0X]", 12);
	N
	j = ft_printf("[%.0X]", 12);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.0X]", -13);
	N
	j = ft_printf("[%.0X]", -13);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.0X]", 0);
	N
	j = ft_printf("[%.0X]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.5X]", 14);
	N
	j = ft_printf("[%.5X]", 14);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.5X]", -15);
	N
	j = ft_printf("[%.5X]", -15);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.5X]", 0);
	N
	j = ft_printf("[%.5X]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.2X]", 16);
	N
	j = ft_printf("[%.2X]", 16);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.2X]", -17);
	N
	j = ft_printf("[%.2X]", -17);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.1X]", -18);
	N
	j = ft_printf("[%.1X]", -18);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.3X]", -19);
	N
	j = ft_printf("[%.3X]", -19);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.2X]", -20);
	N
	j = ft_printf("[%.2X]", -20);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.1X]", -21);
	N
	j = ft_printf("[%.1X]", -21);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.3X]", -22);
	N
	j = ft_printf("[%.3X]", -22);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1.3X]", 23);
	N
	j = ft_printf("[%1.3X]", 23);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1.3X]", -24);
	N
	j = ft_printf("[%1.3X]", -24);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1.3X]", 0);
	N
	j = ft_printf("[%1.3X]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10.3X]", 24);
	N
	j = ft_printf("[%10.3X]", 24);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10.3X]", -24);
	N
	j = ft_printf("[%10.3X]", -24);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10.15X]", 25);
	N
	j = ft_printf("[%10.15X]", 25);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10.15X]", -26);
	N
	j = ft_printf("[%10.15X]", -26);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%10.15X]", 0);
	N
	j = ft_printf("[%10.15X]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-X]", 27);
	N
	j = ft_printf("[%-X]", 27);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-X]", -28);
	N
	j = ft_printf("[%-X]", -28);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5X]", 29);
	N
	j = ft_printf("[%-5X]", 29);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5X]", -30);
	N
	j = ft_printf("[%-5X]", -30);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5X]", 0);
	N
	j = ft_printf("[%-5X]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5.3X]", 31);
	N
	j = ft_printf("[%-5.3X]", 31);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5.3X]", -32);
	N
	j = ft_printf("[%-5.3X]", -32);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5.8X]", 33);
	N
	j = ft_printf("[%-5.8X]", 33);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5.8X]", -34);
	N
	j = ft_printf("[%-5.8X]", -34);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-5.8X]", 0);
	N
	j = ft_printf("[%-5.8X]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%5.0X]", 0);
	N
	j = ft_printf("[%5.0X]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%0.0X]", 0);
	N
	j = ft_printf("[%0.0X]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%1.0X]", 0);
	N
	j = ft_printf("[%1.0X]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%05X]", 37);
	N
	j = ft_printf("[%05X]", 37);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%05X]", -38);
	N
	j = ft_printf("[%05X]", -38);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00X]", 39);
	N
	j = ft_printf("[%00X]", 39);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00X]", -40);
	N
	j = ft_printf("[%00X]", -40);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00X]", 0);
	N
	j = ft_printf("[%00X]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00.5X]", 41);
	N
	j = ft_printf("[%00.5X]", 41);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00.5X]", -42);
	N
	j = ft_printf("[%00.5X]", -42);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%00.0X]", 43);
	N
	j = ft_printf("[%00.0X]", 43);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%010.5X]", 44);
	N
	j = ft_printf("[%010.5X]", 44);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%010.5X]", -45);
	N
	j = ft_printf("[%010.5X]", -45);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%010.0X]", 46);
	N
	j = ft_printf("[%010.0X]", 46);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "//////////////////////////////////////////////\n");
	dprintf(1, "/                     %%p                     /\n");
	dprintf(1, "//////////////////////////////////////////////\n");
	EOC
	i = dprintf(1, "[%p]", &i);
	N
	j = ft_printf("[%p]", &i);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-25p]", &i);
	N
	j = ft_printf("[%-25p]", &i);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%25p]", &i);
	N
	j = ft_printf("[%25p]", &i);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-p]", &i);
	N
	j = ft_printf("[%-p]", &i);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "///////////////////////////////////////////////\n");
	dprintf(1, "/                     %%                       /\n");
	dprintf(1, "///////////////////////////////////////////////\n");
	EOC
	i = dprintf(1, "[%%]");
	N
	j = ft_printf("[%%]");
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%25%]");
	N
	j = ft_printf("[%25%]");
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%-25%]");
	N
	j = ft_printf("[%-25%]");
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.4%]");
	N
	j = ft_printf("[%.4%]");
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "//////////////////////////////////////////////\n");
	dprintf(1, "/                     *                      /\n");
	dprintf(1, "//////////////////////////////////////////////\n");
	EOC
	i = dprintf(1, "[%*%]", 45);
	N
	j = ft_printf("[%*%]", 45);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%*d]", 25, 10);
	N
	j = ft_printf("[%*d]", 25, 10);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%.*d]", 25, 10);
	N
	j = ft_printf("[%.*d]", 25, 10);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%*.*d]", 25, 10, 45);
	N
	j = ft_printf("[%*.*d]", 25, 10, 45);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "//////////////////////////////////////////////\n");
	dprintf(1, "/                 Cas Chelous                /\n");
	dprintf(1, "//////////////////////////////////////////////\n");
	EOC
	i = dprintf(1, "[%5.x]", 0);
	N
	j = ft_printf("[%5.x]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%5.0x]", 0);
	N
	j = ft_printf("[%5.0x]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%5.d]", 0);
	N
	j = ft_printf("[%5.d]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%5.0d]", 0);
	N
	j = ft_printf("[%5.0d]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%4.s]", "salut");
	N
	j = ft_printf("[%4.s]", "salut");
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%4.0s]", "salut");
	N
	j = ft_printf("[%4.0s]", "salut");
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%4.p]", &i);
	N
	j = ft_printf("[%4.p]", &i);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	EOC
	i = dprintf(1, "[%c]", 0);
	N
	j = ft_printf("[%c]", 0);
	N
	if (i != j)
		KO
	else
	{
		OK
		o++;
	}
	BLUE
	dprintf(1, "----------------------------------\n");
	if (o == TOTAL)
		dprintf(1, "\nResultat : \e[32m%d/206\e[39m\n", o);
	else
		dprintf(1, "\nResultat : \e[31m%d/206\e[39m\n", o);
	dprintf(1, "Attention, les \e[32m[OK]\e[39m ne vérifient que la valeur de retour !\n");
	return (0);
}
