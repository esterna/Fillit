/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriTranslator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:34:15 by esterna           #+#    #+#             */
/*   Updated: 2017/04/20 20:08:52 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

/*
char		*trans_g1(char *buf)
{
	if (*(buf + 5) == '#' && *(buf + 10) == '#' && *(buf + 15) == '#')
		return ("1.0.1.0.1.0");
	else if (*(buf + 10) == '#')
	{
		if (*(buf + 11) == '#')
			return ("1.0.1.0.0.1");
		else if (*(buf + 9) == '#')
			return ("1.0.1.0.0.-1");
		else if (*(buf + 6) == '#')
			return ("1.0.0.1.1.-1");
		return ("1.0.0.-1.1.1");
	}
	if (*(buf + 4) == '#' && *(buf + 6) == '#')
		return ("1.0.0.-1.0.2");
	else if (*(buf + 3) == '#')
		return ("1.0.0.-1.0.-1");
	else if (*(buf + 4) == '#')
		return ("1.0.0.-1.1.0");
	else if (*(buf + 7) == '#')
		return ("1.0.0.1.0.1");
	return ("1.0.0.1.1.0");
}

char		*trans_g2(char *buf)
{
	if (*(buf + 1) == '#' && *(buf + 2) == '#' && *(buf + 3) == '#')
		return ("0.1.0.1.0.1");
	else if (*(buf + 2) == '#')
	{
		if (*(buf + 5) == '#')
			return ("1.0.-1.1.0.1");
		else if (*(buf + 6) == '#')
			return ("0.1.1.0.-1.1");
		return ("0.1.0.1.-1.0");
	}
	else
	{
		if (*(buf + 5) == '#')
		{
			if (*(buf + 4) == '#')
				return ("0.1.1.-1.0.-1");
			else if (*(buf + 10) == '#')
				return ("0.1.1.-1.0.-1");
			return ("0.1.1.-1.0.1");
		}
		return (*(buf + 11) == '#' ? "0.1.1.0.1.0" : "0.1.1.0.0.1");
	}
}

char		*translate(char *buf)
{
	while (*buf != '#')
		buf++;
	if (*(buf + 1) != '#')
		return (trans_g1(buf));
	return (trans_g2(buf));
}*/

void		translate_2(char *buf, char *dest)
{
	int i;
	int k1;
	int k2;
	int r;

	i = 0;
	k1 = 0;
	k2 = 0;
	r = 0;
	dest[i++] = 'F';
	dest[i++] = '.';
	while (*buf != '#')
	{
		k1++;
		buf++;
	}
	k2 = k1 + 1;
	buf++;
	while (*buf)
	{
		while (*buf != '\n' && *buf != '#' && *buf)
		{
			buf++;
			k2++;
		}
		if (*buf == '\n')
		{
			r++;
			k2++;
			buf++;
		}
		else
		{
			dest[i++] = r + '0';
			dest[i++] = '.';
			if (r > 0)
			{
				if ((k2 % 5) - (k1 % 5) < 0)
				{
					dest[i++] = '-';
					dest[i++] = ((k1 % 5) - (k2 % 5)) + '0';
				}
				else
					dest[i++] = ((k2 % 5) - (k1 % 5)) + '0';
			}
			else
			{
				if (k2 - k1 < 0)
				{
					dest[i++] = '-';
					dest[i++] = (k1 - k2) + '0';
				}
				else
					dest[i++] = (k2 - k1) + '0';

			}
			dest[i++] = '.';
			k1 = k2;
			r = 0;
			k2++;
			buf++;
		}
	}
	dest[i] = '\0';
}

char		**tetriTranslator(char *file, int numTetri)
{
	int		i;
	int		fd;
	char	*buf;
	/*char	*tmp;*/
	char	**lst;

	i = 0;
	buf = (char *)malloc(sizeof(char) * 21);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(buf);
		return (NULL);
	}
	lst = ft_2dstrnew(numTetri, 17);
	while (read(fd, buf, 21) > 0)
	{
		if (fd == -1)
		{
			free(buf);
			free(lst);
			return (NULL);
		}
		translate_2(buf, lst[i]);
	/*	tmp = translate(buf);
		ft_strcpy2(lst[i], tmp);*/
		i++;
	}
	if (i != numTetri)
	{
		free(buf);
		free(lst);
		return (NULL);
	}
	return (lst);
}
