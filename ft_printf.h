/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laltarri <laltarri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:50:19 by laltarri          #+#    #+#             */
/*   Updated: 2023/09/30 01:11:43 by laltarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

char	*ft_strchr(const char *s, int c);
int		ft_printf(char const *argc, ... );
void	ft_putstr(char *str, int *len);
char	*ft_strchr(const char *s, int c);
void	pt_putbase(int n, int base, int *len, char c);
void	pt_putchar(int c, int *i);

#endif
