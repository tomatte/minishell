/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:52:46 by mleonard          #+#    #+#             */
/*   Updated: 2023/04/24 22:52:49 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_token
{
	char	*value;
	int		type;
	int		id;
}	t_token;

typedef struct s_command
{
	char	**args;
	int		input_fd;
	int		output_fd;
	int		pid;
	int		status;
}	t_command;

typedef struct s_exp
{
	char	*value;
	char	*name;
	char	*start;
	char	*end;
	int		len;
}	t_exp;

#endif
