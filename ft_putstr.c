/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:49:31 by laltarri          #+#    #+#             */
/*   Updated: 2023/10/01 19:17:40 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			*len = -1;
		else
			*len += 6;
		return ;
	}
	while (*str)
	{
		pt_putchar(*str, len);
		if(*len == -1)
			return ;
		str++;
	}
}
