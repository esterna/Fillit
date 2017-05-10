/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:33:32 by esterna           #+#    #+#             */
/*   Updated: 2017/05/07 21:52:05 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

static int			checkchrs(char *str)
{
	int i;

	i = 0;
	while (*str && (*str == '.' || *str == '#' || *str == '\n'))
	{
		if (*str == '#')
			i++;
		str++;
	}
	if (*str || i != 4)
		return (0);
	return (1);
}

static int			checkrows(char *str)
{
	int i;

	while (*str)
	{
		i = 4;
		while (i > 0 && *str)
		{
			if (*str == '.' || *str == '#')
				str++;
			else
				return (0);
			i--;
		}
		if (*str != '\n')
			return (0);
		if (*(str + 1) == '\n')
			str++;
		str++;
	}
	return (1);
}

static int			checktets(char *str)
{
	int conxs;

	conxs = 0;
	while (*str)
	{
		while (*str == '.' || *str == '\n')
			str++;
		if (*str == '#')
		{
			if (*(str - 1) == '#')
				conxs++;
			if (*(str + 1) == '#')
				conxs++;
			if (*(str + 5) == '#')
				conxs++;
			if (*(str - 5) == '#')
				conxs++;
		}
		str++;
	}
	return (((conxs == 6) || (conxs == 8)) ? 1 : 0);
}

static int			read_loop(int fd)
{
	int		rd;
	int		last;
	int		num_tetri;
	char	*buf;

	num_tetri = 0;
	buf = (char *)malloc(sizeof(char) * (22));
	while ((rd = read(fd, buf, 21)) && rd > 0)
	{
		last = rd;
		buf[rd] = 0;
		if (!checkchrs(buf) || !checkrows(buf) ||
				!checktets(buf) || num_tetri > 26 || fd == -1)
		{
			free(buf);
			return (0);
		}
		num_tetri++;
	}
	free(buf);
	if (last != 20)
		return (0);
	return (num_tetri);
}

int					file_checker(char *filename)
{
	int		fd;
	int		num_tetri;

	num_tetri = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	num_tetri = read_loop(fd);
	if (!num_tetri || num_tetri > 26)
	{
		close(fd);
		return (0);
	}
	if (close(fd) == -1)
		return (0);
	return (num_tetri);
}
