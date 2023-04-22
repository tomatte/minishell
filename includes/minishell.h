/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:40:05 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/22 15:27:21 by dbrandao         ###   ########.fr       */
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
# include <errno.h>
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
//MEMORY TRACK
void	destroy_memories(void);
void	*talloc(size_t nmemb, size_t size);
void	add_to_tracker(void *mem);
t_list	*lstnew_track(void *content);

//EVARS
char	**get_evars(void);
void	add_evar(char *var);
void	start_evars(char **envp);
void	destroy_evars(void);

//evars2
t_list	**evars2(void);
void	start_evars2(char **envp);
t_list	*get_evars2(void);
void	destroy_evars2(void);
void	add_evar2(char *str);
t_list	*find_evar2(char *str);
void	remove_evar(char *str);
char	**get_evars_arr(void);

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
void	cleaner(t_list *tokens);
int		in_error(void);
char	*read_all(int fd);
t_token	*token(t_list *tokens);
t_list	*next_operator(t_list *tokens);
t_list	*next_operator2(t_list *tokens);
int		is_operator(t_list *tokens, int operator);
int		is_redirect(t_list *tokens);
t_list	*next_pipe(t_list *tokens);
t_list	*next_pipe2(t_list *tokens);
void	mini_exit(int code);
int		is_option(char *str);
char	*join_and_free(char *s1, char *s2);
int		no_command(t_list *tokens);

//ERROR
void	nut_error(char *str);
void	cmd_not_found(char *cmd);
void	set_error(int code);
int		get_error(void);
void	invalid_option(char *cmd, char *opt);
void	no_such_file(char *cmd, char *file);
void	invalid_identifier(char *cmd, char *identifier);
void	exec_error_exit(int err, int code);
void	normal_exec_error(int err, t_command *cmd);
void	inpath_exec_error(int err, char *cmd);
void	redirect_error(char *file);

//EXECUTOR
void		executor(t_list *tokens);
t_list		*get_files(t_list *tokens);
char		**get_args(t_list *tokens);
void		pipe_exec(t_list *tokens);
int			**get_pipedes(t_list *tokens);
t_list		*get_commands(t_list *tokens, int **pipedes);
void		exec_commands(t_list *tokens, t_list *commands, int **pipedes);
void		close_pipes(int **pipedes);
char		**get_paths(char *cmd);
void		command_exec(t_command *command);
void		get_redirects(t_list **tokens, int *redirects);
t_command	*new_command(t_list *tokens, int fd_in, int fd_out);
void		simple_exec(t_list *tokens);

//TEMP
void	print_pipedes(int **pipedes);
void	print_commands(t_list *commands);
void	print_command(t_command *command);
void	print_tokens(t_list *tokens);
void	print_args(char **args);
void	print_asc(char *str);
void	print_token(t_token *token);
void	print_token_value(t_list *node);

//EXPANDER
void	expander(char **str);
void	fill_exp(t_exp *exp, char *str);
void	fill_exp_value(t_exp *exp);
void	expand_str(char **str, t_exp *exp);

//BUILT-INS
void	echo(t_command *cmd);
void	cd(t_command *cmd);
void	exitin(t_command *cmd);
void	pwd(t_command *cmd);
void	env(t_command *cmd);
void	export(t_command *cmd);
void	unset(t_command *cmd);

//HEREDOC
int		get_sdoc(void);
void	set_sdoc(int id);
void	read_fork(char *end);

//SIGNALS
void	disable_signals(void);
void	set_sig_here(void);
void	set_signals(void);

//TRANSFORMER
void	transformer(char *str);
int		is_quote(char c);
int		is_delimiter2(char c);
int		have_quotes(char *s);
void	pass_word(char **str);
void	pass_quotes(char **s);
char	*get_opening_quote(char *str);
char	*get_closing_quote(char *s, char quote);
void	move_quote_left(char *str, char *start);
void	move_quote_right(char *s, char **str, char *end);

#endif