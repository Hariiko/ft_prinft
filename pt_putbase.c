/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:06:52 by laltarri          #+#    #+#             */
/*   Updated: 2023/09/30 01:37:25 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pt_putbase(int n, int base, int *len, char c)
{
    if(c == 'u')
	{
		(unsigned int)n = -n;
	}
	if (n == INT_MIN)
	{
		pt_putbase((n / base), base,  len ,c);
		*len += write(1, "8",1);
	}
	else 
	{
		if (n < 0)
    	{
        	*len += write(1, "-", 1);
     		n = -n;
    	}
		if (n >= base)
		{
    		pt_putbase (n / base, base, len,c);
		} 	 
		if (c !='X')    
        	*len += write(1, &"0123456789abcdef"[n % base], 1);
    	else
        	*len += write(1, &"0123456789ABCDEF"[n % base], 1);
	}
}
