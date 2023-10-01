/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:37:56 by laltarri          #+#    #+#             */
/*   Updated: 2023/10/01 19:17:23 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpointer(uintptr_t n, int base, int *len)
{
	uintptr_t	i;

	i = 0;
	while (n / i >= (uintptr_t)base)
		i *= base;
	while (i > 0)
	{
		*len += write(1, &"0123456789abcdef"[(n / i) % base], 1);
		i /= base;
	}
}
