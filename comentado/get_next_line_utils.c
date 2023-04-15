/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:41:51 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/03/06 15:57:17 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	// If c is null returns the pointer to the end of the array
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	// If s is not null, point the first c occurrence
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	// If c is not found return null
	return (0);
}
 
char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	// If left_str is null assigns malloc(1) with a null character
	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	// If buff or left_str is null retunrs null
	if (!left_str || !buff)
		return (NULL);
	// Allocate a memory block of size of both strings combined plus 1 for the null character
	// returns null if cant allocate the memory
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	// Copy the left_str to the new string
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	// Copy the buff to the new string
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	// Add the null character to the end of the new string
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

//
char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	// Returns null if left_str is null
	if (!left_str[i])
		return (NULL);
	// Counts the number of characters until the first new line('/n') or the end of the string
	while (left_str[i] && left_str[i] != '\n')
		i++;
	// Allocates memory for the new string plus 2 for new line caracter('/n) and the null termination
	str = (char *)malloc(sizeof(char) * (i + 2));
	// Returns null if malloc fails
	if (!str)
		return (NULL);
	i = 0;
	// Copy the left_str to the new string
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	// Searche the position for newline and add '/n' to the end of the new string
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	// Finds the end of the string or '/n'
	while (left_str[i] && left_str[i] != '\n')
		i++;
	// If the end of the string is reached returns null and free the memory
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	// Allocates memory for the new string plus 1 for the null termination
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	// Copies the remaining portion of left_str after the first '/n'
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	// Frees the memory and retunrs the pointer to str
	free(left_str);
	return (str);
}
