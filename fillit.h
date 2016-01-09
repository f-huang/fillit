/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:53:44 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/09 19:18:24 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdio.h>
# include <string.h>

# define BUF_SIZE 5

typedef struct			s_maillon
{
	char				**tab;
	int					x;				// X ET Y OU LE TETRIS A ETE PLACE
	int					y;				//
	int					ver;
	int					hor;
	char				n_tetris;
	struct s_maillon	*next;			//FONCTION QUI RELIE NEXT ET PREV
	struct s_maillon	*prev;
}						t_maillon;

typedef struct			s_map
{
	int					x;
	int					y;
}						t_map;

/*
** MAP
*/

char					**fresh_map(int cote);
void					fill_with_dots(char **tab, int cote);
void					print_map(char **map, int cote);
int						free_map(char **map, int cote);
int						square_size(size_t nb_tetris);

/*
** CHECK
*/

int						check_diese(char **tab);
int						check_tetris(char **tab);
int						check_file(t_list *lst, t_maillon *adeter, int fd);

/*
** TETRIS
*/

void					put_tetris(t_list *lst, t_maillon tetris);
int						count_tetris(t_list **lst);
void					trim_tetris(char **tab);
int						trim_ho(char **tab, int n);
int						trim_ver(char **tab, int x, int y);

/*
**	BACKTRACK
*/

int						backtracking(t_list *lst, int cote);
int						try_space(char **grid, t_maillon *tetris, int cote);
void					ft_erase(char **map, char c, int cote);





















#endif
