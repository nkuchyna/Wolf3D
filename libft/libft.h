/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:05:22 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/06/03 13:53:53 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 100

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_readlist
{
	char				*str;
	int					fd;
	int					get_end;
	struct s_readlist	*next;
}						t_readlist;

void					ft_putchar(char c);
void					ft_putstr(char const *s);
size_t					ft_strlen(const char *s);
void					ft_strclr(char *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
void					ft_striter(char *s, void (*f)(char *));
int						ft_strequ(char const *s1, char const *s2);
int						ft_toupper(int c);
int						ft_tolower(int c);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isascii(int c);
int						ft_isalnum(int	c);
int						ft_isprint(int c);
char					*ft_strstr(const char *big, const char *little);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
									size_t n);
char					*ft_strnstr(const char *big, const char *little,
									size_t len);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
void					ft_strdel(char **as);
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strnew(size_t size);
char					*ft_strmapi(char const *s,
									char (*f)(unsigned int, char));
char					*ft_strsub(char const *s,
									unsigned int start, size_t len);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_strjoin_n(char **s1, char **s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(int n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_printarray_charx2(char **array);
char					**ft_createarray_charx2(int x, int y, char filler);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void					ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_change_register(char *str, int flag);
char					*ft_reverse_str(char *str);
int						*ft_sort_int_array(int *array, int array_size);
void					ft_swap(int *a, int *b);
int						get_next_line(const int fd, char **line);
void					ft_clear_str(char *str, int len);
int						ft_exit_x(void);
int						ft_ststr_for_diff_registers(char *big, char *lit);
void					ft_free_char_array(char **array);
char					**ft_strsplit_new(char *s);
int						ft_strstr_new(char *big, char *lit);

#endif
