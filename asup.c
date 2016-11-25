/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 06:42:45 by tdumouli          #+#    #+#             */
/*   Updated: 2016/11/25 07:56:27 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

int debut(const char *c, va_list va)
{
	if (*(c + 1) == '%')
		write(1, "%", 1);
	if (*(c + 1) == 'c')
		ft_putchar(va_arg(va, int));
	if (*(c + 1) == 's')
		ft_putstr(va_arg(va, char *));
	if (*(c + 1) == 'd')
		ft_putnbr(va_arg(va, int));
	return (2);
}

int ft_printf(const char * format, ...)
{
	size_t len;
	size_t start;
	va_list va;

	va_start(va, format);
	len = 0;
	start = 0;
	while (*(len + start + format) != '\0')
	{
		while (*(len + start + format) != '%' && *(len + start + format) != 0)
			++len;
		write(1, format + start, len);
		if (*(format + start + len) == '%')
			len += debut(format + start + len, va);
		start += len;
		len = 0;
	}
	va_end(va);
	return (0);
}



int main(void)
{
ft_printf("gdf1%%2dg%%gg%c%d%s\n", 'a', 'a', "jhgfd");
}
