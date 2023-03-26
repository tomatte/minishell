/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:50:51 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/26 19:45:53 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

//TO BE USED AS TYPES AND STATES
# define NONE 0
# define START 1
# define WORD 2
# define OPERATOR 3
# define EXPANSIVE 4
# define QUOTE 5

//WORD
# define EXEC 6
# define ARG 7
# define IN_FILE 8
# define OUT_FILE 9
# define HERE_DOC_END 10
# define DELIMITER "$'\"<|>"

//QUOTE
# define SIMPLE_QUOTES 11
# define DOUBLE_QUOTES 12

//EXPANSIVE
# define ENV_VAR 13
# define EXIT_STAT 14

//OPERATOR
# define HERE_DOC 15
# define R_APPEND_OUT 16
# define R_INPUT 17
# define R_OUTPUT 18
# define PIPE 19

//UTILS
# define NEXT 20

# define OP_NUM 5

# define R 0
# define W 1

# define PATH_START "PATH="

//ERRORS
# define ERR_UNCLOSED_QUOTES -2
# define ERR_NUT -3
# define CREATE_FILE_ERROR -4
# define OPEN_FILE_ERROR -5
# define EXEC_ERR -6

#endif