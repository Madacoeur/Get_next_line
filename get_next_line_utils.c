/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamroun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:36:52 by aamroun           #+#    #+#             */
/*   Updated: 2025/12/17 23:20:18 by aamroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strdup(const char *src)
{
	int		i;
	char	*p;

	i = 0;
	while (src[i])
	{
		i++;
	}
	p = (char *)malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = (j = -1);
	if (!s1)
	{
		s1 = ft_strdup(s1);
		if (!s1)
			return (NULL);
	}
	if (!s2)
		return (free((char *)s1), (NULL));
	dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (free((char *)s1), NULL);
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	return (free((char *)s1), dest);
}


char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;
	unsigned int	j;

	j = ft_strlen(s);
	if (start > j)
		return (ft_strdup(""));
	if (len > j - start)
		len = j - start;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		else
			i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "bonjour je";
	str2 = "suis Adam blabla";
	printf("%s", ft_strjoin(str1, str2));
	return (0);
}*/
