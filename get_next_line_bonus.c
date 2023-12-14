/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:15:00 by midbella          #+#    #+#             */
/*   Updated: 2023/12/14 15:40:23 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	new_line_check(char *buff)
{
	int	i;

	i = 0;
	if (buff == NULL)
		return (0);
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_the_line(char *buff)
{
	int		i;
	char	*res;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
	{
		res = malloc(sizeof(char) * i + 1);
		if (!res)
			return (NULL);
	}
	else
	{
		res = malloc(sizeof(char) * i + 2);
		if (!res)
			return (NULL);
		res[i + 1] = '\0';
	}
	while (i >= 0)
	{
		res[i] = buff[i];
		i--;
	}
	return (res);
}

char	*scaner(int fd, char *comb)
{
	char	*buff;
	ssize_t	len;

	len = BUFFER_SIZE;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (free(comb), NULL);
	ft_bzero(buff, (size_t)BUFFER_SIZE + 1);
	while (!new_line_check(comb))
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len <= 0)
			break ;
		comb = ft_strjoin(comb, buff);
		ft_bzero(buff, BUFFER_SIZE + 1);
	}
	free (buff);
	if (len == -1)
		return (free(comb), NULL);
	return (comb);
}

char	*reserver(char *buff)
{
	char	*res;
	int		i;
	int		y;

	y = 0;
	i = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	if (buff[i] == '\0' || (buff[i] == '\n' && buff[i + 1] == '\0'))
		return (free(buff), NULL);
	i++;
	while (buff[i++] != '\0')
		y++;
	i--;
	res = malloc(sizeof(char) * y + 1);
	if (!res)
		return (free(buff), NULL);
	while (y >= 0)
		res[y--] = buff[i--];
	return (free(buff), res);
}

char	*get_next_line(int fd)
{
	static char	*readed_bytes[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	if (!new_line_check(readed_bytes[fd]))
		readed_bytes[fd] = scaner(fd, readed_bytes[fd]);
	if (!readed_bytes[fd])
		return (NULL);
	line = get_the_line(readed_bytes[fd]);
	if (!line)
	{
		free(readed_bytes[fd]);
		readed_bytes[fd] = NULL;
		return (NULL);
	}
	readed_bytes[fd] = reserver(readed_bytes[fd]);
	return (line);
}
