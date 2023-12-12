/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:20:51 by midbella          #+#    #+#             */
/*   Updated: 2023/12/11 22:07:19 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	new_line_check(char *buff, int max_len)
{
	int	i;

	i = 0;
	while (i < max_len)
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
		res = malloc(sizeof(char) * i + 1);
	else
	{
		res = malloc(sizeof(char) * i + 2);
		res[i + 1] = '\0';
	}
	if (!res)
		return (NULL);
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
	int		len;
	int		temp;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	ft_bzero(buff, BUFFER_SIZE + 1);
	len = read(fd, buff, BUFFER_SIZE);
	comb = ft_strjoin(comb, buff);
	while (new_line_check(comb, ft_strlen(comb)) == 0 && len > 0)
	{
		temp = len;
		len += read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = '\0';
		if (temp == len)
			break ;
		comb = ft_strjoin(comb, buff);
	}
	free(buff);
	if (len < 0)
		return NULL;//fee comb
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
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
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
	free(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	
	static char	*readed_bytes;
	char		*line;
	//printf("START: the svar in the of the function is equal to |%s|\n", readed_bytes);

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!readed_bytes || !new_line_check(readed_bytes, ft_strlen(readed_bytes)))
		readed_bytes = scaner(fd, readed_bytes);
	if (!readed_bytes)
		return (NULL);
	line = get_the_line(readed_bytes);
	if (!line)
		return (NULL);
	readed_bytes = reserver(readed_bytes);
	
	//printf("END: the svar in the of the function is equal to |%s|\n", readed_bytes);
	return (line);
}

#include <fcntl.h>
int main()
{
	int fd = open("to_read_write.txt", O_RDWR, 0666);
	char *res;
	int i = 0;
	while (i < 4)
	{
		res = get_next_line(fd);
		printf("%s", res);
		i++;
	}
	free(res);
	close(fd);
}