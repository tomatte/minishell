/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:07:49 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/05 10:22:03 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 08:56:03 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/05 09:09:09 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	open_file(int id, char *name)
{
	int		fd;
	int		flag;

	flag = 0;
	if (id == R_INPUT)
		flag = flag | O_RDONLY;
	if (id == R_OUTPUT)
		flag = flag | O_WRONLY | O_CREAT;
	if (id == R_APPEND_OUT)
		flag = flag | O_WRONLY | O_APPEND | O_CREAT;
	fd = open(name, flag, 0664);
	if (fd == -1)
	{
		perror(strerror(errno));
		exit(1); //use exit_error()
	}
	return (fd);
}

t_list	*redirect_remove(t_list *redirect)
{
	t_list	*aux;

	while (redirect && !is_redirect(redirect))
	{
		aux = redirect;
		redirect = redirect->next;
	}
	if (is_redirect(redirect))
		aux->next = redirect->next->next;
	return (redirect);
}

static void	fill_new_fd(t_list *tokens, int *redirects)
{
	t_token	*tkn;
	int		fd;

	tkn = token(tokens);
	fd = open_file(tkn->id, token(tokens->next)->value);
	if (tkn->id == R_OUTPUT || tkn->id == R_APPEND_OUT)
		redirects[W] = fd;
	else
		redirects[R] = fd;
}

void	get_redirects(t_list *tokens, int *redirects)
{
	t_list	*aux;

	redirects[R] = STDIN_FILENO;
	redirects[W] = STDOUT_FILENO;
	aux = tokens;
	while (1)
	{
		tokens = aux;
		tokens = next_operator(tokens);
		if (tokens == NULL || !is_redirect(tokens))
			return ;
		fill_new_fd(tokens, redirects);
		redirect_remove(aux);
	}
}
