/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:51:33 by laltarri          #+#    #+#             */
/*   Updated: 2023/09/27 20:40:08 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void comprovate_char(va_list a,  char const *argc, int i)
{
	if (argc[i] == 'c')
		printf("c");
	else if (argc[i] == 's')
		putstr(va_arg(a, char*), &i);
    else if (argc[i] == 'p')	
		printf("p");
	else if (argc[i] == 'd' || argc[i] == 'i')
        printf("di");
    else if (argc[i] == 'u')
		printf("u");
	else if (argc[i] == 'x' || argc[i] == 'X')
        printf("xX");
	else if(argc[i] == '%')
		printf("%%");
}

int ft_printf(char const *argc, ...)
{
	int i;
	va_list a;
	
	va_start(a,argc);
	i = 0;	
	while (argc[i] != '\0')
	{
		if (argc[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX%",argc[i]))
				comprovate_char(a, argc, i);
		}
		else
			write(1, &argc[i], 1);
		i++;	
	}
	return (i);
}

int main ()
{
	int a = ft_printf("%s\n", "aa");
	printf("%d\n", a);
	return 0;
}
