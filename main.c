/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:33:45 by esterna           #+#    #+#             */
/*   Updated: 2017/04/24 17:15:03 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libfill.h"

int			main(int argc, char **argv)
{
	int 	i;
	int		numTetri;
	int		*place;
	char	**pieces;
	char	**board;
	int		*boardSize;

	i = -1;
	boardSize = (int *)malloc(sizeof(int) * 1);
	*boardSize = 2;
	if (argc != 2)
	{
		ft_putstr("usage: \nfillit file\n");
		return (0);
	}
	argv++;
	numTetri = file_checker(*argv);
	if (!numTetri)
	{
		ft_putstr("error in file_checker\n");
		return (0);
	}
	pieces = tetriTranslator(*argv, numTetri);
	if (!pieces || !*pieces)
	{
		ft_putstr("error in translator\n");
		return (0);
	}
	board = ft_2dstrnew(BOARD_SIZE, BOARD_SIZE); 
	while (++i < BOARD_SIZE)
		memset(board[i], (int)'.', BOARD_SIZE);
	place = (int *)malloc(sizeof(int) * 2);
	solve(board, boardSize, pieces, numTetri, place);
	i = 0;
	while (i < BOARD_SIZE)
	{
		free(board[i]);
		i++;
	}
	free(board);
	i = 0;
	while (i < numTetri)
	{
		free(pieces[i]);
		i++;
	}
	free(place);
	free(boardSize);
	return (0);
}
