/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:15:19 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/18 17:49:55 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	char	*res;
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
			if (*str == '%')
				res = ft_strdup("%");
			else if (*str == 'c')
				res = ft_strdup(va_arg(args, char));
		}
		if (isspechar)
		{
			ft_putstr(res);
			i += ft_strlen(res) - 1;
		}
		else
			ft_putchar(*str);
		i++;
	}
	va_end(args);
	return (i);
}
// #include <stdio.h>
// int main()
// {
// 	char c = 'h';
// 	int i = ft_printf("hello %% %c", c);
// 	printf("%d", i);
// 	return (0);
// }