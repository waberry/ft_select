/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 20:11:12 by wdaher-a          #+#    #+#             */
/*   Updated: 2018/07/10 18:42:16 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
		{
			s[i] = '\0';
			++i;
		}
	}
}
