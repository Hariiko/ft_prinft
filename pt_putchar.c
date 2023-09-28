/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:41:58 by laltarri          #+#    #+#             */
/*   Updated: 2023/09/28 21:06:30 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	pt_putchar(char c, int *i)
{
	int cont;

	cont =	write(1, &c, 1);
	if (cont == -1)
		*i = -1;
	(*i)++;
}
