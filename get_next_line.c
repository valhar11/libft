/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:27:29 by vlibert           #+#    #+#             */
/*   Updated: 2024/06/15 14:57:01 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_gnl(char *s1, char *s2, int *eol)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	dest = malloc(sizeof(char) * (i + j + 1));
	if (!dest)
		return (free(s1), NULL);
	ft_memcpy(dest, s1, i);
	free(s1);
	ft_memcpy(dest + i, s2, j + 1);
	if (i + j > 0 && *(dest + i + j - 1) == '\n')
		*eol = 0;
	return (dest);
}

static char	*remove_old_line(char *buffer, int *eol)
{
	size_t		len;
	char		*next_line;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	len ++;
	next_line = malloc(sizeof(char) * (len + 1));
	if (!next_line)
		return (NULL);
	ft_memcpy(next_line, buffer, len);
	next_line[len] = '\0';
	if (len > 0 && next_line[len - 1] == '\n')
		*eol = len - 1;
	return (next_line);
}

int	eol_index(char *next_line)
{
	int	i;

	i = 0;
	if (!next_line)
		return (-1);
	while (i < BUFFER_SIZE)
	{
		if (next_line[i] == '\n' || next_line[i] == '\0')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*get_line_gnl(char *next_line, char *save, int *eol, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	count;
	size_t	len;

	while (*eol == -1)
	{
		ft_bzero(buffer, (BUFFER_SIZE + 1));
		count = read(fd, buffer, BUFFER_SIZE);
		if (count <= 0)
		{
			if (count < 0)
			{
				ft_bzero(save, (BUFFER_SIZE + 1));
				return (free(next_line), NULL);
			}
			ft_bzero(save, BUFFER_SIZE + 1);
			return (next_line);
		}
		len = eol_index(buffer);
		ft_strlcpy(save, &buffer[len], (BUFFER_SIZE + 1));
		buffer[len] = '\0';
		next_line = ft_strjoin_gnl(next_line, buffer, eol);
	}
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*next_line;
	int			eol;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	eol = -1;
	next_line = remove_old_line(buffer, &eol);
	if (!next_line)
		return (NULL);
	ft_strlcpy(buffer, &buffer[eol + 1], BUFFER_SIZE + 1);
	next_line = get_line_gnl(next_line, buffer, &eol, fd);
	if (!next_line || next_line[0] == '\0')
		return (free(next_line), NULL);
	return (next_line);
}
