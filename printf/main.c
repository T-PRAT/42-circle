/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:46:50 by tprat             #+#    #+#             */
/*   Updated: 2020/02/26 16:29:41 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"
int main()
{
	char *s = "Hello";
	int d = 42;

	int i = printf("|%4d%i", 12, 23);
	printf("|\n");
	int j = ft_printf("|%4d%i", 12, 23);
	printf("|\n");
	printf("%d/%d\n", i, j);
	while (d);
}
