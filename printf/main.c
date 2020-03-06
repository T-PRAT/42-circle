/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:46:50 by tprat             #+#    #+#             */
/*   Updated: 2020/03/06 01:00:01 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"
int main()
{
	char *s = "Hello";
	int d = 42;

	int i = printf("|%c%c|\n", 'c', 0);
	int j = ft_printf("|%c%c|\n", 'c', 0);
	printf("%d/%d\n", i, j);
	//while (d);
}
