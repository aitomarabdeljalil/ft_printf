/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:15:19 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/24 19:24:41 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.c"
#include <stdarg.h>
#include <stdbool.h>

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
	if (c == 'i')
		i = ft_putnbr((int) va_arg(args, int));
	if (c == 's')
	{
		s = (char *) va_arg(args, const char *);
		i = ft_putstr(s);
	}
	return (i);
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
			if (*str == '%' || *str == 'c' || *str == 'i' || *str == 's')
				i += ft_firstcase(*str, args);
		}
		if (!isspechar)
		{
			ft_putchar(*str);
			i++;
		}
		str++;
	}
	va_end(args);
	return (i);
}
#include <stdio.h>
int main()
{
	char c = 'h';
	int i;
	i = ft_printf("hello %c %% %i\n%s\n", c, 122, "aoa");
	printf("%d",i);
	return (0);
}