/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 22:58:29 by smickael          #+#    #+#             */
/*   Updated: 2018/03/30 22:58:33 by smickael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_printf.h"

typedef int			t_bool;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(const void *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
char			*ft_strchr(const char *s, int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strcpy(char *dst, char *src);
char			*ft_strdup(const char *str);
size_t			ft_strlen(const char *s);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
unsigned int	ft_strlcat(char *dst, char *src, unsigned int size);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
char			*ft_itoa(int n);
void			ft_memdel(void **ap);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putendl(const char *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putstr(const char *s);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
int				ft_strequ(const char *s1, const char *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			**ft_strsplit(const char *s, char c);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
int				ft_isspace(char c);
char			*ft_strndup(const char *s1, size_t n);
int				ft_putwchar(unsigned wchar, int wstrlen);
size_t			ft_wstrlen(unsigned *s);
size_t			ft_wcharlen(unsigned c);
int				ft_putwstr(wchar_t *s);
double			ft_pow(double n, int pow);
void			ft_putstr_free(char const *s);
#endif
