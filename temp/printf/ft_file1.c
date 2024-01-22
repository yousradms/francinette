/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:30:03 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/26 20:58:31 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check(int x, int *count)
{
	*count += x;
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	count;
	int	x;
	int	i;

	x = 0;
	count = 0;
	i = 0;
	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (str[i])
		check(ft_putchar(str[i++]), &count);
	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		check(ft_putstr("-2147483648"), &count);
	else if (nb < 0)
	{
		nb = -nb;
		check (ft_putchar('-'), &count);
		check(ft_putnbr(nb), &count);
	}
	else if (nb >= 10)
	{
		check(ft_putnbr(nb / 10), &count);
		check(ft_putnbr(nb % 10), &count);
	}
	else if (nb < 10)
		check(ft_putchar(nb + 48), &count);
	return (count);
}
