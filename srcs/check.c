/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:32:25 by wgulista          #+#    #+#             */
/*   Updated: 2016/10/20 15:18:13 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			limit_cross_map(t_env *e, int x, int y)
{
	if (x < 0 || y < 0 || x >= e->map_coord.x || y >= e->map_coord.y)
		return (1);
	return (0);
}

int			limit_cross_piece(t_env *e, int x, int y)
{
	if (x < 0 || y < 0 || x >= e->piece_coord.x || y >= e->piece_coord.y)
		return (1);
	return (0);
}

int			is_player(t_env *e, char c)
{
	if (e->player == c || e->player == c + 32)
		return (1);
	return (0);
}

int			is_ennemy(t_env *e, char c)
{
	if (e->ennemy == c || e->player == c + 32)
		return (1);
	return (0);
}
