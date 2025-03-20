/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:14:50 by athiebau          #+#    #+#             */
/*   Updated: 2023/05/25 16:14:52 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
 * (converted to a `char`) in the string `s`. The terminating null byte
 * ('\0') is considered part of the string, so if `c` is '\0', the function
 * will return a pointer to the null terminator of the string.
 *
 * @param s The string to be searched. If `s` is NULL, the function returns 0.
 * @param c The character to locate in the string.
 * 
 * @return A pointer to the first occurrence of the character `c` in the
 * string `s`, or NULL if the character is not found.
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
 * empty string. The memory allocated for `s1` is freed before returning
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
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
