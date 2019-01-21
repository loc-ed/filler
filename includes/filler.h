/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 03:04:05 by cfrederi          #+#    #+#             */
/*   Updated: 2018/08/08 21:24:03 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_player
{
	char		id;
	t_point		start;
}				t_player;

typedef struct	s_token
{
	int			width;
	int			height;
	int			size;
	char		**data;
}				t_token;

typedef struct	s_filler
{
	int			inited;
	t_player	player;
	t_player	enemy;
	t_point		target;
	t_token		board;
	t_token		token;
	t_point		*buf_p;
	int			p_count;
	t_point		*buf_e;
	int			e_count;
}				t_filler;

t_point			closest_pair(t_filler filler);
int				try_place(t_filler filler, t_point point);
void			place(t_filler filler);
int				place_around(t_filler filler, t_point p, t_point *result);
t_point			find_placement(t_filler filler);
int				dist(t_point a, t_point b);
int				position_valid(t_filler filler, t_point point);

#endif

