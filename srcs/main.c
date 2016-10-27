/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:38:03 by wgulista          #+#    #+#             */
/*   Updated: 2016/10/21 03:12:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int					get_fighter(t_env *e, char **av)
{
	char			*line;

	if (!get_next_line(0, &line))
		return (0);
	if (!ft_strcmp(av[0], line))
		return (0);
	if (line != NULL)
	{
		e->player = (line[10] == '1' ? 'O' : 'X');
		e->ennemy = (line[10] == '1' ? 'X' : 'O');
		return (1);
	}
	return (0);
}

static int			print_coord(t_env *e)
{
	if (e->solver.x == 0 && e->solver.y == 0)
	{
		ft_putendl_fd("0 0", 1);
		return (1);
	}
	ft_putstr_fd(ft_itoa(e->solver.y), 1);
	ft_putchar_fd(' ', 1);
	ft_putendl_fd(ft_itoa(e->solver.x), 1);
	return (1);
}

int					init_img(t_env *e)
{
	if (!(e->win = mlx_new_window(e->mlx, e->map_coord.x * 10, e->map_coord.y * 10, "wgulista.filler")))
	{
		ft_putendl("WINDOW CREATION FAIL");
		return (0);
	}
	if (!(e->img.data = mlx_get_data_addr(e->img.img, &(e->img.bpp), &(e->img.sline),
		&(e->img.endian))))
		return (0);
	if (!(e->img.img = mlx_new_image(e->mlx, e->map_coord.x * 10, e->map_coord.y * 10)))
		return (0);
	e->img.depth = (e->img.bpp / 8);
	return (1);
}

static int			start_game(t_env *e)
{
	int				game;

	game = parse_data(e);
	init_img(e);
	create_grid(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	print_coord(e);
	return (1);
}

int					main(int ac, char **av)
{
	static t_env	e;

	(void)ac;
	if (!(e.mlx = mlx_init()))
	{
		ft_putendl("MLX INIT FAIL");
		return (0);
	}
	get_fighter(&e, av);
	mlx_loop_hook(e.mlx, start_game, &e);
	mlx_loop(e.mlx);
	return (0);
}
