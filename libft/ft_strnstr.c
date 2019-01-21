/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:56:27 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/06 14:46:25 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;
	char	*h;
	char	*n;

	a = 0;
	n = (char *)needle;
	h = (char *)haystack;
	if (n[0] == '\0')
		return (h);
	while ((h[a] != '\0') && (a < len))
	{
		b = 0;
		while (a + b < len && h[a + b] == n[b] && n[b] != '\0')
			b++;
		if (n[b] == '\0')
			return ((char *)(haystack + a));
		a++;
	}
	return (NULL);
}
