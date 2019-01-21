/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:44:14 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/05 16:43:33 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int a;

	a = 0;
	while (s[a] != '\0')
		a++;
	while (a >= 0)
	{
		if (s[a] == (char)c)
			return ((char *)(s + a));
		if ((char)c == '\0')
			return ((char*)(s + a));
		a--;
	}
	return (NULL);
}
