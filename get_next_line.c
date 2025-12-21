/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamroun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:41:52 by aamroun           #+#    #+#             */
/*   Updated: 2025/12/20 17:22:39 by aamroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getlinebro(char *stash)
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

char	*ft_solvethatbro(char *stash)
{
	int		i;
	char	*tmp;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0' || stash[i + 1] == '\0')
		return (free(stash), (NULL));
	i++;
	tmp = ft_substr(stash, i, ft_strlen(stash) - i);
	free(stash);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	ssize_t		bytes_read;
	char		*line;

	line = NULL;
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
			return (free(stash), free(buffer), stash = NULL, NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (stash && ft_strchr(stash, '\n'))
			break ;
	}
	if (stash)
		(1 && (line = ft_getlinebro(stash)), (stash = ft_solvethatbro(stash)));
	return (free(buffer), line);
}
