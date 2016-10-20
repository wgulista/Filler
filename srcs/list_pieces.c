/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pieces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:37:56 by wgulista          #+#    #+#             */
/*   Updated: 2016/10/20 15:16:08 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_piece			*set_piece(int x, int y)
{
	t_piece		*new;

	new = (t_piece*)malloc(sizeof(t_piece));
	new->pts = set_point(x, y);
	new->next = NULL;
	return (new);
}

void			add_to_list(t_piece **pieces, t_piece *new)
{
	t_piece		*current;

	if (!(*pieces))
	{
		(*pieces) = new;
		return ;
	}
	current = (*pieces);
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}
