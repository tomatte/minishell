/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:40:05 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/22 10:45:38 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../libft/libftprintf.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "./defines.h"
# include "./structs.h"

//PROMPT
const char	*get_username(void);
char		*get_directory(const char *username);
char		*get_hostname(void);
char		*get_prompt_msg(void);
char		*prompt(void);

//STATICS
char	**operators(void);
int		get_state(void);
void	set_state(int id);

//LEXER
t_list	*lexer(char *str);
t_token	*new_token(char *value, int type, int id);
t_token	*identify_operator(char **str);
t_token	*identify_quotes(char **str);
t_token	*identify_word(char **str);

//PARSER
void	parser(t_list *tokens);
void	categorize_word(t_token *token);
void	syntax(t_list *tokens);

//UTILS
void	cleaner(char *str, t_list *tokens);
int		in_error(void);
char	*read_all(int fd);
t_token	*token(t_list *tokens);

//ERROR
void	nut_error(char *str);

//EXECUTOR
void	executor(t_list *tokens);
t_list	*get_files(t_list *tokens);
void	clear_files(t_list *files);
char	**get_args(t_list *tokens);
void	pipe_exec(t_list *tokens);

#endif