/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 19:46:47 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/05 16:22:53 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	int a;
	int b;
	int i;

	a = 0;
	b = 0;
	i = 0;
	while (dst[a] != '\0')
		a++;
	while (i < (int)len)
	{
		dst[a] = src[i];
		if (src[i] == '\0')
			return (dst);
		i++;
		a++;
	}
	dst[a] = '\0';
	return (dst);
}
