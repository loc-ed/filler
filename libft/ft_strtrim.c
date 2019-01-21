/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:38:35 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/06 01:25:13 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		a;
	int		len;
	char	*new;

	a = 0;
	if (!s)
		return (0);
	while (s[a] && ((s[a] == ' ') || (s[a] == '\t') || (s[a] == '\n')))
		a++;
	len = ft_strlen(s) - 1;
	if (s[a] == '\0')
		return (ft_strdup((s + a)));
	while (s[len] && ((s[len] == ' ') || (s[len] == '\t') || (s[len] == '\n')))
		len--;
	if (!(new = ft_strnew(len)))
		return (NULL);
	new = ft_strsub(s, a, (len - a) + 1);
	return (new);
}
