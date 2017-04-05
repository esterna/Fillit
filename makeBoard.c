/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeBoard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:33:57 by esterna           #+#    #+#             */
/*   Updated: 2017/04/05 12:17:21 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*makeBoard(int size)
{
/*
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
	*/
	int i;
	char *board;
	int s;

	i = 0;
	s = ((size + 1) * (size + 1)) + 1;
	board = (char *)malloc(sizeof(char) * s);
	board[--s] = '\0';
	while (i < s)
	{
		ft_memset(board, (int)'.', size);
		i += size;
		board[i++] = '\n';
	}
}
