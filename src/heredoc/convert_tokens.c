/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:00:22 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/18 13:59:37 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	convert_tokens(t_list **tokens, t_list *heredoc_list)
{
	t_list	*cmd;

	cmd = get_heredoc_cmd(*tokens);
	ft_printf("command: ");print_token_value(cmd);
}
