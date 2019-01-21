/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:15:19 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/06 01:21:10 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		a;
	int		len;
	char	*cpy;

	a = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (!(cpy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s)
	{
		cpy[a] = f(a, *s);
		a++;
		s++;
	}
	cpy[a] = '\0';
	return (cpy);
}
