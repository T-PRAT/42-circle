/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:46:50 by tprat             #+#    #+#             */
/*   Updated: 2020/02/25 19:42:41 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"
int main()
{
	char *s = "Hello";
	int d = 42;
	//char *a = ft_strdup(d);
	//printf("%c%s%u%x%X|%p", 'a', "Hello", 32, 32, -32, s);
	printf("%d", printf("|%.4d/", 42));
	printf("|\n");
	printf("%d", ft_printf("|%.4d/", 42));
	//printf("|%.4d/", 42);
	printf("|\n");
	while (d);
}
