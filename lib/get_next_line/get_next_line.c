/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:17:26 by jotrujil          #+#    #+#             */
/*   Updated: 2024/02/12 18:35:47 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_free(char *str, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(str, buf);
	free(str);
	return (tmp);
}

char	*ft_next_lines(char *buf)
{
	char	*next_lines;
	int		i;
	int		j;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	if (buf[i] == '\n')
		i++;
	j = 0;
	while (buf[i + j] != '\0')
		j++;
	next_lines = ft_calloc(j + 1, sizeof(char));
	j = 0;
	while (buf[i] != '\0')
	{
		next_lines[j++] = buf[i++];
	}
	free(buf);
	return (next_lines);
}

char	*ft_current_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (buf[i] == '\0')
		return (NULL);
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] != '\0')
		line[i] = '\n';
	return (line);
}

char	*ft_read_fd(int fd, char *str)
{
	char	*local_buffer;
	int		bytes_read;

	if (!str)
		str = ft_calloc(1, 1);
	local_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, local_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(local_buffer);
			free(str);
			return (NULL);
		}
		local_buffer[bytes_read] = '\0';
		str = ft_join_free(str, local_buffer);
		if (ft_strchr(local_buffer, '\n'))
			break ;
	}
	free(local_buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_read_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_current_line(buffer);
	buffer = ft_next_lines(buffer);
	return (line);
}

/* int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
} */