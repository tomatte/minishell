/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:37:08 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/06 15:34:30 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_prompt_message(void)
{
	char	*current_dir;
	char	*full_msg;
	char	*aux;
	char	*user;

	user = ft_strjoin(getenv("USER"), ":");
	aux = getcwd(NULL, 0);
	current_dir = ft_strjoin(aux, "$ ");
	full_msg = ft_strjoin(user, current_dir);
	free(current_dir);
	free(user);
	free(aux);
	return (full_msg);
}

char	*prompt(void)
{
	char	*str_command;
	char	*prompt_message;

	prompt_message = get_prompt_message();
	str_command = readline(prompt_message);
	free(prompt_message);
	add_history(str_command);
	return (str_command);
}
