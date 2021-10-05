/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrodri <julrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:52:18 by julrodri          #+#    #+#             */
/*   Updated: 2021/09/30 08:38:29 by julrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	if(!s)
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
		return(0);
	count = 0;
	while (s[count] != '\0' && s[count] != '\n')
		count++;
	return (count);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new || !lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*r;

	r = malloc(sizeof(t_list));
	if (!r)
		return (0);
	r->content = content;
	r->next = NULL;
	return (r);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*next;

	if (!*lst)
		return ;
	temp = *lst;
	while (temp->next)
	{
		del(temp->content);
		next = temp->next;
		free(temp);
		temp = next;
	}
	del(temp->content);
	free(temp);
	*lst = 0;
}

char	*ft_strdup(const char *s)
{
	char	*r;
	size_t	i;

	r = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!r)
		return (0);
	i = 0;
	while (i <= ft_strlen(s))
	{
		r[i] = s[i];
		i++;
	}
	return (r);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (0);
	r = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!r)
		return (0);
	while (s1[i] != '\0')
	{
		r[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i] != '\0')
	{
		r[j + i] = s2[i];
		i++;
	}
	r[j + i] = '\0';
	return (r);
}