/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:44:29 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/27 22:14:46 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>

int	ft_putnbr(int n);
int	ft_strlen(char *str);
int	ft_putchar(char c);
int	ft_putnbr_base(int nbr, char *base);
int	ft_puthexa(unsigned int nbr, char c);
int	ft_putpointer(unsigned long long nbr);
int	ft_putstr(char *s);
int	ft_printf(const char *str, ...);

#endif