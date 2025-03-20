/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:14:33 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/25 16:14:35 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @brief Reads from a file descriptor and appends the content to a saved string.
 * 
 * This function reads data from the given file descriptor `fd` in chunks of
 * size `BUFFER_SIZE` and appends it to the `save` string. The reading continues
 * until a newline character ('\n') is found in the `save` string or the end of
 * the file is reached. If an error occurs during reading, the function frees
 * the allocated buffer and returns NULL.
 * 
 * @param fd The file descriptor to read from.
 * @param save The string to which the read content will be appended. It may
 *             contain previously read data.
 * 
 * @return A pointer to the updated `save` string containing the appended data,
 *         or NULL if an error occurs during reading or memory allocation.
 * 
 * @note The caller is responsible for freeing the memory allocated for the
 *       `save` string.
 */
static char	*read_and_save(int fd, char *save)
{
	char	*buffer;
	ssize_t	reads;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	reads = 1;
	while (!ft_strchr(save, '\n') && reads > 0)
	{
		reads = read(fd, buffer, BUFFER_SIZE);
		if (reads == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[reads] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

/**
 * save_next_line - Extracts and saves the portion of a string after a newline
 *                  character, freeing the original string.
 *
 * @save: A pointer to the string containing the data to process.
 *        This string is expected to contain a newline character.
 *
 * Return: A newly allocated string containing the portion of the input string
 *         after the first newline character. If no newline is found, or if
 *         memory allocation fails, returns NULL. The original string is freed
 *         in both cases.
 *
 * Note: The caller is responsible for freeing the returned string to avoid
 *       memory leaks.
 */
static char	*save_next_line(char *save)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!buffer)
		return (NULL);
	i++;
	while (save[i])
	{
		buffer[j++] = save[i++];
	}
	buffer[j] = '\0';
	free(save);
	return (buffer);
}

/**
 * @brief Extracts a line from the given string up to and including the first newline character.
 *
 * This function takes a string `save` and extracts a line from it. The line includes all characters
 * up to and including the first newline character (`\n`). If there is no newline character, it extracts
 * all characters until the end of the string. The extracted line is returned as a newly allocated string.
 *
 * @param save The input string from which the line is to be extracted. It is expected to be null-terminated.
 *
 * @return A newly allocated string containing the extracted line, including the newline character if present.
 *         If the input string is empty or memory allocation fails, the function returns NULL.
 *
 * @note The caller is responsible for freeing the memory allocated for the returned string.
 */
static char	*get_the_line(char *save)
{
	int		i;
	char	*buffer;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	buffer = (char *)malloc(i + 2);
	if (!buffer)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		buffer[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		buffer[i] = save[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

/**
 * get_next_line - Reads a line from a file descriptor.
 * @fd: The file descriptor to read from.
 *
 * This function reads a line from the given file descriptor `fd` and returns
 * it as a dynamically allocated string. It uses a static array to keep track
 * of the remaining content for each file descriptor, allowing it to handle
 * multiple file descriptors simultaneously.
 *
 * Return: A pointer to the line read from the file descriptor, or NULL if
 *         an error occurs, the end of the file is reached, or BUFFER_SIZE
 *         is invalid.
 *
 * Note:
 * - The function relies on helper functions `read_and_save`, `get_the_line`,
 *   and `save_next_line` to perform its operations.
 * - The `save` array is used to store the remaining content for each file
 *   descriptor, indexed by the file descriptor number.
 */
char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = read_and_save(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = get_the_line(save[fd]);
	save[fd] = save_next_line(save[fd]);
	return (line);
}
