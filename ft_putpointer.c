/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:37:56 by laltarri          #+#    #+#             */
/*   Updated: 2023/10/02 19:49:53 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printpointer(uintptr_t n, int base, int *len)
{
	uintptr_t	i;
	int			e;
	int         writted;

	writted = 0;
	i = 1;
	while (n / i >= (uintptr_t)base)
		i *= base;
	while (i > 0)
	{
		e = write(1, &"0123456789abcdef"[(n / i) % base], 1);
		if(e == -1)
		{
			*len = -1;
			return ;
		}
		writted += e;
		i /= base;
	}
	*len += writted;
}


void	ft_putpointer(void *n, int *len)
{
	if(write(1, "0x", 2) == -1)
	{
		*len = -1;
		return ;
	}
	*len += 2;
	ft_printpointer((uintptr_t)n, 16, len);
}
