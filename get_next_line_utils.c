/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:11:59 by kbossio           #+#    #+#             */
/*   Updated: 2024/11/28 15:12:00 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	while (*s1)
		ptr[i++] = *s1++;
	while (*s2)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_memset(void *p, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)p;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t	*mem;

	mem = (void *)malloc(num * size);
	if (!mem)
		return (NULL);
	ft_memset(mem, '\0', num * size);
	return (mem);
}

size_t	ft_strlen(const char *str)
{
	size_t		number;

	number = 0;
	while (*str)
	{
		number++;
		str++;
	}
	return (number);
}

char	*ft_strchr(const char *str, int c)
{
	while ((char)c != *str)
	{
		if (!*str)
			return (0);
		str++;
	}
	return ((char *)str);
}
