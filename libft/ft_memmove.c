/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:04:47 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/04 22:54:00 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				a;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	a = 0;
	if (p2 < p1)
	{
		a = len;
		while (a-- > 0)
			p1[a] = p2[a];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
