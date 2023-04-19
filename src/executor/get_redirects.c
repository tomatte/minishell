/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:18:47 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/19 10:05:48 by dbrandao         ###   ########.fr       */
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
	if (id == HERE_DOC_END)
		fd = open(HERE_FILE, O_RDWR, 0644);
	else
		fd = open(name, flag, 0644);
	if (fd == -1)
	{
		perror(strerror(errno));
		mini_exit(1);
	}
	return (fd);
}

t_list	*redirect_remove(t_list **redirect)
{
	t_list	*op;
	t_list	*aux;

	if (is_redirect(*redirect))
	{
		*redirect = (*redirect)->next->next;
		return (*redirect);
	}
	op = *redirect;
	while (op && !is_redirect(op))
	{
		aux = op;
		op = op->next;
	}
	if (is_redirect(op))
		aux->next = op->next->next;
	return (op);
}

static int	get_redirect_fd(t_list *tokens)
{
	t_token	*tkn;
	int		fd;

	tkn = tokens->next->content;
	if (tkn->id == HERE_DOC_END)
		read_fork(tkn->value);
	fd = open_file(tkn->id, tkn->value);
	return (fd);
}

static void	fill_new_fd(t_list *tokens, int *redirects)
{
	t_token	*tkn;
	int		fd;

	tkn = token(tokens);
	fd = get_redirect_fd(tokens);
	if (tkn->id == R_OUTPUT || tkn->id == R_APPEND_OUT)
		redirects[W] = fd;
	else
		redirects[R] = fd;
}

void	get_redirects(t_list **tokens, int *redirects)
{
	t_list	*op;

	redirects[R] = STDIN_FILENO;
	redirects[W] = STDOUT_FILENO;
	while (1)
	{
		op = *tokens;
		op = next_operator2(op);
		if (op == NULL || !is_redirect(op))
			return ;
		fill_new_fd(op, redirects);
		redirect_remove(tokens);
	}
}
