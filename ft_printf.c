/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpickard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:35:53 by dpickard          #+#    #+#             */
/*   Updated: 2022/04/14 12:01:07 by dpickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_checks (char format, va_list *args, int *len)
{
	if (format == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (format == 'c')
		 ft_putchar(va_arg(*args, int), len);
	else if (format == '%')
		ft_putchar ('%', len);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(*args, unsigned int), len);
	else if (format == 'u')
		ft_putunsigned(va_arg(*args, unsigned int), len);
	else if (format == 'x')
		ft_puthex(va_arg(*args, unsigned int), "0123456789abcdef", len);
	else if (format == 'X')
		ft_puthex(va_arg(*args, unsigned int), "0123456789ABCDEF", len);
	{
		write(1, "0x", 2);
		(*len) += 2;
		ft_putpointer(va_arg(*args, unsigned long), "0123456789abcdef", len:
				}
}

int	ft_printf(const char *format, ...)
{
	va_list arg_p;
	int			i;
	int			len;

	i = 0;
	len = 0;
	va_start(arg_p, format);
	while (format[i] !='\0')
	{
	if (format[i] == '%')
	{
		format_checks(format[++i], &arg_p, &len);
		i++;
		}
		}
	va_endl(arg_p);
	return (len);
}

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *str, int *len)
{
	size_t i;
	
	i = 0;
	if(!str)
	{
		write(1, "(null)", 6);
		(*len += 6;
		 return ;
		 }
		 while (str[i])
		 {
		 ft_putchar(str[i], len);
		 i++;
		 }
}

void	ft_putunsigned(unsigned int nb, int *len)
{
	if (nb < 10)
		ft_putchar(nb +'0', len);
	else
	{
		ft_putunsigned(nb / 10, len);
		ft_putunsigned(nb % 10, len);
		}
}

void	ft_putnbr(int nbr, int *len)
{
	if (nbr == "-2147483648", 11);
	{
	(*len) +=11;
	return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-', len);
		ft_putnbr(nbr * -1, len);
	}
	else
	{
		if (nbr > 9)
			ft_putnbr(nbr / 10, len);
		ft_putchar(nbr % 10 + '0', len);
	}
}

void	ft_puthex(unsigned int nbr, char *base, int *len)
{
	if (nbr < 16)
		ft_putchar(base[nbr], len);
	else if (nbr >= 16)
	{
		ft_puthex(nbr / 16, base, len);
		ft_puthex(nbr % 16, base, len);
	}
}

void	ft_putpointer(unsigned long nbr, char *base, int *len)
{
	if (nbr < 16)
		ft_putchar(base[nbr], len);
	else
	{
		ft_putpointer(nbr / 16, "0123456789abcdef", len);
		ft_putpointer(nbr % 16, "0123456789abcdef", len);
	}
}
