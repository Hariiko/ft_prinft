/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:51:33 by laltarri          #+#    #+#             */
/*   Updated: 2023/09/28 21:20:50 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void comprovate_char(va_list a,  char c, int *i)
{
	if (c == 'c')
		pt_putchar(va_arg(a,int), i);
	else if (c == 's')
		pt_putstr(va_arg(a, char*), i);
    else if (c == 'p')
		printf("p");
	else if (c == 'd' || c == 'i')
		pt_putnbase(va_arg(a, long long), 10, &i);
    else if (c == 'u')
		printf("u");
	else if (c == 'x' || c == 'X')
        printf("xX");
	else if(c == '%')
		printf("%%");
}

int ft_printf(char const *argc, ...)
{
	int i;
	int value;
	va_list a;
	
	va_start(a,argc);
	i = 0;
	value = 0;
	while (argc[i] != '\0')
	{
		if (argc[i] == '%')
		{
			i++;
			if (!ft_strchr("cspdiuxX%",argc[i]) || !argc[i])
				return (-1);				
			comprovate_char(a, argc[i], &value);
		}
		else
			pt_putchar(argc[i], &value);
		i++;	
	}
	return (value);
}

int main ()
{
	int a = ft_printf("%i\n", 1);
	printf("%d\n", a);
	//printf("%");
	return 0;
}
