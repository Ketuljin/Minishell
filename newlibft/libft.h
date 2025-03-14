/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:01:04 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/14 02:40:37 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	int				value;
	int				index;
}				t_list;

int		ft_atoi(const char *nptr);//norm / paco-k
void	ft_bzero(void *s, size_t n);//norm / paco-k
void	*ft_calloc(size_t nmemb, size_t size);//norm / paco-k
int		ft_error(char *str);
int		ft_isalnum(int c);//norm / paco-k
int		ft_isalpha(int c);//norm / paco-k
int		ft_isascii(int c);//norm / paco-k
int		ft_isdigit(int c);//norm / paco-k
int		ft_isprint(int c);//norm / paco-k
char	*ft_itoa(int n);//norm / paco-k
void	*ft_memchr(const void *s, int c, size_t n);//norm / paco-k
int		ft_memcmp(const void *s1, const void *s2, size_t n);//norm / paco-k
void	*ft_memcpy(void *dest, const void *src, size_t n);//norm / paco-k
void	*ft_memmove(void *dest, const void *src, size_t n);//norm / paco-k
void	*ft_memset(void *s, int c, size_t n);//norm / paco-k
void	ft_putchar_fd(char c, int fd);//norm / paco-k
void	ft_putendl_fd(char *s, int fd);//norm / paco-k
void	ft_putnbr_fd(int n, int fd);//norm / paco-k
void	ft_putstr_fd(char *s, int fd);//norm / paco-k
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);//norm / paco-k
char	*ft_strdup(const char *s);//norm / paco-k
void	ft_striteri(char *s, void (*f)(unsigned int, char*));//norm / paco-k
char	*ft_strjoin(char const *s1, char const *s2);//norm / paco-k
size_t	ft_strlcat(char *dst, const char *src, size_t size);//norm / paco-k
size_t	ft_strlcpy(char *dst, const char *src, size_t size);//norm / paco-k
size_t	ft_strlen(const char *s);//norm / paco-k
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));//norm/paco-k
int		ft_strncmp(const char *s1, const char *s2, size_t n);//norm / paco-k
int		ft_strncmp_r(const char *s1, const char *s2, int n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);//nor/pacok
char	*ft_strrchr(const char *s, int c);//norm / paco-k
char	*ft_strtrim(char const *s1, char const *set);//norm / paco-k
char	*ft_substr(char const *s, unsigned int start, size_t len);//norm/paco-k
char	**ft_tabdup(char **src_tab);
void	ft_tabfree(char **tab);
size_t	ft_tablen(char **tab);
int		ft_tolower(int c);//norm / paco-k
int		ft_toupper(int c);//norm / paco-k

int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

char	*destock(char **remaining_str, unsigned int i);
void	stock(char **remaining_str, char *str);
void	stock_2mlc(char **remaining_str, char *str);
char	*get_next_line(int fd);

#endif
