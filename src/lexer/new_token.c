/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:16:48 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/27 16:24:13 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*new_token(char *value, int type, int id)
{
	t_token	*token;

	add_to_tracker(value);
	token = (t_token *) talloc(1, sizeof(t_token));
	token->value = value;
	token->type = type;
	token->id = id;
	return (token);
}
