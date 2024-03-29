/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:18:47 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/26 10:25:24 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	open_file(int id, char *name)
{
	int		fd;
	int		flag;

	flag = 0;
	if (id == R_INPUT || id == HERE_DOC)
		flag = flag | O_RDONLY;
	if (id == R_OUTPUT)
		flag = flag | O_WRONLY | O_CREAT | O_TRUNC;
	if (id == R_APPEND_OUT)
		flag = flag | O_WRONLY | O_APPEND | O_CREAT;
	fd = open(name, flag, 0644);
	if (fd <= -1)
		redirect_error(name);
	else
		add_fd(fd);
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
	int		fd;

	fd = open_file(token(tokens)->id, token(tokens->next)->value);
	return (fd);
}

static int	fill_new_fd(t_list *tokens, int *redirects)
{
	t_token	*tkn;
	int		fd;

	tkn = token(tokens);
	fd = get_redirect_fd(tokens);
	if (fd <= -1)
		return (-1);
	if (tkn->id == R_OUTPUT || tkn->id == R_APPEND_OUT)
		redirects[W] = fd;
	else
		redirects[R] = fd;
	return (0);
}

int	get_redirects(t_list **tokens, int *redirects)
{
	t_list	*op;
	int		err;

	redirects[R] = STDIN_FILENO;
	redirects[W] = STDOUT_FILENO;
	while (1)
	{
		op = *tokens;
		op = next_operator2(op);
		if (op == NULL || !is_redirect(op))
			return (0);
		err = fill_new_fd(op, redirects);
		redirect_remove(tokens);
		if (err == -1)
			return (-1);
	}
	return (0);
}
