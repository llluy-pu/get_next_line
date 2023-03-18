/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:42:13 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/02/14 11:44:12 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

//-----------------------------------------------------------------------------
// get_next_line.c

/*
Reads lines from a file descriptor, one line at a time.
Read data from the file descriptor and keep track of any partial lines left over
from previous reads. It then extracts complete lines from the combined data,
updates the partial line for future reads,
and returns each complete line as a string.
*/
char	*get_next_line(int fd);

/*
Function reads data from a file descriptor until it finds a newline character
or the end of the file.
It concatenates the read data with any partial line left
over from previous reads, and returns the resulting string. It frees the memory
allocated for the buffer and returns NULL if it
encounters an error while reading.
*/
char	*ft_read_to_left_str(int fd, char *left_str);
//-----------------------------------------------------------------------------
// get_next_line_utils.c

/*
Searches for the first occurrence of a character in a string. The function takes
a pointer to a character array (string) and an integer value that represents the
character to search for. The function returns a pointer to the first occurrence
of the character in the string, or NULL if the character is not found
*/
char	*ft_strchr(char *s, int c);

/*
Concatenates two strings and returns a new string that contains the concatenated
result.
The function takes two pointers to character arrays (strings) as arguments,
left_str and buff. The function returns a pointer to the new concatenated string,
or NULL if there is an error. 
*/
char	*ft_strjoin(char *left_str, char *buff);

/*
Returns the length of a string. The function takes a pointer to a character array
(string) as an argument. The function returns the length of the string.
*/
size_t	ft_strlen(char *s);

/*
Takes a string as input and returns a new string that contains the first line
of the input string. It checks if the input string is empty and then scans the
input string to find the first line, which it copies to a new string.
It adds a newline character (if it exists) and a null terminator
to the new string. Finally, it returns the new string.
*/
char	*ft_get_line(char *left_str);

//-----------------------------------------------------------------------------
// get_next_line_utils2.c

/*
Returns a new string that contains the remaining text in the input string after
the first line has been extracted. It frees the memory allocated for the input
string and returns NULL if the end of the input string has been reached.
*/
char	*ft_new_left_str(char *left_str);

#endif
