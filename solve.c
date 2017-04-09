/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:34:06 by esterna           #+#    #+#             */
/*   Updated: 2017/04/08 22:59:41 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

char		**subArray(char **pieces, int i)
{
	free(pieces[i]);
	pieces[i] = NULL;
	return (pieces);
}

bool		solve(char *board, int boardSize, char **pieces, int numPieces)
{
	int i;

	if (numPieces == 0)
	{
		displayBoard(board, boardSize);
		return (true);
	}
	if (numPieces == 1 && boardSize <= 3)
	{
		if (ft_strcmp(pieces[0], "1.4.5"))
		   board++;
		if (!ft_strcmp(pieces[0], "1.2.3") || !ft_strcmp(pieces[0], "4.8.12"))
			board++;
		addPiece(board, boardSize, pieces[i], i);
		displayBoard(board, boardSize);
		return (true);
	}
	if (numPieces > 1 && boardSize < 4)
		boardSize == 4;
	i = 0;
	while (i <= numPieces)
	{
		if (pieceFits(board, boardSize, pieces[i]))
		{
			if (Solve(addPiece(board, boardSize, pieces[i], i),
						boardSize, subArray(pieces, i), numPieces - 1))
				return (true);
		}
		i++;
		if (i == numPieces)
		{
			boardSize++;
			i = 0;
		}
	}
	return (false);
}
