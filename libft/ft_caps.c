/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:33:19 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/05 00:21:30 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_caps(char *str)
{
	int		a;
	char	ptr[len(str)];

	a = 0;
	while (ptr[a] == ' ' || ptr[a] == '\t')
		a++;
	while (ptr[a++])
	{
		if (ptr[a] >= 'A' && ptr[a] <= 'Z')
			ptr[a] += 32;
	}
	a = 0;
	while (a < len(str))
	{
		if (ptr[a - 1] == ' ' || ptr[a - 1] == '\t' || a == 0)
		{
			if (ptr[a] >= 'a' && ptr[a] <= 'z')
				ptr[a] -= 32;
		}
		write(1, &ptr[a], 1);
		a++;
	}
}
