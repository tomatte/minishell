/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:40:05 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/07 17:12:37 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../libft/libftprintf.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

const char	*get_username(void);
char		*get_directory(const char *username);
char		*get_hostname(void);
char		*get_prompt_msg(void);
char		*prompt(void);

char	**operators(void);
int		get_state(void);
void	set_state(int id);

#endif