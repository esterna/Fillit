/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:34:06 by esterna           #+#    #+#             */
/*   Updated: 2017/04/24 18:05:58 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "libfill.h"

bool		no_pieces(char **pieces, int numPieces)
{
	int i;

	i = 0;
	while (i < numPieces && pieces[i][0] == 'P')
		i++;
	if (i == numPieces)
		return (true);
	return (false);
}

void		removePiece(char **board, char *piece, int index)
{
	char 	p;
	int		s;
	int		i;
	int		k;

	p = 'A' + index;
	s = 0;
	i = 0;
	k = 0;
	while (s < 4)
	{
		while (board[i][k] && board[i][k] != p)
			k++;
		if (!board[i][k])
		{
			i++;
			k = 0;
		}
		else if (board[i][k] == p)
		{
			s++;
			board[i][k] = '.';
			k++;
		}
	}
	piece[0] = 'F';
}

bool		solve(char **board, int *boardSize, char **pieces, int numPieces, int *place)
{
	int i;

	i = 0;
	if (no_pieces(pieces, numPieces))
	{
		displayBoard(board, *boardSize);
		return (true);
	}/*
	else if (numPieces == 1 && *boardSize <= 3)
	{
		if (ft_strcmp(pieces[0], "F.0.1.1.-1.0.1."))
		   (*boardSize)++;
		if (!ft_strcmp(pieces[0], "F.0.1.0.1.0.1.") || !ft_strcmp(pieces[0], "F.1.0.1.0.1.0."))
			(*boardSize)++;
		pieceFits(board, *boardSize, pieces[i], place);
		addPiece(board, pieces[i], i, place);
		displayBoard(board, *boardSize);
		return (true);
	}*/
	else if (numPieces > 1 && *boardSize == 2)
		(*boardSize)++;
	while (i != numPieces)
	{
		if (pieceFits(board, *boardSize, pieces[i], place))
		{
			addPiece(board, pieces[i], i, place);
			if (solve(board, boardSize, pieces, numPieces, place))
				return (true);
			removePiece(board, pieces[i], i);
		}
		i++;
		if (count_dots(board, *boardSize) <= 4  && i == numPieces)
		{
			(*boardSize)++;
			i = 0;
			while (i < numPieces)
			{
				pieces[i][0] = 'F';
				i++;
			}
			while (i < BOARD_SIZE)
			{
				memset(board[i], (int)'.', BOARD_SIZE);
				i++;
			}	
			i = 0;
		}
		displayBoard(board, *boardSize);
		ft_putchar('\n');
	}
	return (false);
}
