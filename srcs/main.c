/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:38:03 by wgulista          #+#    #+#             */
/*   Updated: 2016/10/20 15:25:34 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int					get_fighter(t_env *e)
{
	char			*line;
	char			**fighter;

	if (get_next_line(0, &line) < 0)
		return (0);
	fighter = ft_strsplit(line, ' ');
	if (ft_strcmp(fighter[2], "p1") == 0)
	{
		e->player = 'O';
		e->ennemy = 'X';
	}
	else
	{
		e->player = 'X';
		e->ennemy = 'O';
	}
	free(line);
	return (1);
}

static int			print_coord(t_env *e)
{
	ft_putstr_fd(ft_itoa(e->solver.y), 1);
	ft_putchar_fd(' ', 1);
	ft_putendl_fd(ft_itoa(e->solver.x), 1);
	return (1);
}

int					main(void)
{
	static t_env	e;
	int				game_loop;

	game_loop = 1;
	get_fighter(&e);
	while (game_loop)
	{
		game_loop = parse_data(&e);
		print_coord(&e);
		delete_env(&e);
	}
	return (0);
}
