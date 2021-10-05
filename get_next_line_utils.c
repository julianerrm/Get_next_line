/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrodri <julrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:52:18 by julrodri          #+#    #+#             */
/*   Updated: 2021/10/04 09:38:54 by julrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*o;

	fd = open("ola.txt", O_RDONLY);
	o = get_next_line(fd);
	printf("%s", o);
	o = get_next_line(fd);
	printf("%s", o);
	free(o);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != (unsigned char)c && s[i] != '\0')
		i++;
	if (s[i] != (unsigned char)c)
		return (0);
	return ((char *) &s[i]);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(const char *s, size_t size)
{
	char	*r;
	size_t	i;

	if (size == 0 || !s)
		return (0);
	r = malloc((size + 1) * sizeof(char));
	if (!r)
		return (0);
	i = 0;
	while (i < size)
	{
		r[i] = s[i];
		i++;
	}
	r[size] = '\0';
	return (r);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		i;
	int		j;

	if (!s2)
		return (ft_strdup(s1, ft_strlen(s1)));
	if (!s1 && !(ft_strchr(s2, '\n')))
		return (ft_strdup(s2, ft_strlen(s2)));
	if (!s1)
		return (ft_strdup(s2, (size_t)(ft_strchr(s2, '\n') - s2 + 1)));
	r = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!r)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		r[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i] != '\0' && s2[i - 1] != '\n')
	{
			r[j + i] = s2[i];
			i++;
	}
	r[j + i] = '\0';
	return (r);
}
