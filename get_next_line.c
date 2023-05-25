
#include "get_next_line.h"

static char	*read_and_save(int fd, char *save)
{
	char	*buffer;
	ssize_t	reads;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
    	if (!buffer)
        return (NULL);
	reads = 1;
	while(!ft_strchr(save, '\n') && reads > 0)
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

static char	*save_next_line(char *save)
{
	int	i;
	int	j;
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
		buffer[j] = save[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
	free(save);
	return (buffer);
}

static char	*get_the_line(char *save)
{
	int	i;
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

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	save[fd] = read_and_save(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = get_the_line(save[fd]);
	save[fd] = save_next_line(save[fd]); 
	return (line);
}

int main()
{
	int	fd;
	int	fd2;
	int	fd3;
	char *line = NULL;

	fd = open("text.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	fd3 = open("text3.txt", O_RDONLY);
	//ligne 1
	line = get_next_line(fd);
	printf("sortie 1 : <%s>\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("sortie 2 : <%s>\n", line);
	free(line);
	line = get_next_line(fd3);
	printf("sortie 3 : <%s>\n", line);
	free(line);
	//ligne 2
	line = get_next_line(fd);
	printf("sortie 1 : <%s>\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("sortie 2 : <%s>\n", line);
	free(line);
	line = get_next_line(fd3);
	printf("sortie 3 : <%s>\n", line);
	free(line);
	//ligne 3
	line = get_next_line(fd);
	printf("sortie 1 : <%s>\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("sortie 2 : <%s>\n", line);
	free(line);
	line = get_next_line(fd3);
	printf("sortie 3 : <%s>\n", line);
	free(line);
	//ligne 4
	line = get_next_line(fd);
	printf("sortie 1 : <%s>\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("sortie 2 : <%s>\n", line);
	free(line);
	line = get_next_line(fd3);
	printf("sortie 3 : <%s>\n", line);
	free(line);
	//ligne 5
	line = get_next_line(fd);
	printf("sortie 1 : <%s>\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("sortie 2 : <%s>\n", line);
	free(line);
	line = get_next_line(fd3);
	printf("sortie 3 : <%s>\n", line);
	//ligne 6
	line = get_next_line(fd);
	printf("sortie 1 : <%s>\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("sortie 2 : <%s>\n", line);
	free(line);
	line = get_next_line(fd3);
	printf("sortie 3 : <%s>\n", line);
	//ligne 7
	line = get_next_line(fd);
	printf("sortie 1 : <%s>\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("sortie 2 : <%s>\n", line);
	free(line);
	line = get_next_line(fd3);
	printf("sortie 3 : <%s>\n", line);
	free(line);
	close(fd);
	close(fd2);
	close(fd3);
	return 0;
}