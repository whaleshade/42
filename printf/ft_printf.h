/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:20:04 by jibang            #+#    #+#             */
/*   Updated: 2022/04/29 16:32:25 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putnbr_unsign(unsigned int n, int *len);
void	ft_putnbr_base(unsigned int nbr, char *base, int *len);
void	ft_print_mem_address(unsigned long long nbr, int *len);
int		ft_printf(const char *str, ...);

#endif
