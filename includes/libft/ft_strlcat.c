/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:50:24 by fbruggem          #+#    #+#             */
/*   Updated: 2022/03/31 13:51:41 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	ret;

	dstlen = 0;
	srclen = 0;
	ret = ft_strlen(src) + ft_strlen(dst);
	while (dstsize != 0 && *dst != '\0')
	{
		dst++;
		dstlen++;
		dstsize--;
	}
	if (dstsize == 0)
		return (dstlen + ft_strlen(src));
	while (*src != '\0' && dstsize > 1)
	{
		*dst = *src;
		src++;
		dst++;
		dstsize--;
	}
	*dst = '\0';
	return (ret);
}
