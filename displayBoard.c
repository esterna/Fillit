/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayBoard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:32:43 by esterna           #+#    #+#             */
/*   Updated: 2017/04/07 14:50:18 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		displayBoard(char *board, int boardSize)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (n < boardSize)
	{
		while (i < boardSize)
		{
			ft_putchar(*board);
			board++;
			i++;
		}
		ft_putchar('\n');
		n++;
		i = 0;
		board = board + (13 - boardSize);
	}
}
