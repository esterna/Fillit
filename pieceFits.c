/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieceFits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:37:37 by esterna           #+#    #+#             */
/*   Updated: 2017/04/24 18:03:10 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "libfill.h"

bool				pieceFits(char **board, int boardSize, char *piece, int *place)
{
	int r;
	int c;
	int t1;
	int t2;
	char *p_tmp;

	r = 0;
	c = 0;
	p_tmp = piece + 2;
	if (*piece == 'P')
		return (false);
	piece += 2;
	while (board[r] && r < boardSize && c < boardSize)
	{
		while (c < boardSize && board[r][c] != '.' && board[r][c])
			c++;
		if (c >= boardSize || !board[r][c])
		{
			c = 0;
			r++;
		}
		else if ((t1 = r + nextNum(&p_tmp)) < boardSize && (t2 = c + nextNum(&p_tmp)) < boardSize
				&& t1 >= 0 && t2 >= 0 && board[t1][t2] == '.'
				&&(t1 = t1 + nextNum(&p_tmp)) < boardSize && (t2 = t2 + nextNum(&p_tmp)) < boardSize
				&& t1 >= 0 && t2 >= 0 && board[t1][t2] == '.'
				&&(t1 = t1 + nextNum(&p_tmp)) < boardSize && (t2 = t2 + nextNum(&p_tmp)) < boardSize
				&& t1 >= 0 && t2 >= 0 && board[t1][t2] == '.')
		{
			place[0] = r;
			place[1] = c;

			return (true);
		}
		else
		{
			p_tmp = piece;
			c++;
		}
	}
	place[0] = 0;
	place[1] = 0;
	return (false);
}
