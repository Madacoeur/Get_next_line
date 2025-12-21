/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line _bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamroun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:41:52 by aamroun           #+#    #+#             */
/*   Updated: 2025/12/20 17:22:39 by aamroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_getlinebro(char *stash)
{
	size_t	i;
	char	*tmp;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	tmp = ft_substr(stash, 0, i);
	return (tmp);
}

static char	*ft_solvethatbro(char *stash)
{
	int		i;
	char	*tmp;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0' || stash[i + 1] == '\0')
		return (free(stash), (NULL));
	i++;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(stash[fd]), free(buffer), stash[fd] = NULL, NULL);
		buffer[bytes_read] = '\0';
		stash[fd] = ft_strjoin(stash[fd], buffer);
	}
	tmp = ft_substr(stash, i, ft_strlen(stash) - i);
	free(stash);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*buffer;
	ssize_t		bytes_read;
	char		*line;

	line = NULL;
	bytes_read = 1;
	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	if (ft_strchr(stash[fd], '\n'))
		break ;
	if (stash[fd])
		line = ft_getlinebro(stash[fd]);
		stash[fd] = ft_solvethatbro(stash[fd]);
	return (free(buffer), line);
}
