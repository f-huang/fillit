/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:55:59 by asalama           #+#    #+#             */
/*   Updated: 2016/01/09 19:24:31 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		backtracking(t_list *lst, int cote)
{
	int				stop;
	char			**grid;
	t_maillon		*tetris;

	tetris = ((t_maillon*)(lst->content));
	stop = 1;
	while (stop)
	{
		//CREATION tetris (COTE)
		if (!(grid = fresh_map(cote)))
			return (-1);
		while (tetris)
		{
			// IF CHEKC PLACE OK -> CPY MAILLON
			if (!(try_space(grid, tetris, cote)))
			{
				tetris = tetris->next;
				if (tetris == NULL)
					stop = 0;
				// MAILLON SUIV
					// IF tetris = NULL
						//STOP = 0
			}
			else if ((try_space(grid, tetris, cote)) == 2)
			{
				tetris->y++;
				tetris->x = 0;
				//if fin :: tetris -> prev
			}
			else
			{
				tetris->x++;
				if (tetris->x == cote && tetris->y == cote)
				{
					tetris = tetris->prev;
					if (tetris == NULL)
						break ;
					ft_erase(grid, tetris->n_tetris, cote);
					tetris->x++;
					if (tetris->x >= cote)
					{
						tetris->x = 0;
						tetris->y++;
					}
				}
				//IF tetris PREV = NULL
					//BREAK 
				//ERASE MAILLON PREV
				//TRY MAILLON PREC EN DECALANT  ->>> SAVE COORD DU MAILLON DAVANT
			}
		}
		free_map(grid, cote);
		cote++;
		//FREE tetris
		//COTE ++ 
	}
	print_map(grid, cote);
	//PRINT tetris
	return (0);
}














