/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:05:24 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/24 19:22:51 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (*s != '\0')
		{
			write(1, s, 1);
			s++;
			i++;
		}
		return (i);
	}
	return (0);
}

int	ft_putnbr(int n)
{
	int	c;
	
	if (n <= -10)
	{
		c = ft_putnbr(n / 10);
		ft_putchar(-(n % -10) + '0');
		return (1 + c);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putchar(-n + '0');
		return (2);
	}	
	else if (n >= 10)
	{
		c = ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
		return (1 + c);
	}
	else
	{
		ft_putchar(n + '0');
		return (1);
	}
}