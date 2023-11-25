/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:10:25 by bkas              #+#    #+#             */
/*   Updated: 2023/11/25 14:05:31 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	topla(int miktar, ...)
{
	int i = 0;
	int topla = 0;
	int deger = 0;

	va_list arg;
	va_start(arg, miktar);
	while (i <= miktar)
	{
		deger = va_arg(arg, int);
		printf("toplanacak deger : %d\n", deger);
		topla = deger + topla;
		printf("toplandıktan sonraki deger : %d\n", topla);
		i++;
	}
	va_end(arg);
}

int main()
{
	//topla(3, 5, 4, 9, 1);
	printf("%z", 98765678909876);
}
