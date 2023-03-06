/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:54:54 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/18 20:38:18 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include "../../libft.h"

# define CONVERSION "cspdiuxX%"
# define FORMAT "-0.# +"

typedef struct s_sign
{
	int	minus;
	int	zero;
	int	dot;
	int	ht;
	int	spc;
	int	plus;
	int	type;
	int	fill;
	int	is_valid;
}				t_sign;

char	*ft_uitoa(unsigned int n);
int		ft_printf(const char *str, ...);
void	init_sign(t_sign **sign);
void	sign_place(t_sign **sign, int c);
void	ft_convert(t_sign **sign, va_list ap, int *len);
void	dot_case(const char *str, t_sign **sign, int c, int *index);
void	is_digit_alone(const char *str, t_sign **sign, int *index, int *c);
char	*set_n0(char **str, t_sign **sign);
char	*print_int(t_sign **sign, va_list ap);
char	*print_hex(t_sign **sign, va_list ap, char type);
char	*print_pointer(t_sign **sign, va_list ap);
char	*print_uint(t_sign **sign, va_list ap);
void	fill(char **str, t_sign **sign);
void	fill_c(char **str, t_sign **sign);
void	fill_zeros(char **str, t_sign **sign);

#endif