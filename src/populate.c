/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 03:01:30 by cfrederi          #+#    #+#             */
/*   Updated: 2018/08/09 14:02:19 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

//7.2 clears and updates the placement counts after most recent placement , Get a mapping of where the enemy / player is on the board

void		create_arrays(t_filler *filler)
{
	int		size;

	if (filler->buf_p)
		ft_memdel((void **)&filler->buf_p);
	if (filler->buf_e)
		ft_memdel((void **)&filler->buf_e);
	size = filler->board.size;
	if (!(filler->buf_p = ft_memalloc(size * sizeof(t_point))) ||
		!(filler->buf_e = ft_memalloc(size * sizeof(t_point))))
		exit(1);
	ft_bzero(filler->buf_p, size * sizeof(t_point));
	ft_bzero(filler->buf_e, size * sizeof(t_point));
}

//7.1 notes and counts all the '*' previously placed by both the enemy and the player

void		populate_closest_array(t_filler *filler)
{
	t_point	point;

	create_arrays(filler);
	filler->p_count = 0;
	filler->e_count = 0;
	point.y = 0;
	while (point.y < filler->board.height)
	{
		point.x = 0;
		while (point.x < filler->board.width)
		{
			if (filler->board.data[point.y][point.x] == filler->player.id)
				filler->buf_p[filler->p_count++] = point;
			else if (filler->board.data[point.y][point.x] == filler->enemy.id)
				filler->buf_e[filler->e_count++] = point;
			point.x++;
		}
		point.y++;
	}
}

//7.3 finds the shortest distance between the enemy and user pieces 

int			dist(t_point a, t_point b)
{
	return (ft_max(a.x, b.x) - ft_min(a.x, b.x) +
			ft_max(a.y, b.y) - ft_min(a.y, b.y));
}

//7. iterates through the number of placed enemy and player pieces till it finds the shortest distance between the two by calling the dist function. if the distance doesnt fall within the confines of the board it calls function to find placement else returns value 

t_point		closest_pair(t_filler filler)
{
	int		p_cur;
	int		e_cur;
	t_point	temp;
	t_point	p;
	int		last_dist;

	populate_closest_array(&filler);
	last_dist = filler.board.size;
	p_cur = 0;
	while (p_cur < filler.p_count)
	{
		e_cur = 0;
		while (e_cur < filler.e_count)
		{
			if (dist(filler.buf_p[p_cur], filler.buf_e[e_cur]) <= last_dist &&
					place_around(filler, filler.buf_p[p_cur], &temp))
			{
				p = temp;
				last_dist = dist(filler.buf_p[p_cur], filler.buf_e[e_cur]);
			}
			e_cur++;
		}
		p_cur++;
	}
	return (last_dist == filler.board.size ? find_placement(filler) : p);
}
