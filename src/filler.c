/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 03:02:16 by cfrederi          #+#    #+#             */
/*   Updated: 2018/09/03 15:04:18 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <fcntl.h>

//4.deletes theb old token and map in favour of the updated version. dont forget the offset values originally set.

void		free_token(t_token *token, int offset)
{
	int		i;
	char	*str;

	if (!token->data)
		return ;
	i = 0;
	while (i < token->height)
	{
		str = token->data[i] - offset;
		ft_strdel(&str);
		i++;
	}
	ft_memdel((void **)&token->data);
}

//3.function used for both token and map . the offset value is to account for the 0000 before the rows of each map . the token doesnt have that so you'll have an offset of 0.Allocates memory to save board and token info. calls function to free anything in the allocated memory beforehand 

void		read_token(char *line, int offset, t_token *token)
{
	int		i;

	free_token(token, offset);
	line = ft_strchr(line, ' ') + 1;
	token->height = ft_atoi(line);
	token->width = ft_atoi(ft_strchr(line, ' '));
	token->size = token->height * token->width;
	if (offset)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	token->data = ft_memalloc(token->height * sizeof(char *));
	i = 0;
	while (i < token->height)
	{
		get_next_line(0, &line);
		token->data[i] = line + offset;
		i++;
	}
}

//5.functio

void		init(t_filler *filler)
{
	t_point p;

	p.y = 0;
	while (p.y < filler->board.height)
	{
		p.x = 0;
		while (p.x < filler->board.width)
		{
			if (filler->board.data[p.y][p.x] == filler->player.id)
				filler->player.start = p;
			else if (filler->board.data[p.y][p.x] == filler->enemy.id)
				filler->enemy.start = p;
			p.x++;
		}
		p.y++;
	}
	filler->target.x = (filler->enemy.start.x - filler->player.start.x < 0 ?
			0 : filler->board.width - 1);
	filler->target.y = (filler->enemy.start.y - filler->player.start.y < 0 ?
			0 : filler->board.height - 1);
	filler->inited = 1;
}

//2. read updated map and given token loop

void		filler_loop(t_filler filler)
{
	char	*line;
	int		res;

	while ((res = get_next_line(0, &line)) > -1)
	{
		if (!line)
			continue;
		if (!ft_strncmp(line, "Plateau ", 8))
		{
			read_token(line, 4, &filler.board);
			if (!filler.inited)
				init(&filler);
		}
		else if (!ft_strncmp(line, "Piece ", 6))
		{
			read_token(line, 0, &filler.token);
			place(filler);
		}
		ft_strdel(&line);
	}
}

//1.set all struct values to zero and get player ID before calling function to get map and token infomation

int			main(void)
{
	t_filler	filler;
	char		*line;

	ft_bzero(&filler, sizeof(t_filler));
	line = NULL;
	filler.inited = 0;
	if (get_next_line(0, &line) && line && ft_strlen(line) > 10 &&
			!ft_strncmp(line, "$$$ exec p", 9) &&
			(line[10] == '1' || line[10] == '2'))
	{
		filler.player.id = (line[10] == '1' ? 'O' : 'X');
		filler.enemy.id = (line[10] == '1' ? 'X' : 'O');
		ft_strdel(&line);
		filler_loop(filler);
	}
	else
		return (1);
	return (0);
}
