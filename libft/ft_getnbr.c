/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 14:56:24 by ravernhe          #+#    #+#             */
/*   Updated: 2019/07/06 14:56:26 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_getnbr(char *str)
{
	size_t	i;
	int		result;

	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		result = result * (-1);
	return (result);
}
