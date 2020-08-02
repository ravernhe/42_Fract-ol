/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:02:59 by ravernhe          #+#    #+#             */
/*   Updated: 2019/07/06 15:03:01 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (!(s1 && s2))
		return (0);
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] == s2[i]);
}
