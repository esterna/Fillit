/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:34:06 by esterna           #+#    #+#             */
/*   Updated: 2017/04/05 11:36:54 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**subArray(char **pieces, int i)
{
	free(pieces[i]);
	pieces[i] = NULL;
	return (pieces);
}

int			boardSize(char *board)
{
	int i;

	i = 0;
	while (*board != '\n')
		i++;
	return (i);
}

bool		solve(char *board, char **pieces, int numPieces)
{
	int i;

	if (numPieces == 0)
	{
		displayBoard(board);
		return (true);
	}
	i = 0;
	while (i <= numPieces)
	{
		if (pieceFits(board, pieces[i], i))
		{
			if (Solve(addPiece(board, pieces[i]), subArray(pieces, i), numPieces - 1))
				return (true);
		}
		i++;
		if (i == numPieces)
		{
			board = makeBoard(boardSize(board) + 1);
			i = 0;
		}
	}
	return (false);
}
