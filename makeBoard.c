

#include "libft.h"

char		**makeBoard(int size)
{
	int i;
	char **board;

	i = 0;
	board = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		board[i] = (char *)malloc(sizeof(char) * (size + 2));
		board[i][size + 1] = '\0';
		board[i][size] = '\n';
		ft_memset(board[0], (int)'.', size - 1);
		i++;
	}
	board[size] = NULL;
	return (board);
}
