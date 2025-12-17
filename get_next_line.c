/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamroun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:41:52 by aamroun           #+#    #+#             */
/*   Updated: 2025/12/17 23:30:03 by aamroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*ft_getlinebro(char *stash)
{
	size_t	i;
	char	*tmp;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	i++;
	tmp = ft_substr(stash, 0, i);
	return (tmp);
}
char	*ft_solvethatbro(char *stash)
{
	int	i;
	int	j;
	char	*tmp;

	i = (j = 0);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		return (free(stash), (NULL));
	else if (stash[i] == '\n')
	{
		i++;
		tmp = malloc((ft_strlen(stash) - i + 1) * sizeof(char));// on reserve juste la taille pour accueillir assez de place du /n a la fin du buffer.
		if (!tmp)
			return (NULL);
		while (stash[i])
			tmp[j++] = stash[i++];
	}
	stash = ft_strdup(tmp);
	return (stash); // donc la on a fait le cas ou /n est atteint et on remet la stash au point de depart(avec les characteres apres le \n) pour qu elle s en rappelle et on free le buffer.
}

char *get_next_line(int fd)
{
	static char	*stash;
	char	*buffer;
	ssize_t	bytes_read;
	char	*line;

	bytes_read = 1;
	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(stash, '\n'))
			break;
	}
	if (bytes_read > 0)
	{
		line = ft_getlinebro(stash);
		stash = ft_solvethatbro(stash);
	}
	return (free(buffer), line);
}

int	main(void)
{
	// char	buffer[100000] = "Bonjour Adam je suis ton buffer d'aujourdhui";
	// ssize_t bytes_read;
	int	fd;
	char	*line;
	int		i = 0;

	fd = open("get_next_line.c", O_RDONLY);
	if (fd == -1)
		return (1);
/*
//buffer = "Bonjour Adam je suis ton buffer d'aujourdhui";
bytes_read = read(fd, buffer, 7000);
if (fd == -1)
	return(1);
buffer[bytes_read] = '\0';

printf("le fd est le numero: %d", fd);
*/
	/*
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	*/

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	return 0;
}
/*
int	ft_truc()
{
	if ((fd == -1) || (buffer == NULL) || (nbyte <= 0))
		return (0);

}
*/
