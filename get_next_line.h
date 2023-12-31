/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:56:06 by midbella          #+#    #+#             */
/*   Updated: 2023/12/14 16:04:43 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 37
# endif

char	*reserver(char *buff);
char	*scaner(int fd, char *prev_line);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
int		new_line_check(char *buff);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_the_line(char *buff);
void	ft_bzero(void *s, size_t n);

#endif