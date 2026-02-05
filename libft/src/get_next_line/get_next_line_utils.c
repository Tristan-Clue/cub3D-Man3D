/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:12:43 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 19:12:26 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "get_next_line.h"

/* Check to see if previous buffer has a complete line
 */
int	has_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str++ == '\n')
			return (true);
	}
	return (false);
}

/* Extract a line from tmp and return it.
 * After extracting, shift the remaining char to the front of str.
 */
void	*extract_buffer(char *str)
{
	char	*host;
	int		len;
	int		i;
	int		start;

	len = 0;
	while (str[len] != '\n')
		len++;
	host = malloc(sizeof(char) * (len + 2));
	if (!host)
		return (NULL);
	i = 0;
	while (i < len)
	{
		host[i] = str[i];
		i++;
	}
	host[i++] = '\n';
	host[i] = '\0';
	start = 0;
	while (str[i])
		str[start++] = str[i++];
	str[start] = '\0';
	return (host);
}

/* Parse the non newline ended, null terminated src string into dest,
 * then free src.
 * Basically a modified ft_strdup.
 */
char	*string_transfer(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (!i)
		return (NULL);
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* Join host and buffer together into a new malloc string and return it.
 * Host will be freed after parsing to new_host.
 */
char	*join_host_buffer(char *host, char *buffer, int rbytes)
{
	int		i;
	int		j;
	char	*new_host;

	i = 0;
	while (host[i])
		i++;
	new_host = malloc(sizeof(char) * (i + rbytes + 1));
	if (!new_host)
		return (NULL);
	j = i;
	while (j-- > 0)
		new_host[j] = host[j];
	j = 0;
	while (j < rbytes && buffer[j] != '\n')
		new_host[i++] = buffer[j++];
	if (j < rbytes)
		new_host[i++] = buffer[j++];
	new_host[i] = '\0';
	i = 0;
	while (j < rbytes)
		buffer[i++] = buffer[j++];
	buffer[i] = '\0';
	return (free(host), new_host);
}

/* Read fd and combine host(if there's any from previous g_n_line call) with
 * buffer until end of first line into new_host.
 * If host is NULL, malloc an empty string into host.
 *
 * Leftover characters gets shifted to the front and stays in buffer to be
 * processed by extract_buffer or string_transfer in the next g_n_line call.
 *
 * When end of file has been reached (0 rbytes), free host(empty string or NULL)
 * then return NULL.
 *
 * If incomplete line is found after read, line will be transferred from
 * new_host back to a freed buffer.
 */
char	*read_fd(char *host, char *buffer, int fd)
{
	int		rbytes;
	char	*new_host;

	rbytes = read(fd, buffer, BUFFER_SIZE);
	if (rbytes <= 0)
		return (host);
	if (!host)
	{
		host = malloc(sizeof(char) * 1);
		if (!host)
			return (NULL);
		host[0] = '\0';
	}
	new_host = join_host_buffer(host, buffer, rbytes);
	if (!new_host)
		return (NULL);
	if (!has_newline(new_host))
	{
		host = string_transfer(new_host);
		free(new_host);
		new_host = read_fd(host, buffer, fd);
	}
	return (new_host);
}
