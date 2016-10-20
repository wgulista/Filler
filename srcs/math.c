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

int			hypothenus(t_point a, t_point b)
{
	int		x;
	int		y;

	x = (a.x - b.x) * (a.x - b.x);
	y = (a.y - b.y) * (a.y - b.y);
	return (ft_sqrt(x + y));
}