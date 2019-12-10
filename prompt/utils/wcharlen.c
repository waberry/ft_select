/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcharlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:27:36 by ntom              #+#    #+#             */
/*   Updated: 2019/10/15 18:57:51 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

size_t		wcharlen(char c)
{
	if (c == 27)
		return (5);
	if ((c & 0xF0) == 0xF0)
		return (4);
	else if ((c & 0xE0) == 0xE0)
		return (3);
	else if ((c & 0xC0) == 0xC0)
		return (2);
	return (1);
}
