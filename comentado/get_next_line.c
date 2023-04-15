/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:42:06 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/03/06 17:57:57 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	// Allocates memory to read the data from the fd. retunrs null iif fails
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	// Reads data until '/n'
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		// Reads data from the fd and returns the number of bytes read
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		// Adds the data to left_str until '/n' is found
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	// Frees memory and retunrs the string
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	// Return NULL if the file descriptor is invalid or the buffer size is non-positive
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	// Read from the file descriptor and append to the leftover string
	left_str = ft_read_to_left_str(fd, left_str);
	// If the leftover string is NULL, return NULL
	if (!left_str)
		return (NULL);
	// Extract a line from the leftover string
	line = ft_get_line(left_str);
	// Update the leftover string to remove the line that was just extracted
	left_str = ft_new_left_str(left_str);
	// Return the line that was extracted
	return (line);
}


/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
