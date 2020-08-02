/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 14:58:53 by ravernhe          #+#    #+#             */
/*   Updated: 2019/07/06 14:58:54 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*alloc;
	size_t	i;

	i = 0;
	if (!(alloc = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size)
	{
		alloc[i] = '\0';
		i++;
	}
	return (alloc);
}
