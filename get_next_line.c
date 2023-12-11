/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:20:51 by midbella          #+#    #+#             */
/*   Updated: 2023/12/11 18:23:57 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line_check(char *buff, int max_len)
{
	int	i;

	i = 0;
	while (max_len > 0)
	{
		if (buff[i] == '\n')
			return (1);
		max_len--;
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
		res = malloc(sizeof(char) * i + 1);
	else
	{
		res = malloc(sizeof(char) * i + 2);
		res[i + 1] = '\0';
	}
	if (res == NULL)
		return (NULL);
	while (i >= 0)
	{
		res[i] = buff[i];
		i--;
	}
	return (res);
}

char	*scaner(int fd, char *prev_line)
{
	char	*buff;
	char	*comb;
	int		len;
	int		temp;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	ft_bzero(buff, BUFFER_SIZE + 1);
	comb = prev_line;
	len = 0;
	len += read(fd, buff, BUFFER_SIZE);
	comb = ft_strjoin(comb, buff);
	while (new_line_check(comb, len) == 0 && len % BUFFER_SIZE == 0 && len > 0)
	{
		temp = len;
		len += read(fd, buff, BUFFER_SIZE);
		if (temp == len)
			break ;
		comb = ft_strjoin(comb, buff);
	}
	return (comb);
}

char	*reserver(char *buff)
{
	char	*res;
	int		i;
	int		y;

	if (buff == NULL)
		return (NULL);
	y = 0;
	i = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	i++;
	while (buff[i++] != '\0')
		y++;
	i--;
	res = malloc(sizeof(char) * y + 1);
	if (!res)
		return (NULL);
	while (y >= 0)
	{
		res[y--] = buff[i--];
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*readed_bites;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readed_bites = scaner(fd, readed_bites);
	line = get_the_line(readed_bites);
	readed_bites = reserver(readed_bites);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
// 	int fd = open("to_read_write.txt", O_RDWR, 0666);
// 	char *res;
// 	res = get_next_line(fd);
// 	printf("%s", res);
// 	close(fd);
// }