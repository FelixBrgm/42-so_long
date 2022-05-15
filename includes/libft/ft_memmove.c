/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:54:44 by fbruggem          #+#    #+#             */
/*   Updated: 2022/03/31 13:48:38 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	const char		*from;
	char			*to;

	i = 0;
	from = src;
	to = dst;
	if (!dst && !src)
		return (0);
	if (from > to)
		while (len--)
			*to++ = *from++;
	else
	{
		to += len -1;
		from += len -1;
		while (len--)
			*to-- = *from--;
	}
	return (dst);
}
