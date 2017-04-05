/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriTranslator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:34:15 by esterna           #+#    #+#             */
/*   Updated: 2017/04/05 12:13:12 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*trans_g1(char *buf)
{
	if (buf + 5 == '#' && buf + 10 == '#' && buf + 15 == '#')
		return ("l");
	else if (buf + 10 == '#')
	{
		if (buf + 11 == '#')
			return ("L");
		else if (buf + 9 == '#')
			return ("bL");
		else if (buf + 6 == '#')
			return ("rT");
		else
			return ("lT");
	}
	else
	{
		if (buf + 4 == '#' && buf + 6 == '#')
			return ("uT");
		else if (buf + 4 == '#')
			return ("2+90");
		else
			return ("s+90");
	}
}

char		*trans_g2(char *buf)
{
	if (buf + 1 == '#' && buf + 2 == '#' && buf + 3 == '#')
		return ("l+90");
	else if (buf + 2 == '#')
	{
		if (buf + 5 == '#')
			return ("L+90");
		else if (buf + 6 == '#')
			return ("T");
		else
			return ("bL-90");
	}
	else
	{
		if (buf + 5 == '#')
		{
			if (buf + 4 == '#')
				return ("s");
			else if (buf + 10 == '#')
				return ("bL+180");
			return ("sq");
		}
		else
			return (buf + 11 == '#' ? "L+180" : "2");
	}
}

char		*translate(char *buf)
{
	char **lst;

	lst = *lstptr;
	while (*buf != '#')
		buf++;
	if (buf + 1 != '#')
		return (trans_g1(buf));
	else
		return (trans_g2(buf));
}

char		**tetriTranslator(char *file, int numTetri)
{
	int		i;
	int		fd;
	char	*buf;
	char	**lst;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error in opening file\n");
		return (NULL);
	}
	lst = (char **)malloc(sizeof(char *) * (numTetri + 1));
	lst[numTetri] = NULL;
	while (lst[i] != NULL)
		lst[i++] = (char *)malloc(sizeof(char) * 7);
	i = 0;
	while (read(fd, buf, 21) == fd)
	{
		if (fd == -1)
		{
			ft_putstr("error in reading file\n");
			return (NULL);
		}
		ft_strcpy(lst[i++], translate(buf));
	}
	if (i + 1 != numTetri)
		ft_putstr("Couldn't find all Tetrimonos.\n");
	return (lst);
}
