/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:31:26 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/06 19:49:34 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

Test(prompt, get_username)
{
	cr_assert_str_eq(MY_USER, get_username());
}

Test(prompt, get_hostname)
{
	char	*hostname;

	hostname = get_hostname();
	if (hostname)
	{
		cr_assert_str_eq(MY_HOST, hostname);
		free(hostname);
	}
}

Test(prompt, get_directory)
{
	char	*directory;

	directory = get_directory(MY_USER);
	cr_assert_str_eq(directory, "~/codes/42/minishell/tests");
}
