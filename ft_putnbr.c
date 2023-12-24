/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchouai <hchouai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:05:47 by hchouai           #+#    #+#             */
/*   Updated: 2023/11/30 17:36:11 by hchouai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnbr(int n, int *len)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-', len);
		nb *= -1;
	}
	if (nb >= 0 && nb < 10)
	{
		nb += 48;
		ft_putchar(nb, len);
	}
	else
	{
		ft_printnbr(nb / 10, len);
		ft_printnbr(nb % 10, len);
	}
}

void	ft_putnbr(int n, int *len)
{
	ft_printnbr(n, len);
}
