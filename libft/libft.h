/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao < dbrandao@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:27:51 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/26 14:21:26 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "./get_next_line/get_next_line_bonus.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define HEXMAP "0123456789abcdef"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_toupper(int c); //convert word to upper based on ASCIIV
int		ft_tolower(int c); //convert word to upper based on ASCII

//fills memory with zeros: useful for initializations or cleaning data
void	ft_bzero(void *s, size_t n);

//copies from a memory to another: overlap not treated
void	*ft_memcpy(void *dest, const void *src, size_t n);

//fills memory with value specified in c
void	*ft_memset(void *str, int c, size_t n);

//copies data from a memory to another and treats overlap
void	*ft_memmove(void *dest, const void *src, size_t n);

//if c values is found, then it's location is returned
void	*ft_memchr(const void *s, int c, size_t n);

//string length
size_t	ft_strlen(const char *s);

//copies string until specified size or null char is found
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

//finds a char in a string and returns it's location
char	*ft_strchr(const char *s, int c);

//return the location of the last specified char found int he string
char	*ft_strrchr(const char *s, int c);

//cocatenates strings until specified size
size_t	ft_strlcat(char *dst, const char *src, size_t size);

//compare strings until n size. returns *s1 - *s2, then 0 if equals
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);

//same as ft_putnbr, but with unsigned integers
void	ft_put_uint(unsigned int n);

//converts decimal to hexadecimal
char	*ft_itohex(long unsigned int number);

//convert string to uppercase
char	*ft_strtoupper(char *str);

int		ft_abs(int num);

/*verify if string is a number, 
it passes the initial spaces and stops in the first space after the number
result examples:
"  -99 " is a number
"+99" is a number
"99" is a number
"99t" is not a number
*/
char	*ft_isnumber(char *str);

//verify if character is a space 
int		ft_isspace(char c);

//return 1 if char is - or +
int		ft_issign(char c);

//add a char to the end of the string
void	ft_str_push_char(char **str, char c);

//potentiation
int		ft_pow(int num, int power);

//returns the lowest of two numbers
int		ft_lowest(int x, int y);

//returns the highest of two numbers
int		ft_highest(int x, int y);

//returns 1 if the strings are equal or 0 if not
int		ft_streq(char *s1, char *s2);

#endif