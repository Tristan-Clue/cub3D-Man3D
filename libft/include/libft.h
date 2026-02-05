/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:52:05 by kchiang           #+#    #+#             */
/*   Updated: 2025/11/05 23:57:20 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

/* Whitespaces delimiter for ft_split.
 * */
# define WHITESPACE	" \t\n\v\f\r"

/* Shorthands for unsigned variable types. */
typedef unsigned char		t_uchar;
typedef unsigned int		t_uint;
typedef unsigned long		t_ulong;
typedef unsigned long long	t_ullong;
typedef long long			t_llong;

/* ********** ft_printf *********** */
int		ft_printf(const char *format, ...);

/* ******** get_next_line ********* */
char	*get_next_line(int fd);

/* ****** Functions in libft ****** */
int		ft_abs(int j);
float	ft_fabs(float j);
int		ft_atoi(const char *nptr);
int		ft_atoi_base(const char *nptr, const char *base);
t_llong	ft_atoll(const char *nptr);
t_llong	ft_llabs(t_llong j);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_qsort(void *base, size_t nmemb, size_t size,
			int (*compar)(const void *, const void *));
char	*ft_itoa(t_llong nbr);
char	*ft_itoa_base(t_llong nbr, const char *base);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_uitoa(t_ullong nbr);
char	*ft_uitoa_base(t_ullong nbr, const char *base);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(const char *s, const char *set);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);

#endif
