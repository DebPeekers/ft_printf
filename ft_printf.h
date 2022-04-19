/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpickard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:07:46 by dpickard          #+#    #+#             */
/*   Updated: 2022/04/19 10:30:07 by dpickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

void	ft_putunsigned(unsigned int nb, int *len);
void	ft_putnbr(int nbr, int *len);
void	ft_puthex(unsigned int nbr, char *base, int *len);
void	ft_putpointer(unsigned long nbr, char *base, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
int		ft_printf(const char *format, ...);

#endif
