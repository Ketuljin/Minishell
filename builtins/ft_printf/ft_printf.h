/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:29:31 by jkerthe           #+#    #+#             */
/*   Updated: 2023/11/17 12:33:18 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printchar(char n);
int		ft_printf(const char *test, ...);
int		ft_print_unsigned(unsigned int n);
int		ft_printnbr(int nb);
int		ft_printdi(const char test, va_list args);
int		ft_hex_len(unsigned	int num);
int		ft_print_hex(unsigned int num, const char format);
int		ft_prints(char *str);
int		ft_print_ptr(unsigned long long int ptr);
int		ft_ptr_len(unsigned	long long num);
int		ft_num_len(unsigned	int num);
void	ft_put_hex(unsigned int num, const char format);
void	ft_put_ptr(unsigned long long num);
void	ft_putstr(char *str);
size_t	getcpt(int nb);
char	*ft_uitoa(unsigned int n);
char	*ft_itoa(int n);

#endif
