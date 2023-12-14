/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:22:59 by midbella          #+#    #+#             */
/*   Updated: 2023/12/13 20:23:44 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
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