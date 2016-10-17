#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"

# define ABS(x) (x > 0 ? x : -x)

typedef struct s_point	t_point;
typedef struct s_env		t_env;

struct			s_point
{
	int				x;
	int				y;
};

struct			s_env
{
	char			player;
	char			ennemy;
	t_point		map_coord;
	char			**map;
	t_point		piece_coord;
	char			**piece;
	t_point		solver;
};

void				free_tab(char **tab);
int					length_tab(char **tab);
void				print_tab(char **tab);
void 				print_color_map(t_env *e);
int					hypothenus(t_point a, t_point b);
t_point			set_point(int x, int y);
void 				delete(t_env *e);
void				get_coord_map(t_env *e);
void				get_map(t_env *e);
void				get_coord_piece(t_env *e);
void				get_piece_map(t_env *e);
int      		play_the_filler(t_env *e);

#endif
