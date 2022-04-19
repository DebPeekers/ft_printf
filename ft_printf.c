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
	int		i;
	int		len;

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
		else
		{
			ft_putchar((char)format[i], &len);
			i++;
		}
	}
	va_endl(arg_p);
	return (len);
}
