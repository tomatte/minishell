/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_docs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:50:33 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/26 10:35:46 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*get_here_filename(int num)
{
	char	*filename;
	char	*number;

	number = ft_itoa(num);
	filename = ft_strjoin(HERE_FILE, number);
	free(number);
	add_to_tracker(filename);
	return (filename);
}

static void	read_to_file(t_token *tkn, int num)
{
	char	*filename;

	filename = get_here_filename(num);
	read_fork(filename, tkn->value);
	tkn->value = filename;
}

void	read_docs(t_list *tokens)
{
	int	num;

	num = 0;
	while (tokens)
	{
		if (token(tokens)->id == HERE_DOC_END)
			read_to_file(token(tokens), num++);
		tokens = tokens->next;
	}
}
