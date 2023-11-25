/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:04:21 by bkas              #+#    #+#             */
/*   Updated: 2023/11/25 14:06:37 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		write(1, str++, 1);
		(*len)++;
	}
}

void	print_nbr(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) = (*len) + 11;
		return ;
	}
	if (nbr < 0)
	{
		nbr = nbr * -1;
		write(1, "-", 1);
		(*len)++;
	}
	if (nbr >= 10)
		print_nbr(nbr / 10, len);
	write(1, &"0123456789"[nbr % 10], 1);
	(*len)++;
}

void	print_hex(unsigned int nbr, int *len)
{
	if (nbr < 0)
	{
		nbr = nbr * -1;
		write(1, "-", 1);
		(*len)++;
	}
	if (nbr >= 16)
		print_hex(nbr / 16, len);
	write(1, &"0123456789abcdef"[nbr % 16], 1);
	(*len)++;
}

int ft_printf(const char *format, ...)
{
	int length = 0;
	char *x;
	int i;
	unsigned int a;
	va_list arg;
	va_start(arg, format);
	while (*format)
	{
		if ((*format == '%') && (*(format) + 1))
		{
			format++;
			if (*format == 's')
			{
				x = va_arg(arg, char *);
				put_str(x, &length);
			}
			else if (*format == 'd')
			{
				i = va_arg(arg, int);
				print_nbr(i, &length);
			}
			else if (*format == 'x')
			{
				a = va_arg(arg, unsigned int);
				print_hex(a, &length);
			}
		}
		else
		{
			write(1, format, 1);
			length++;
		}
		format++;
	}
	va_end(arg);
	return (length);
}
#include <stdio.h>
int main()
{
	int	ft_len = 0;
	int len = 0;
	
	char	*str;

	str = 0;
	ft_len = ft_printf("%s\n",str);
	len = printf("%s\n",str);
	printf("ft_len = %d || len = %d\n",ft_len,len);
	ft_len = ft_printf("asdfasdfasdf%sasdfasdf\n",str);
	len = printf("asdfasdfasdf%sasdfasdf\n",str);
	printf("ft_len = %d || len = %d\n",ft_len,len);
	ft_len = ft_printf("%d\n",999);
	len = printf("%d\n",999);
	printf("ft_len = %d || len = %d\n",ft_len,len);
	ft_len = ft_printf("%x\n",20);
	len = printf("%x\n",20);
	printf("ft_len = %d || len = %d\n",ft_len,len);
	ft_len = ft_printf("%x\n",5);
	len = printf("%x\n",5);
	//printf("ft_len = %d || len = %d\n",ft_len,len);
	//ft_len = ft_printf("%a\n",16);
	//len = printf("%a\n",16);
	printf("ft_len = %d || len = %d\n",ft_len,len);
	ft_len = ft_printf("%d\n",-2147483648);
	len = printf("%d\n",-2147483648);
	printf("ft_len = %d || len = %d\n",ft_len,len);
	ft_len = ft_printf("%d\n",2147483647);
	len = printf("%d\n",2147483647);
	printf("ft_len = %d || len = %d\n",ft_len,len);
	ft_len = ft_printf("%%");
	len = printf("%%");
	printf("ft_len = %d\n",ft_len);
	printf("len = %d\n",len);
}