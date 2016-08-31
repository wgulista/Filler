#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"

typedef struct 		s_point
{
	int				x;
	int 			y;
}					t_point;

typedef struct  	s_player
{
	int 			got;
	t_point			*pos;
}					t_player;

typedef struct 		s_piece
{
	char 			*piece;
	t_point			*size;
}					t_piece;

typedef struct 		s_env
{
	t_player 		*p1;
	t_player 		*p2;
	t_point 		*map;
}					t_env;

void				init_env(t_env *e);
void				delete_env(t_env *e);

#endif