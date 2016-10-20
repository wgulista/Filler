/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:27:43 by wgulista          #+#    #+#             */
/*   Updated: 2016/10/20 15:29:00 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_piece
{
	t_point			pts;
	int				dist;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_env
{
	char			player;
	char			ennemy;
	t_point			map_coord;
	char			**map;
	t_point			piece_coord;
	char			**piece;
	t_point			solver;
}					t_env;

int					limit_cross_map(t_env *e, int x, int y);
int					limit_cross_piece(t_env *e, int x, int y);
int					is_player(t_env *e, char c);
int					is_ennemy(t_env *e, char c);

int					ft_abs(int num);
int					ft_sqrt(int num);
int					hypothenus(t_point a, t_point b);

int					delete_env(t_env *e);
t_point				set_point(int x, int y);
void				free_tab(char **tab);
void				print_color_map(t_env *e);

int					parse_data(t_env *e);

t_piece				*set_piece(int x, int y);
void				add_to_list(t_piece **pieces, t_piece *new);

int					filler(t_env *e, t_piece *pieces);
int					flood_fill(t_env *e, t_piece *pieces);

int					play_the_filler(t_env *e);
#endif
