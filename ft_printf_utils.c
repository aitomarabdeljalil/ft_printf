/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:05:24 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/27 21:47:03 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nbr_u;	
	int				len_base;
	char			char_arr[32];
	int				i;
	int				ret;

	len_base = ft_strlen(base);
	i = 0;
	nbr_u = nbr;
	while (nbr_u != 0 || i == 0)
	{
		char_arr[i++] = base[nbr_u % len_base];
		nbr_u /= len_base;
	}
	ret = i;
	while (i > 0)
		ft_putchar(char_arr[--i]);
	return (ret);
}

int	ft_puthexa(unsigned int nbr, char c)
{
	char	*base;
	char	hexa_nbr[8];
	int		i;
	int		ret;

	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (nbr == 0)
		hexa_nbr[i++] = '0';
	while (nbr != 0)
	{
		hexa_nbr[i++] = base[nbr % 16];
		nbr /= 16;
	}
	ret = i;
	while (i > 0)
		ft_putchar(hexa_nbr[--i]);
	return (ret);
}

int	ft_putpointer(unsigned long long nbr)
{
	char	hexa_nbr[18];
	int		i;
	int		ret;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	if (nbr == 0)
		return (ft_putstr("0x0"));
	while (nbr != 0)
	{
		hexa_nbr[i++] = base[nbr % 16];
		nbr /= 16;
	}
	hexa_nbr[i++] = 'x';
	hexa_nbr[i++] = '0';
	ret = i;
	while (i > 0)
		ft_putchar(hexa_nbr[--i]);
	return (ret);
}
