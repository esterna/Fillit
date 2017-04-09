/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:33:45 by esterna           #+#    #+#             */
/*   Updated: 2017/04/06 13:11:16 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			main(int argc, char **argv)
{
	int	numTetri;
	char **pieces;
	char *board;
	int boardSize;

	if (argc != 2)
	{
		ft_putstr("usage: \nfillit file\n");
	}
	argv++;
	numTetri = file_checker(*argv);
	if (!numTetri)
		return (0);
	pieces = tetriTranslator(*argv, numTetri);
	board = makeBoard();
	boardSize = 2;
	Solve(board, boardSize, pieces, numTetri);
	return (0);
}
