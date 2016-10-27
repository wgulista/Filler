/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:27:43 by wgulista          #+#    #+#             */
/*   Updated: 2016/10/20 16:31:26 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct 		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef	struct 		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sline;
	int				endian;
	int				depth;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			img;
	char			player;
	char			ennemy;
	t_point			map_coord;
	char			**map;
	t_point			piece_coord;
	char			**piece;
	t_point			solver;
	t_color			*c;
}					t_env;

int					create_grid(t_env *e);
int					limit_cross_map(t_env *e, int x, int y);
int					limit_cross_piece(t_env *e, int x, int y);
int					is_player(t_env *e, char c);
int					is_ennemy(t_env *e, char c);

int					ft_abs(int num);
int					ft_sqrt(int num);

int					delete_env(t_env *e);
t_point				set_point(int x, int y);
void				free_tab(char **tab);
void				print_color_map(t_env *e);

int					parse_data(t_env *e);

int					play_the_filler(t_env *e);
#endif
