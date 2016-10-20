/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:38:10 by wgulista          #+#    #+#             */
/*   Updated: 2016/10/20 15:24:40 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			ft_abs(int num)
{
	if (num > 0)
		return (num);
	return (-num);
}

int			ft_sqrt(int num)
{
	int		i;

	i = 1;
	while (i * i < num)
		i++;
	return (i - 1);
}
