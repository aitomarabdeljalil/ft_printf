/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:15:19 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/27 21:29:47 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_firstcase(char c, va_list args)
{
	char	r;
	char	*s;
	int		i;

	i = 0;
	if (c == '%')
	{
		write(1, &c, 1);
		i = 1;
	}
	if (c == 'c')
	{
		r = (char) va_arg(args, int);
		write(1, &r, 1);
		i = 1;
	}
	if (c == 'u')
		i = ft_putnbr_base((int) va_arg(args, int), "0123456789");
	if (c == 's')
	{
		s = (char *) va_arg(args, const char *);
		i = ft_putstr(s);
	}
	return (i);
}

int	ft_secendcase(char c, va_list args)
{
	int		countw;

	countw = 0;
	if (c == 'x' || c == 'X')
		countw = ft_puthexa((int) va_arg(args, int), c);
	if (c == 'p')
		countw = ft_putpointer(va_arg(args, unsigned long long));
	if (c == 'd' || c == 'i')
		countw = ft_putnbr(va_arg(args, int));
	return (countw);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	bool	isspechar;

	va_start(args, str);
	i = 0;
	while (*str)
	{
		isspechar = false;
		if (*str == '%')
		{
			isspechar = true;
			str++;
			if (*str == '%' || *str == 'c' || *str == 'u' || *str == 's')
				i += ft_firstcase(*str, args);
			if (*str == 'x' || *str == 'X' || *str == 'd'
				|| *str == 'p' || *str == 'i')
				i += ft_secendcase(*str, args);
		}
		if (!isspechar)
			i += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (i);
}
