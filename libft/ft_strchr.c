/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:02:03 by ravernhe          #+#    #+#             */
/*   Updated: 2019/07/06 15:02:04 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
	}
	return (NULL);
}
