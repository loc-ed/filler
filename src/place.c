/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 03:03:14 by cfrederi          #+#    #+#             */
/*   Updated: 2018/09/03 15:04:33 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdlib.h>

//8. checks that placement coordinates fall within the map constraints 

int			position_valid(t_filler filler, t_point point)
{
	return (point.x >= 0 && point.y >= 0 &&
			point.x < filler.board.width && point.y < filler.board.height);
}

//7.4 function that trims the token using offset values . iterates until it finds the first '*' and trims the top and left side of the piece . Checks the validity of piece (whether it will fall within the constaints of the board

int			place_around(t_filler filler, t_point p, t_point *result)
{
	t_point		offset;

	offset.y = 0;
	while (offset.y < filler.token.height)
	{
		offset.x = 0;
		while (offset.x < filler.token.width)
		{
			result->x = p.x - offset.x;
			result->y = p.y - offset.y;
			if (filler.token.data[offset.y][offset.x] == '*' &&
					position_valid(filler, *result) &&
					!try_place(filler, *result))
			{
				return (1);
			}
			offset.x++;
		}
		offset.y++;
	}
	return (0);
}

//6. function that outputs your move by calling function which t_point value and checks the validity of that placement. If not it returns 0 0\n

void		place(t_filler filler)
{
	t_point		candidate;

	candidate = closest_pair(filler);
	if (!position_valid(filler, candidate))
	{
		candidate.x = 0;
		candidate.y = 0;
		ft_putstr("0 0\n");
		exit(0);
	}
	ft_putnbr(candidate.y);
	ft_putchar(' ');
	ft_putnbr(candidate.x);
	ft_putchar('\n');
}

int			try_place(t_filler filler, t_point point)
{
	t_point	p;
	int		count;

	if (point.y + filler.token.height > filler.board.height ||
		point.x + filler.token.width > filler.board.width)
		return (2);
	count = 0;
	p.y = 0;
	while (p.y < filler.token.height)
	{
		p.x = 0;
		while (p.x < filler.token.width)
		{
			if (filler.token.data[p.y][p.x] == '*' &&
		(filler.board.data[point.y + p.y][point.x + p.x] == filler.enemy.id))
				return (1);
			if (filler.token.data[p.y][p.x] == '*' &&
		(filler.board.data[point.y + p.y][point.x + p.x] == filler.player.id) &&
					++count > 1)
				return (1);
			p.x++;
		}
		p.y++;
	}
	return (count < 1 ? 1 : 0);
}

//7.5 depending on the placemt of the first enemy token . (on top to the left etc) in relation to player token . This function iterates though the map starting either at the top or the bottom till it finds a fitting placement closest the the enemy piece also taking into account the trimmed piece

t_point		find_placement(t_filler filler)
{
	t_point p;
	t_point temp;

	p.y = filler.target.y;
	while (filler.target.y == 0 ? p.y < filler.board.height : p.y >= 0)
	{
		p.x = filler.target.x;
		while (filler.target.x == 0 ? p.x < filler.board.width : p.x >= 0)
		{
			if (filler.board.data[p.y][p.x] == filler.player.id &&
					place_around(filler, p, &temp))
				return (temp);
			p.x += (filler.target.x == 0 ? 1 : -1);
		}
		p.y += (filler.target.y == 0 ? 1 : -1);
	}
	return (p);
}

