/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:51:33 by laltarri          #+#    #+#             */
/*   Updated: 2023/10/01 19:15:15 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static void	comprovate_char(va_list a, char c, int *i)
{
	void		*ptr;
	uintptr_t	e;

	if (c == 'c')
		pt_putchar(va_arg(a, int), i);
	else if (c == 's')
		ft_putstr(va_arg(a, char *), i);
	else if (c == 'p')
	{
		pt_putchar('0', i);
		pt_putchar('x', i);
		*ptr = va_arg(a, void *);
		e = (uintptr_t) ptr;
		ft_putpointer(e, 16, i);
	}
	else if (c == 'd' || c == 'i')
		pt_putbase(va_arg(a, int), 10, i, c);
	else if (c == 'u')
		pt_putbase(va_arg(a, unsigned int), 10, i, c);
	else if (c == 'x' || c == 'X')
		pt_putbase(va_arg(a, unsigned int), 16, i, c);
	else if (c == '%')
		pt_putchar(c, i);
}

int	ft_printf(char const *argc, ...)
{
	int		i;
	int		value;
	va_list	a;

	va_start(a, argc);
	i = 0;
	value = 0;
	while (argc[i] != '\0')
	{
		if (argc[i] == '%')
		{
			i++;
			if (!ft_strchr("cspdiuxX%", argc[i]) || !argc[i])
				return (-1);
			comprovate_char(a, argc[i], &value);
		}
		else
			pt_putchar(argc[i], &value);
		i++;
	}
	va_end(a);
	return (value);
}
/*
int main ()
{
	printf("%d\n", ft_printf(" %u ",1));
	printf("\n");
	printf("%d\n", printf(" %u ",1));
	return 0;
}*/
