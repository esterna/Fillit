

#include "libft.h"

char		**subArray(char **pieces, int i)
{
	free(pieces[i]);
	pieces[i] = NULL;
	return (pieces);
}

bool		solve(char **board, char **pieces, int numPieces)
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
			board = makeBoard(ft_strlen(*board));
			i = 0;
		}
	}
	return (false);
}
