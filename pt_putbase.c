/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:06:52 by laltarri          #+#    #+#             */
/*   Updated: 2023/09/28 21:20:47 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pt_putnbase(long long n, int base, int *len)
{
    if (n < 0)
    {
        *len += write(1, "-", 1);
        n = -n;
    }
    if (n >= base)
        putnbase (n / base, base, len);
        *len += write(1, &"0123456789abcdef"[n % base, 1]);
}
