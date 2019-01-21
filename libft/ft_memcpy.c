/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:10:04 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/05 00:31:31 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p1;
	char	*p2;
	size_t	a;

	a = 0;
	p1 = (char *)dst;
	p2 = (char *)src;
	while (a < n)
	{
		p1[a] = p2[a];
		a++;
	}
	return (dst);
}
