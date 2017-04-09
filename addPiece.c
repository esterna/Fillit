/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addPiece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 12:04:46 by esterna           #+#    #+#             */
/*   Updated: 2017/04/08 22:49:45 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*addPiece(char *board, int boardSize, char *piece, int p_order)
{
	int i;
	char *p_tmp;
	char *b_tmp;
	char #;

	i = 0;
	p_tmp = piece;
	b_tmp = board;
	# = 'A' + p_order;
	while (*board)
	{
		while (i < boardSize && *board != '.')
		{
			board++;
			i++;
		}
		if (i == boardSize)
			i = 0;
		else if (boardSize == 2 || boardSize == 3)
		{
			p_tmp = piece;
			*board = #;
			*(board + ft_atoi(p_tmp)) = #;
			*(board + nextNum(&p_tmp)) = #;
			*(board + nextNum(&p_tmp)) = #;
			return (b_tmp);
		}
		else
		{
			if (board + (ft_atoi(p_tmp) * (boardSize / 4)) + (boardSize % 4) == '.'
					&& board + (nextNum(&p_tmp) * (boardSize / 4)) + (boardSize % 4) == '.'
					&& board + (nextNum(&p_tmp) * (boardSize / 4)) + (boardSize % 4) == '.')
			{
				p_tmp = piece;
				*board = #;
				*(board + (ft_atoi(p_tmp) * (boardSize / 4)) + (boardSize % 4)) = #;
				*(board + (nextNum(&p_tmp) * (boardSize / 4)) + (boardSize % 4)) = #;
				*(board + (nextNum(&p_tmp) * (boardSize / 4)) + (boardSize % 4)) = #;
				return (b_tmp);
			}
			p_tmp = piece;
			board++;
		}
	}
}
