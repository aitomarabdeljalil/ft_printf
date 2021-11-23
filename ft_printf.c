/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:15:19 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/23 14:33:29 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	ft_firstcase(char c, va_list args)
{
	char	r;
	char	*s;
	int		i;

	i = 0;
	if (c == '%')
		write(1, &c, 1);
	if (c == 'c')
	{
		r = (char) va_arg(args, int);
		write(1, &r, 1);
	}
	if (c == 'i')
		ft_putnbr((int) va_arg(args, int));
	if (c == 's')
	{
		s = (char *) va_arg(args, const char *);
		ft_putstr(s);
	}
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
				ft_firstcase(*str, args);
		}
		if (!isspechar)
			ft_putchar(*str);
		// else
		// 	i += ft_strlen(res) - 1;
		i++;
		str++;
	}
	va_end(args);
	return (i);
}
#include <stdio.h>
int main()
{
	char c = 'h';
	ft_printf("hello %c %% %i\n%s\n", c, 122, "aoa");
	return (0);
}