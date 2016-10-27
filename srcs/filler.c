/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:37:47 by wgulista          #+#    #+#             */
/*   Updated: 2016/10/20 15:26:23 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				is_overlap(t_env *e, t_point m)
{
	int			overlap;
	t_point		p;
	t_point		tmp;

	overlap = 0;
	p.y = -1;
	while (++p.y < e->piece_coord.y && (p.x = -1))
	{
		while (++p.x < e->piece_coord.x)
		{
			if (e->piece[p.y][p.x] == '*')
			{
				tmp = set_point(p.x + m.x, p.y + m.y);
				if (limit_cross_map(e, tmp.x, tmp.y) ||
						is_ennemy(e, e->map[tmp.y][tmp.x]))
					return (0);
				else if (is_player(e, e->map[tmp.y][tmp.x]))
					if (++overlap > 1)
						return (0);
			}
		}
	}
	if (overlap == 1)
		return (1);
	return (0);
}

int				play_the_filler(t_env *e)
{
	t_point		p;

	p.y = -1;
	while (++p.y < e->map_coord.y && (p.x = -1))
	{
		while (++p.x < e->map_coord.x)
		{
			if (is_overlap(e, p))
			{
				e->solver = set_point(p.x, p.y);
				return (1);
			}
		}
	}
	return (0);
}
