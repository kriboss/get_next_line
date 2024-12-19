/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:04:29 by kbossio           #+#    #+#             */
/*   Updated: 2024/12/01 16:04:33 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>

static char	*free_join(char *buffer, char *text)
{
	char	*ris;

	ris = ft_strjoin(buffer, text);
	free(buffer);
	return (ris);
}

static char	*read_buffer(int fd, char *buffer)
{
	int		len;
	char	*text;

	len = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	text = malloc(BUFFER_SIZE + 1);
	if (!text)
		return (NULL);
	while (len > 0)
	{
		len = read(fd, text, BUFFER_SIZE);
		if (len == -1)
		{
			free(buffer);
			free(text);
			return (NULL);
		}
		text[len] = '\0';
		buffer = free_join(buffer, text);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(text);
	return (buffer);
}

static char	*trim_buffer(char *buffer)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = malloc(ft_strlen(buffer) - i);
	if (!str)
		return (NULL);
	while (buffer[++i])
		str[j++] = buffer[i];
	str[j] = '\0';
	free(buffer);
	return (str);
}

static char	*read_the_line(char *buffer)
{
	int		i;
	char	*res;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	res = malloc(i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		res[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*buffer[OPEN_MAX];

	res = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	buffer[fd] = read_buffer(fd, buffer[fd]);
	if (!buffer[fd] || !*buffer[fd])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	res = read_the_line(buffer[fd]);
	buffer[fd] = trim_buffer(buffer[fd]);
	return (res);
}
	//printf("\nres:%sbuffer:%s\n", res, buffer);
/*
#include <fcntl.h>

int main(){
    
	char* fileName = "text.txt";
	char *buffer;
	int fd = open(fileName, O_RDONLY);

	if (fd < 0)
	{
		printf("Error opening text.txt");
		return (1);
	}

	// Read lines from the file using get_next_line
	printf("Reading from text.txt:\n");
	while ((buffer = get_next_line(fd)) != NULL)
	{
		printf("%s", buffer); // Print the line
		free(buffer);         // Free memory allocated by get_next_line
	}

	// Close the file descriptor
	close(fd);
	return (0);
}
*/
