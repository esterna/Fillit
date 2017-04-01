

#include "libft.h"

void		displayBoard(char **board)
{
	while (*board)
	{
		ft_putstr(*board);
		board++;
	}
}
