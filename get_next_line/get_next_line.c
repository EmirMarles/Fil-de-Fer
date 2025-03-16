/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:17:06 by emarles           #+#    #+#             */
/*   Updated: 2025/02/16 16:52:06 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fft_strdup(char *s);
char	*fft_strjoin(char *s1, char *s2);
size_t	fft_strlen(char *s);
char	*fft_strchr(char *str, int search_str);
char	*get_line(char *s);
char	*storage_update(char *storage);

char	*get_line(char *s)
{
	size_t	i;
	char	*line;

	if (!s || !*s)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] && s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*combine(char *s1, char *temp_buffer)
{
	char	*res;

	if (!s1 && !temp_buffer)
		return (NULL);
	if (!s1)
		return (fft_strdup(temp_buffer));
	if (!temp_buffer)
		return (fft_strdup(s1));
	res = fft_strjoin(s1, temp_buffer);
	free(s1);
	return (res);
}

char	*free_everything(char *storage, char *temp_buffer)
{
	free(storage);
	free(temp_buffer);
	return (NULL);
}

char	*reading(int fd, char *storage)
{
	char	*temp_buffer;
	int		bytes_read;

	if (!storage)
		storage = fft_strdup("");
	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buffer)
		return (free_everything(storage, NULL));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_everything(storage, temp_buffer));
		temp_buffer[bytes_read] = '\0';
		storage = combine(storage, temp_buffer);
		if (fft_strchr(temp_buffer, '\n'))
			break ;
	}
	free(temp_buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = reading(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = storage_update(buffer);
	return (line);
}
