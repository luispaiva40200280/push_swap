/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaiva <lpaiva@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:04:53 by lpaiva            #+#    #+#             */
/*   Updated: 2026/01/06 18:58:15 by lpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_update_buff(char *buffer_file)
{
	char			*update_buff;
	unsigned int	i;
	unsigned int	j;

	if (!buffer_file)
		return (NULL);
	i = 0;
	while (buffer_file[i] && buffer_file[i] != '\n')
		i++;
	if (!buffer_file[i] || !buffer_file[i + 1])
		return (free(buffer_file), NULL);
	update_buff = malloc(ft_strlen(buffer_file + i + 1) + 1);
	if (!update_buff)
		return (free(buffer_file), NULL);
	i++;
	j = 0;
	while (buffer_file[i])
		update_buff[j++] = buffer_file[i++];
	update_buff[j] = '\0';
	return (free(buffer_file), update_buff);
}

/*extracts the line for print*/
char	*ft_next_line(char *buffer_file)
{
	char			*line;
	unsigned int	i;

	if (!buffer_file || !buffer_file[0])
		return (NULL);
	i = 0;
	while (buffer_file[i] && buffer_file[i] != '\n')
		i++;
	line = malloc(i + (buffer_file[i] == '\n') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer_file[i] && buffer_file[i] != '\n')
	{
		line[i] = buffer_file[i];
		i++;
	}
	if (buffer_file[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/* read the file in chunks of BUFFFER SIZE */
char	*read_file(int fd, char *buffer_file)
{
	char	*buff_chunks;
	int		bytes_read;

	buff_chunks = malloc(BUFFER_SIZE + 1);
	if (!buff_chunks)
		return (free(buffer_file), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff_chunks, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer_file), free(buff_chunks), NULL);
		if (bytes_read == 0)
			break ;
		buff_chunks[bytes_read] = '\0';
		buffer_file = ft_strjoin_free(buffer_file, buff_chunks);
		if (!buffer_file)
			return (free(buff_chunks), NULL);
		if (ft_strchr(buffer_file, '\n'))
			break ;
	}
	return (free(buff_chunks), buffer_file);
}

char	*get_next_line(int fd)
{
	static char	*buffer_file;
	char		*line_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer_file)
	{
		buffer_file = malloc(1);
		if (!buffer_file)
			return (free(buffer_file), NULL);
		buffer_file[0] = '\0';
	}
	buffer_file = read_file(fd, buffer_file);
	line_read = ft_next_line(buffer_file);
	if (!line_read)
	{
		free(buffer_file);
		buffer_file = NULL;
		return (NULL);
	}
	buffer_file = ft_update_buff(buffer_file);
	return (line_read);
}
