/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:23:08 by midbella          #+#    #+#             */
/*   Updated: 2023/12/14 12:56:02 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str)
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (n > 0)
	{
		ptr[i] = 0;
		i++;
		n--;
	}
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (res == NULL)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*res;
	int		i;
	int		y;

	y = 0;
	i = 0;
	if (s1 == NULL)
		return (ft_strdup(s2));
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (res == NULL)
		return (free(s1), NULL);
	res[ls1 + ls2] = '\0';
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[y] != '\0')
		res[i++] = s2[y++];
	return (free(s1), res);
}
