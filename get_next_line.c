/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrodri <julrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:50:34 by julrodri          #+#    #+#             */
/*   Updated: 2021/09/28 14:21:13 by julrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int fd;
	char 	*o;

	fd = open("ola.txt", O_RDONLY);
	o = get_next_line(fd);
	printf("%s", o);
	o = get_next_line(fd);
	printf("%s", o);
	free(o);
}

void	ft_lsttochar(char **s, t_list *header, int *i)
{
	t_list	*temp;
	int		j;
	
	if (ft_lstsize(header) == 0)
		return;
	temp = header;
	while (temp->next != 0)
	{
		j = 0;
		while(((char*)temp->content)[j] != '\0')
		{
			(*s)[*i] = ((char*)temp->content)[j];
			(*i)++;
			j++;
		}
		temp = temp->next;
	}
	j = 0;
	while(((char*)temp->content)[j] != '\0')
	{
		(*s)[*i] = ((char*)temp->content)[j];
		(*i)++;
		j++;
	}	
}

char	*ft_strjoin(char *mem, t_list *header, char *buffer)
{
	char	*line;
	int		size;
	int		i;
	int		j;

	j = 0;
	line = malloc(ft_strlen(mem) + ft_strlen(buffer) + BUFFER_SIZE * ft_lstsize(header) + 2);
	if (!line)
		return(0);
	i = 0;
	while (mem != 0 && mem[i] != '\0')
		line[i] = mem[i++];
	ft_lsttochar(&line, header, &i);
	while (buffer[j] != '\n' && buffer[j] != '\0')
		line[i + j] = buffer[j++];
	if (buffer[j] == '\n')
		line[i + j++] = '\n';
	line[i + j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char    *buffer;
	char    *line;
	static char *mem;
	t_list	*header;
	int		i;
	
	header = 0;
	if(!(ft_strchr(mem, '\n')))
	{
		buffer = calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buffer) 
			return(0); 
		while(read(fd, buffer, BUFFER_SIZE) != 0)
		{
			buffer[BUFFER_SIZE] = '\0';
			if(!(ft_strchr(buffer, '\n')) && ft_strlen(buffer) == BUFFER_SIZE)
			{
				ft_lstadd_back(&header, ft_lstnew(buffer));
				buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
				if (!buffer) 
					return(0);
			}
			else
				break;
		}
		line = ft_strjoin(mem, header, buffer); 
		free(mem);
		if ((ft_strchr(buffer, '\n')) != 0)
			mem = ft_strdup(ft_strchr(buffer, '\n') + 1);
		free(buffer);
		ft_lstclear(&header, free);
	}
	else
	{
		i = ft_strchr(mem, '\n') - mem;
		line = malloc(i);
		while (i > 0)
			line[i] = mem[i--];
		free(mem);
		if ((ft_strchr(buffer, '\n')) != 0)
			mem = ft_strdup(ft_strchr(buffer, '\n') + 1);
	}
	return(line);
}
