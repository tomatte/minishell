/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:06:09 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/23 15:43:27 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	mini_exit(int code)
{
	destroy_memories();
	destroy_evars2();
	clear_history();
	close(R);
	close(W);
	close(2);
	exit(code);
}
