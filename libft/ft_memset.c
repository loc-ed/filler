/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:00:30 by cfrederi          #+#    #+#             */
/*   Updated: 2018/05/29 12:24:57 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	a;
	char	*ptr;

	a = 0;
	ptr = (char *)str;
	while (a < n)
	{
		ptr[a] = c;
		a++;
	}
	return (str);
}
