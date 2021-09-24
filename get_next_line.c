/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrodri <julrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:50:34 by julrodri          #+#    #+#             */
/*   Updated: 2021/09/24 14:59:09 by julrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int fd;
	char 	*o;

	fd = open("ola.txt", O_RDONLY);
	o=get_next_line(fd);
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
	char	*r;
	int		size;
	int		i;
	int		j;

	r = malloc(ft_strlen(mem) + ft_strlen(buffer) + BUFFER_SIZE * ft_lstsize(header) + 2);
	if (!r)
		return(0);
	i = 0;
	j = 0;
	while (mem != 0 && mem[i] != '\0')
		r[i] = mem[i++];
	ft_lsttochar(&r, header, &i);
	while (buffer[j] != '\n' && buffer[j] != '\0')
		r[i + j] = buffer[j++];
	r[i + j] = '\n';
	r[i + j + 1] = '\0';
	return (r);
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
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer) 
			return(0); 
		while(read(fd, buffer, BUFFER_SIZE) != 0)
		{
			//read(fd, buffer, BUFFER_SIZE); // o buffer já recebe ali no while? se sim devo tirar essa linha
			buffer[BUFFER_SIZE] = '\0';
			if(!(ft_strchr(buffer, '\n')))
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
		mem = strdup(ft_strchr(buffer, '\n') + 1);
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
		mem = strdup(ft_strchr(mem, '\n') + 1);
	}
	return(line);
}
