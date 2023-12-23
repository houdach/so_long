/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchouai <hchouai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:33:22 by hchouai           #+#    #+#             */
/*   Updated: 2023/12/13 21:16:47 by hchouai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*p;

	if (!s1)
		return (NULL);
	p = (char *)malloc(ft_strlen(s1) + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*rs;
	size_t	i;
	size_t	j;
	size_t	lens;

	i = start;
	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start > lens)
		return (ft_strdup(""));
	else if (len > lens - start)
		len = lens - start;
	rs = (char *) malloc(sizeof(char) * (len + 1));
	if (!rs)
		return (NULL);
	j = 0;
	while (j < len && s[i] != '\0')
	{
		rs[j] = s[i];
		i++;
		j++;
	}
	rs[j] = '\0';
	return (rs);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*rs;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	rs = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rs)
		return (NULL);
	while (s1[i])
		rs[j++] = s1[i++];
	i = 0;
	while (s2[i])
		rs[j++] = s2[i++];
	rs[j] = '\0';
	return (rs);
}
