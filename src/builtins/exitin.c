/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:45:36 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	not_num_err(char *cmd)
{
	ft_putstr_fd("exit: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	mini_exit(2);
}

static int	get_args_len(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
		i++;
	return (i);
}

static void	many_args_err(void)
{
	ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
	mini_exit(1);
}

static int	num_overflow(char *number)
{
	long long int	sign;
	long long int	n;
	long long int	previous;
	long long int	current;

	sign = 1;
	if (*number == '-')
		sign = -1;
	if (ft_issign(*number))
		number++;
	n = 0;
	while (*number)
	{
		previous = n * sign;
		n = n * 10 + *number - '0';
		current = n * sign;
		if (current / 10 != previous)
			return (1);
		number++;
	}
	return (0);
}

void	exitin(t_command *cmd)
{
	int	args_len;

	ft_putstr("exit\n");
	args_len = get_args_len(cmd);
	if (args_len == 1)
		mini_exit(get_error());
	else if (!ft_isnumber(cmd->args[1]) || num_overflow(cmd->args[1]))
		not_num_err(cmd->args[1]);
	else if (args_len == 2)
		mini_exit(ft_atoi(cmd->args[1]));
	else
		many_args_err();
}
