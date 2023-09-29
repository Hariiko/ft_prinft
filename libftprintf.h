/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:50:19 by laltarri          #+#    #+#             */
/*   Updated: 2023/09/28 21:09:08 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>


char	*ft_strchr(const char *s, int c);
int		ft_printf(char const *argc, ... );
void	pt_putstr(char *str, int *len);
void	pt_putchar(char c, int *i);

#endif
