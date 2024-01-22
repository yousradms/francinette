/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:33:16 by yboutsli          #+#    #+#             */
/*   Updated: 2023/11/29 13:25:26 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printforma(va_list args, const char format)
{
	int	x;

	x = 0;
	if (format == '%')
		x = ft_putchar(format);
	else if (format == 'c')
		x = ft_putchar(va_arg(args, unsigned int));
	else if (format == 's')
		x = ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		x = ft_putnbr(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		x = ft_putnbrhexa(va_arg(args, unsigned int), format);
	else if (format == 'p')
		x = ft_putpointer(va_arg(args, unsigned long));
	else if (format == 'u')
		x = ft_putunsigned(va_arg(args, unsigned int));
	else
		x = ft_putchar(format);
	return (x);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	if (!format)
		return (0);
	if (write(1, 0, 0) < 0)
		return (-1);
	va_start(args, format);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && !format[i + 1])
			return (count);
		if (format[i] == '%' && format[i + 1])
			count += ft_printforma(args, format[i++ + 1]);
		else
			count += ft_putchar(format[i]);
	}
	va_end(args);
	return (count);
}
