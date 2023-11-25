/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:31:56 by bkas              #+#    #+#             */
/*   Updated: 2023/11/22 14:53:36 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void print_numbers(int count, ...)
{
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        int num = va_arg(args, int);
        printf("%d ", num);
    }
    va_end(args);
}

int main()
{
    print_numbers(5, 1, 2, 3, 4, 5);
    return 0;
}
