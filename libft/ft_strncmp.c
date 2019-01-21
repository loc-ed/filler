/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 10:18:15 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/05 17:42:46 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int a;

	a = 0;
	while (s1[a] != '\0' && s1[a] == s2[a] && a < (int)n && s2[a] != '\0')
		a++;
	if (a == (int)n)
		return ((unsigned char)s1[a - 1] - (unsigned char)s2[a - 1]);
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
