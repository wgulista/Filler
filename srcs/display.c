#include "../includes/filler.h"

static void	pixel_put_to_img(t_env *e, int x, int y, t_color *c)
{
	int		pos;

	pos = ((y * e->img.sline) + (x * e->img.depth));
	if (e->img.endian)
	{
		e->img.data[pos] = mlx_get_color_value(e->mlx, c->r);
		e->img.data[pos + 1] = mlx_get_color_value(e->mlx, c->g);
		e->img.data[pos + 2] = mlx_get_color_value(e->mlx, c->b);
	}
	else
	{
		e->img.data[pos] = mlx_get_color_value(e->mlx, c->b);
		e->img.data[pos + 1] = mlx_get_color_value(e->mlx, c->g);
		e->img.data[pos + 2] = mlx_get_color_value(e->mlx, c->r);
	}
}

static void	set_color(int r, int g, int b, t_color *c)
{
	c->r = r;
	c->g = g;
	c->b = b;
}

static void	create_cell(t_env *e, t_point p)
{
	t_point	pos;
	t_point	square;

	pos.x = p.x * 10;
	pos.y = p.y * 10;
	square.x = p.x + 10;
	square.y = p.y + 10;
	while (++pos.y < square.y && (pos.x = square.x - 10))
	{
		while (pos.x < square.x)
		{
			if (e->map[pos.y][pos.y] == '.')
			{
				set_color(51, 102, 153, e->c);
				pixel_put_to_img(e, pos.x, pos.y, e->c);
			}
			else if (e->map[pos.y][pos.y] == 'O' || e->map[pos.y][pos.y] == 'o')
			{
				set_color(102, 255, 153, e->c);
				pixel_put_to_img(e, pos.x, pos.y, e->c);
			}
			else if (e->map[pos.y][pos.y] == 'X' || e->map[pos.y][pos.y] == 'x')
			{
				set_color(153, 102, 255, e->c);
				pixel_put_to_img(e, pos.x, pos.y, e->c);
			}
		}
	}
}

int			create_grid(t_env *e)
{
	t_point	p;

	p.y = -1;
	while (++p.y < e->map_coord.y && (p.x = -1))
		while (++p.x < e->map_coord.x)
			create_cell(e, p);
	return (0);
}
