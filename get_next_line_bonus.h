/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrodri <julrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:52:31 by julrodri          #+#    #+#             */
/*   Updated: 2021/10/30 22:28:23 by julrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_next_line_aux(int fd, char **mem);
char	*ft_add_mem(char **mem);
void	ft_add_to_line(char **line, char **mem, char *buffer);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
