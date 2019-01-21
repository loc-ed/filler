/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:30:42 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/06 01:31:00 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char const))
{
	int		a;
	int		len;
	char	*cpy;

	a = 0;
	if ((!s) || (!f))
		return (NULL);
	len = ft_strlen(s);
	if (!(cpy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s)
	{
		cpy[a++] = f(*s);
		s++;
	}
	cpy[a] = '\0';
	return (cpy);
}
