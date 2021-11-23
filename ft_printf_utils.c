/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:05:24 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/23 11:29:08 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (s)
	{
		while (*s != '\0')
		{
			write(1, s, 1);
			s++;
		}
	}
}

void	ft_putnbr(int n)
{
	if (n <= -10)
	{
		ft_putnbr(n / 10);
		ft_putchar(-(n % -10) + '0');
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putchar(-n + '0');
	}	
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else if (n >= 0)
	{
		ft_putchar(n + '0');
	}
}