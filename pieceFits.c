/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieceFits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:37:37 by esterna           #+#    #+#             */
/*   Updated: 2017/04/08 22:59:37 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int			nextNum(char **str)
{
	while (ft_isdigit(*str) && **str)
		(*str)++;
	while (!ft_isdigit(*str) && **str)
		(*str)++;
	return (ft_atoi(*str));
}

bool				pieceFits(char *board, int boardSize, char *piece)
{
	int i;
	char *p_tmp;

	i = 0;
	p_tmp = piece;
	if (!*piece || !piece)
		return (false);
	while (*board)
	{
		while (i < boardSize && *board != '.')
			board++;
		if (i == boardSize)
			i = 0;
		else
		{
			if (*(board + (ft_atoi(p_tmp) * (boardSize / 4)) + (boardSize % 4)) == '.'
					&& *(board + (nextNum(&p_tmp) * (boardSize / 4)) + (boardSize % 4)) == '.' 
					&& *(board + (nextNum(&p_tmp) * (boardSize / 4)) + (boardSize % 4)) == '.')
				return (true);
			p_tmp = piece;
			board++;
		}
	}
	return (false);
}
