/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:43:37 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/27 21:24:44 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putdig(int d)
{
	char	dig;

	dig = d + '0';
	write(1, &dig, 1);
}

int	ft_putnbr(int n)
{
	int	count;

	if (n <= -10)
	{
		count = ft_putnbr(n / 10);
		ft_putdig(-(n % -10));
		return (count + 1);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putdig(-n);
		return (2);
	}	
	else if (n >= 10)
	{
		count = ft_putnbr(n / 10);
		ft_putdig(n % 10);
		return (count +1);
	}
	else
	{
		ft_putdig(n);
		return (1);
	}
}
