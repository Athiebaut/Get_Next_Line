/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:47:18 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/25 15:47:20 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * ft_strlen - Calculates the length of a null-terminated string.
 * 
 * @str: The string whose length is to be calculated. If the string is NULL,
 *       the function returns 0.
 * 
 * Return: The length of the string (number of characters before the null
 *         terminator). Returns 0 if the input string is NULL.
 */
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * This function searches for the first occurrence of the character `c` 
 * (converted to a char) in the string `s`. If the character is found, 
 * a pointer to the first occurrence of the character in the string is returned.
 * If the character is not found, or if the input string `s` is NULL, the function 
 * returns NULL. If `c` is the null terminator ('\0'), a pointer to the end of 
 * the string is returned.
 *
 * @param s The string to be searched. If NULL, the function returns NULL.
 * @param c The character to search for, passed as an int but converted to a char.
 * 
 * @return A pointer to the first occurrence of the character in the string, 
 *         or NULL if the character is not found or the input string is NULL.
 */
char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

/**
 * ft_strjoin - Concatenates two strings into a newly allocated string.
 * 
 * @s1: The first string. If NULL, it is treated as an empty string.
 * @s2: The second string. Must not be NULL.
 * 
 * This function allocates memory for a new string that is the result of
 * concatenating `s1` and `s2`. If `s1` is NULL, it initializes it as an
 * empty string. The function frees the memory of `s1` before returning
 * the new concatenated string.
 * 
 * Return: A pointer to the newly allocated string containing the concatenation
 *         of `s1` and `s2`. Returns NULL if memory allocation fails or if `s2`
 *         is NULL.
 */
char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((sizeof(char)) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
