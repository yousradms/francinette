/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:14:40 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/27 21:42:24 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	casehexa(unsigned int nb, int *count, char casef)
{
	int	i;

	if (casef == 'X')
		i = 55;
	else
		i = 87;
	if (nb < 10)
		*count += ft_putchar(nb + 48);
	else
		*count += ft_putchar(nb + i);
}

int	ft_putnbrhexa(unsigned long nb, char casef)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		check(ft_putnbrhexa(nb / 16, casef), &count);
		check(ft_putnbrhexa(nb % 16, casef), &count);
	}
	else
		casehexa(nb, &count, casef);
	return (count);
}

int	ft_putpointer(unsigned long adress)
{
	int	count;
	int	x;

	x = 0;
	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbrhexa(adress, 'x');
	return (count);
}

int	ft_putunsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
	{
		check(ft_putunsigned(nb / 10), &count);
		check(ft_putunsigned(nb % 10), &count);
	}
	else if (nb < 10)
		check(ft_putchar(nb + 48), &count);
	return (count);
}
