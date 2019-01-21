/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:03:19 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/01 11:23:45 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	a;
	char			*cpy;

	a = 0;
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !cpy || len > ft_strlen(s) || start > ft_strlen(s))
		return (NULL);
	while (len > 0)
	{
		cpy[a] = s[start + a];
		a++;
		len--;
	}
	cpy[a] = '\0';
	return (cpy);
}
