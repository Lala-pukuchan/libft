/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 08:11:21 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/23 11:21:21 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char	ft_test_strmapi(unsigned int i, char c);
void	ft_test_striteri(unsigned int i, char *p);
void	ft_del(void* vp);
void	ft_upper_content(void* vp);
void	*ft_lower_content(void* vp);

int main(void)
{
	/*
		ft_isalpha
		alphabet -> 1 : others -> 0
	*/
	printf("---isalpha---\n");
	printf("a = 1 : o = %d\n", ft_isalpha('a'));
	printf("a = 1 : o = %d\n", ft_isalpha('Z'));
	printf("a = 0 : o = %d\n", ft_isalpha(' '));
	printf("a = 0 : o = %d\n", ft_isalpha('1'));
	/*
		ft_isdigit
		digit -> 1 : others -> 0
	*/
	printf("---isdigit---\n");
	printf("a = 0 : o = %d\n", ft_isdigit('a'));
	printf("a = 0 : o = %d\n", ft_isdigit('Z'));
	printf("a = 0 : o = %d\n", ft_isdigit(' '));
	printf("a = 1 : o = %d\n", ft_isdigit('1'));
	/*
		ft_isalnum
		alphabet&digit -> 1 : others -> 0
	*/
	printf("---isalnum---\n");
	printf("a = 1 : o = %d\n", ft_isalnum('a'));
	printf("a = 1 : o = %d\n", ft_isalnum('Z'));
	printf("a = 0 : o = %d\n", ft_isalnum(' '));
	printf("a = 1 : o = %d\n", ft_isalnum('1'));
	/*
		ft_isascii
		ascii -> 1 : others -> 0
	*/
	printf("---isascii---\n");
	printf("a = 1 : o = %d\n", ft_isascii('a'));
	printf("a = 1 : o = %d\n", ft_isascii('['));
	printf("a = 1 : o = %d\n", ft_isascii(' '));
	printf("a = 1 : o = %d\n", ft_isascii('1'));
	/*
		ft_isprint
		printable -> 1 : others -> 0
	*/
	printf("---isprint---\n");
	printf("a = 1 : o = %d\n", ft_isprint('a'));
	printf("a = 1 : o = %d\n", ft_isprint('['));
	printf("a = 0 : o = %d\n", ft_isprint('\n'));
	printf("a = 1 : o = %d\n", ft_isprint('1'));
	/*
		ft_strlen
		length of str
	*/
	printf("---strlen---\n");
	char *str_strlen0 = "test";
	char *str_strlen1 = "";
	printf("a = %zu : o = %zu\n", strlen(str_strlen0), ft_strlen(str_strlen0));
	printf("a = %zu : o = %zu\n", strlen(str_strlen1), ft_strlen(str_strlen1));
	/*
		ft_memset
		allocate char to memory of n bytes
	*/
	printf("---memset---\n");
	char str_memset0[] = "0123456789";
	memset(str_memset0 + 2, '*', 5);
	char str_memset1[] = "0123456789";
	ft_memset(str_memset1 + 2, '*', 5);
	printf("a = %s : o = %s\n", str_memset0, str_memset1);
	/*
		ft_bzero
		allocate 0 to memory of n bytes
	*/
	printf("---bzero---\n");
	char str_bzero0[] = "0123456789";
	bzero(str_bzero0 + 3, 5);
	char str_bzero1[] = "0123456789";
	ft_bzero(str_bzero1 + 3, 5);
	printf("a = %s : o = %s\n", str_bzero0, str_bzero1);
	/*
		ft_memcpy
		copy str from one memory to another
	*/
	printf("---memcpy---\n");
	char str_memcpy0[] = "0123456789";
	char str_memcpy1[] = "ABCDEFGHIJ";
	memcpy(str_memcpy0, str_memcpy1, 3);
	char str_memcpy2[] = "0123456789";
	char str_memcpy3[] = "ABCDEFGHIJ";
	ft_memcpy(str_memcpy2, str_memcpy3, 3);
	printf("a = %s : o = %s\n", str_memcpy0, str_memcpy2);
	/*
		ft_memmove
		copy str from one memory to another with allowed duplicated memory
	*/
	printf("---memmove---\n");
	char str_memmove0[] = "0123456789";
	memmove(str_memmove0, str_memmove0 + 4, 3);
	char str_memmove1[] = "0123456789";
	ft_memmove(str_memmove1, str_memmove1 + 4, 3);
	printf("a = %s : o = %s\n", str_memmove0, str_memmove1);
	/*
		ft_strlcpy
		copy from src str to dst str by n bytes and return source length
	*/
	printf("---strlcpy---\n");
	char str_strlcpy0[] = "0123456789";
	char str_strlcpy1[] = "ABCDEFGHIJ";
	int a = strlcpy(str_strlcpy0, str_strlcpy1, 5);
	char str_strlcpy2[] = "0123456789";
	char str_strlcpy3[] = "ABCDEFGHIJ";
	int b = ft_strlcpy(str_strlcpy2, str_strlcpy3, 5);
	printf("a = %s : o = %s\n", str_strlcpy0, str_strlcpy2);
	printf("a = %d : o = %d\n", a, b);
	/*
		ft_strlcat
		add the src char to the last of dest char within n bytes
		size - strlen(dst) - 1 is the max length for concatinating
		max size is third param
	*/
	printf("---strlcat---\n");
	char str_strlcat0[10] = "012";
	char str_strlcat1[] = "ABCDEFGHIJ";
	strlcat(str_strlcat0, str_strlcat1, sizeof(str_strlcat0));
	char str_strlcat2[10] = "012";
	char str_strlcat3[] = "ABCDEFGHIJ";
	ft_strlcat(str_strlcat2, str_strlcat3, sizeof(str_strlcat2));
	printf("a = %s : o = %s\n", str_strlcat0, str_strlcat2);
	/*
		ft_toupper
		change to upper case
	*/
	printf("---toupper---\n");
	char str_toupper0 = 'a';
	char str_toupper1 = 'a';
	printf("a = %c : o = %c\n", toupper(str_toupper0), ft_toupper(str_toupper1));
	/*
		ft_tolower
		change to lower case
	*/
	printf("---tolower---\n");
	char str_tolower0 = 'A';
	char str_tolower1 = 'A';
	printf("a = %c : o = %c\n", tolower(str_tolower0), ft_tolower(str_tolower1));
	/*
		ft_strchr
		search the char from the begining and return the pointer of first found
	*/
	printf("---strchr---\n");
	char str_strchr0[] = "0123456789";
	char str_strchr1[] = "0123456789";
	printf("a = %s : o = %s\n", strchr(str_strchr0, '4'), ft_strchr(str_strchr1, '4'));
	/*
		ft_strrchr
		search the char from the last and return the pointer of first found
	*/
	printf("---strrchr---\n");
	char str_strrchr0[] = "0123454321";
	char str_strrchr1[] = "0123454321";
	printf("a = %s : o = %s\n", strrchr(str_strrchr0, '4'), ft_strrchr(str_strrchr1, '4'));
	/*
		ft_strncmp
		compare strings and return diff if different char is found
	*/
	printf("---strncmp---\n");
	char str_strncmp0[] = "\200";
	char str_strncmp1[] = "\0";
	char str_strncmp2[] = "\200";
	char str_strncmp3[] = "\0";
	printf("a = %d : o = %d\n", strncmp(str_strncmp0, str_strncmp1, 10), ft_strncmp(str_strncmp2, str_strncmp3, 10));
	/*
		ft_memchr
		search the char from memory from the begining
	*/
	printf("---memchr---\n");
	char str_memchr0[] = "ABCDEFAHIJ";
	char str_memchr1[] = "ABCDEFAHIJ";
	printf("a = %s : o = %s\n", memchr(str_memchr0, 'C', sizeof(str_memchr0)), ft_memchr(str_memchr1, 'C', sizeof(str_memchr1)));
	/*
		ft_memcmp
		compare strings and return diff if different char is found
	*/
	printf("---memcmp---\n");
	char str_memcmp0[] = "\200";
	char str_memcmp1[] = "\0";
	printf("a = %d : o = %d\n", memcmp(str_memcmp0, str_memcmp1, 10), ft_memcmp(str_memcmp0, str_memcmp1, 10));
	/*
		ft_strnstr
		find the char in char till n bytes
	*/
	printf("---strnstr---\n");
	char str_strnstr0[] = "ABCDEFGHIJ";
	char str_strnstr1[] = "DEF";
	printf("a = %s : o = %s\n", strnstr(str_strnstr0, str_strnstr1, 7), ft_strnstr(str_strnstr0, str_strnstr1, 7));
	/*
		ft_atoi
		str -> int
	*/
	printf("---atoi---\n");
	int i = 0;
	char s[3][128] = {"-2147483648"," 2147483647","-123"};
	while (i < 3)
	{
		printf("a = %s : o = %d\n", s[i], ft_atoi(s[i]));
		i++;
	}
	/*
		ft_calloc
	*/
	printf("---calloc---\n");
	char *p_calloc0 = calloc(1, 4);
	i = 0;
	while (i < 4)
	{
		p_calloc0[i] = 'x';
		i++;
	}
	p_calloc0[i] = '\0';
	char *p_calloc1 = calloc(1, 4);
	i = 0;
	while (i < 4)
	{
		p_calloc1[i] = 'x';
		i++;
	}
	p_calloc1[i] = '\0';
	printf("a = %s : o = %s\n", p_calloc0, p_calloc1);
	/*
		ft_strdup
	*/
	printf("---strdup---\n");
	char str_strdup0[] = "ABCDEFGHIJ";
	char *p_strdup0 = strdup(str_strdup0);
	char *p_strdup1 = strdup(str_strdup0);
	printf("a = %s : o = %s\n", p_strdup0, p_strdup1);
	free(p_strdup0);
	free(p_strdup1);
	/*
		ft_substr
	*/
	printf("---substr---\n");
	char str_substr0[] = "ABCDEFGHIJ";
	char *p_substr0 = ft_substr(str_substr0, 2, 3);
	printf("a = CDE : o = %s\n", p_substr0);
	free(p_substr0);
	/*
		ft_strjoin
	*/
	printf("---strjoin---\n");
	char str_strjoin0[] = "ABCDE";
	char str_strjoin1[] = "FGHIJ";
	char *p_strjoin0 = ft_strjoin(str_strjoin0, str_strjoin1);
	printf("a = ABCDEFGHIJ : o = %s\n", p_strjoin0);
	free(p_strjoin0);
	/*
		ft_strtrim
	*/
	printf("---strtrim---\n");
	char str_strtrim0[] = "ABCDEFGHIJ";
	char str_strtrim1[] = "ABJ";
	char *p_strtrim0 = ft_strtrim(str_strtrim0, str_strtrim1);
	printf("a = CDEFGHI : o = %s\n", p_strtrim0);
	free(p_strtrim0);
	/*
		ft_split
	*/
	printf("---split---\n");
	char str_split0[] = "ABC,DEF,GHIJ";
	char char_split1 = ',';
	char **p_split0 = ft_split(str_split0, char_split1);
	printf("a = ABC\na = DEF\na = GHIJ\n");
	i = 0;
	while (i < 3)
	{
		printf("o = %s\n", p_split0[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		free(p_split0[i]);
		i++;
	}
	free(p_split0);
	/*
		ft_itoa
	*/
	printf("---itoa---\n");
	int int_itoa0 = -123;
	char *str_itoa0 = ft_itoa(int_itoa0);
	printf("a = -123 : o = %s\n", str_itoa0);
	free(str_itoa0);
	/*
		ft_strmapi
	*/
	printf("---strmapi---\n");
	char *str_strmapi0 = "abc";
	char *str_strmapi1 = ft_strmapi(str_strmapi0, ft_test_strmapi);
	printf("a = ace : o = %s\n", str_strmapi1);
	free(str_strmapi1);
	/*
		ft_striteri
	*/
	printf("---striteri---\n");
	char str_striteri0[128] = "abc";
	ft_striteri(str_striteri0, ft_test_striteri);
	printf("a = ace : o = %s\n", str_striteri0);
	/*
		ft_putchar_fd
	*/
	printf("---putchar_fd---\n");
	ft_putchar_fd('a', 1);
	ft_putchar_fd('\n', 1);
	/*
		ft_putstr_fd
	*/
	printf("---putstr_fd---\n");
	ft_putstr_fd("aaa\n", 1);
	/*
		ft_putendl_fd
	*/
	printf("---putendl_fd---\n");
	ft_putendl_fd("aaa", 1);
	/*
		ft_putnbr_fd
	*/
	printf("---putnbr_fd---\n");
	ft_putnbr_fd(123, 1);
	/*
		ft_lstnew
	*/
	printf("\n---lstnew---\n");
	t_list	*l_lstnew = ft_lstnew("abc\n");
	printf("t_list.content = %s", l_lstnew->content);
	/*
		ft_lstadd_front
	*/
	printf("---lstadd_front---\n");
	t_list	*l_lstadd_front = ft_lstnew("def\n");
	t_list **p_lstadd_front_1 = &l_lstadd_front;
	printf("t_list.content = %s", (**p_lstadd_front_1).content);
	ft_lstadd_front(p_lstadd_front_1, l_lstnew);
	printf("t_list.content = %s", (**p_lstadd_front_1).content);
	free(l_lstnew);
	free(l_lstadd_front);
	/*
		ft_lstsize
	*/
	printf("---lstsize---\n");
	t_list	*l_lstsize0 = ft_lstnew("abc\n");
	t_list	*l_lstsize1 = ft_lstnew("def\n");
	l_lstsize0->next = l_lstsize1;
	l_lstsize1->next = NULL;
	printf("node list size a = 2\n");
	printf("node list size o = %d\n", ft_lstsize(l_lstsize0));
	/*
		ft_lst_last
	*/
	printf("---lst_last---\n");
	t_list	*p_lst_last = ft_lstlast(l_lstsize0);
	printf("p_lst_last.content a = def\n");
	printf("p_lst_last.content o = %s", p_lst_last->content);
	/*
		ft_lstadd_back
	*/
	printf("---lstadd_back---\n");
	t_list	*l_lstadd_back2 = ft_lstnew("ghi\n");
	ft_lstadd_back(&l_lstsize0, l_lstadd_back2);
	t_list	*p_lstadd_back = ft_lstlast(l_lstsize0);
	printf("p_lstadd_back.content a = ghi\n");
	printf("p_lstadd_back.content o = %s", p_lstadd_back->content);
	/*
		ft_lstdelone
	*/
	printf("---lstdelone---\n");
	char *str = malloc(4);
	i = 0;
	while (i < 3)
	{
		str[i] = 'a';
		i++;
	}
	str[i] = '\0';
	t_list	*l_lstdelone0 = ft_lstnew(str);
	ft_lstdelone(l_lstdelone0, ft_del);
	printf("l_lstdelone0->content a = \n");
	printf("l_lstdelone0->content o = %s\n", l_lstdelone0->content);
	printf("l_lstdelone0->next a = 0x0\n");
	printf("l_lstdelone0->next o = %p\n", l_lstdelone0->next);
	/*
		ft_lstclear
	*/
	printf("---lstclear---\n");
	t_list **p_lstclear;
	char *str_lstclear0 = malloc(4);
	i = 0;
	while (i < 3)
	{
		str_lstclear0[i] = 'a';
		i++;
	}
	str_lstclear0[i] = '\0';
	t_list	*l_lstclear0 = ft_lstnew(str_lstclear0);
	char *str_lstclear1 = malloc(4);
	i = 0;
	while (i < 3)
	{
		str_lstclear1[i] = 'a';
		i++;
	}
	str_lstclear1[i] = '\0';
	t_list	*l_lstclear1 = ft_lstnew(str_lstclear1);
	l_lstclear0->next = l_lstclear1;
	l_lstclear1->next = NULL;
	p_lstclear = &l_lstclear0;
	ft_lstclear(p_lstclear, ft_del);
	printf("p_lstclear a = 0x0\n");
	printf("p_lstclear o = %p\n", *p_lstclear);

	/*
		ft_lstiter
	*/
	printf("---lstiter---\n");
	char *str_lstiter0 = malloc(4);
	i = 0;
	while (i < 3)
	{
		str_lstiter0[i] = 'a';
		i++;
	}
	str_lstiter0[i] = '\0';
	t_list	*l_lstiter0 = ft_lstnew(str_lstiter0);
	t_list	*p_lstiter0 = l_lstiter0;
	char *str_lstiter1 = malloc(4);
	i = 0;
	while (i < 3)
	{
		str_lstiter1[i] = 'b';
		i++;
	}
	str_lstiter1[i] = '\0';
	t_list	*l_lstiter1 = ft_lstnew(str_lstiter1);
	l_lstiter0->next = l_lstiter1;
	l_lstiter1->next = NULL;
	ft_lstiter(l_lstiter0, ft_upper_content);
	printf("l_lstiter0->content a = AAA\n");
	printf("l_lstiter0->content o = %s\n", l_lstiter0->content);
	printf("l_lstiter1->content a = BBB\n");
	printf("l_lstiter1->content o = %s\n", l_lstiter1->content);
	/*
		ft_lstmap
	*/
	printf("---lstmap---\n");
	t_list	*p_lstmap0 = ft_lstmap(p_lstiter0, ft_lower_content, ft_del);
	t_list	*p_lstmap1 = p_lstmap0->next;
	printf("l_lstiter0->content a = aaa\n");
	printf("l_lstiter0->content o = %s\n", p_lstmap0->content);
	printf("l_lstiter1->content a = bbb\n");
	printf("l_lstiter1->content o = %s\n", p_lstmap1->content);
	ft_lstclear(&l_lstiter0, ft_del);
	free(l_lstsize0);
	free(l_lstsize0->next);
	return (0);
}

char	ft_test_strmapi(unsigned int i, char c)
{
	return (c + i);
}

void	ft_test_striteri(unsigned int i, char *p)
{
	*p += i;
}

void	ft_del(void* vp)
{
	free(vp);
}

void	ft_upper_content(void* vp)
{
	char	*str;
	str = (char	*)vp;
	while (*str != '\0')
	{
		*str += ('A' - 'a');
		str++;
	}
}

void	*ft_lower_content(void* vp)
{
	char	*str;
	str = (char	*)vp;
	while (*str != '\0')
	{
		*str += ('a' - 'A');
		str++;
	}
	return (vp);
}