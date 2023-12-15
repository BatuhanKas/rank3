/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:44:14 by bkas              #+#    #+#             */
/*   Updated: 2023/12/15 15:38:39 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void print_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		write(1, str, 1);
		str++;
		(*len)++;
	}
}

void print_int(int nbr, int *len)
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
		print_int(nbr / 10, len);
	write(1, &"0123456789"[nbr % 10], 1);
	(*len)++;
}

void print_hex(unsigned int nbr, int *len)
{
	if (nbr >= 16)
		print_hex(nbr / 16, len);
	write(1, &"0123456789abcdef"[nbr % 16], 1);
	(*len)++;
}

int ft_printf(const char *format, ...)
{
	char *s = 0;
	int d = 0;
	unsigned int x = 0;
	int len = 0;
	va_list arg;
	va_start(arg, format);
	
	while(*format)
	{
		if ((*format == '%') && (*(format + 1)))
		{
			format++;
			if (*format == 's')
			{
				s = va_arg(arg, char *);
				print_str(s, &len);
			}
			else if (*format == 'd')
			{
				d = va_arg(arg, int);
				print_int(d, &len);
			}
			else if (*format == 'x')
			{
				x = va_arg(arg, unsigned int);
				print_hex(x, &len);
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				len++;
			}
		}
		else
		{
			write(1, format, 1);
			len++;
		}
		format++;
	}
	va_end(arg);
	return len;
}

//#include <stdio.h>
//int main()
//{
//	char *s = 0;
//	int len = 0;
//	int ft_len = 0;
//	ft_len = ft_printf("%s\n", s);
//	len = printf("%s\n", s);
//	printf("ft_len = %d || len = %d", ft_len, len);
//	printf("\n");
//	ft_len = ft_printf("%d\n", 9999);
//	len = printf("%d\n", 9999);
//	printf("ft_len = %d || len = %d", ft_len, len);
//	printf("\n");
//	ft_len = ft_printf("asdfasdf%s\n", s);
//	len = printf("asdfasdf%s\n", s);
//	printf("ft_len = %d || len = %d", ft_len, len);
//	printf("\n");
//	ft_len = ft_printf("%x\n", 1337);
//	len = printf("%x\n", 1337);
//	printf("ft_len = %x || len = %x", ft_len, len);
//	printf("\n");
//	ft_len = ft_printf("asdfasdf%%x\n");
//	len = printf("asdfasdf%%x\n");
//	printf("ft_len = %d || len = %d", ft_len, len);
//	printf("\n");
//	ft_len = ft_printf("%%\n", s);
//	len = printf("%%\n", s);
//	printf("ft_len = %d || len = %d", ft_len, len);
//	printf("\n");
//}

//#include <stdio.h>
//int main()
//{
//	int	ft_len = 0;
//	int len = 0;
	
//	char	*str;

//	str = 0;
//	ft_len = ft_printf("%s\n",str);
//	len = printf("%s\n",str);
//	printf("ft_len = %d || len = %d\n",ft_len,len);
//	ft_len = ft_printf("asdfasdfasdf%sasdfasdf\n",str);
//	len = printf("asdfasdfasdf%sasdfasdf\n",str);
//	printf("ft_len = %d || len = %d\n",ft_len,len);
//	ft_len = ft_printf("%d\n",999);
//	len = printf("%d\n",999);
//	printf("ft_len = %d || len = %d\n",ft_len,len);
//	ft_len = ft_printf("%x\n",20);
//	len = printf("%x\n",20);
//	printf("ft_len = %d || len = %d\n",ft_len,len);
//	ft_len = ft_printf("%x\n",5);
//	len = printf("%x\n",5);
//	//printf("ft_len = %d || len = %d\n",ft_len,len);
//	//ft_len = ft_printf("%a\n",16);
//	//len = printf("%a\n",16);
//	printf("ft_len = %d || len = %d\n",ft_len,len);
//	ft_len = ft_printf("%d\n",-2147483648);
//	len = printf("%d\n",-2147483648);
//	printf("ft_len = %d || len = %d\n",ft_len,len);
//	ft_len = ft_printf("%d\n",2147483647);
//	len = printf("%d\n",2147483647);
//	printf("ft_len = %d || len = %d\n",ft_len,len);
//	ft_len = ft_printf("%%");
//	len = printf("%%");
//	printf("ft_len = %d\n",ft_len);
//	printf("len = %d\n",len);
//}