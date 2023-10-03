/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:51:33 by laltarri          #+#    #+#             */
/*   Updated: 2023/10/02 19:49:38 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static void	comprovate_char(va_list a, char c, int *i)
{
	if (c == 'c')
		pt_putchar(va_arg(a, int), i);
	else if (c == 's')
		ft_putstr(va_arg(a, char *), i);
	else if (c == 'p')
		ft_putpointer(va_arg(a, void *), i);
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
			if(value == -1)
				return -1;
		}
		else
			pt_putchar(argc[i], &value);
		if(value == -1)
			return -1;
		i++;
	}
	va_end(a);
	return (value);
}

/*int main ()
  {
	int e = 34;
	printf("%d\n", ft_printf("\001\002\007\v\010\f\r\n"));
	printf("\n");
	printf("%d\n", printf("\001\002\007\v\010\f\r\n"));
	return 0;
}*/
