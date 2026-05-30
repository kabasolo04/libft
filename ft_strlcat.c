/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:31 by kabasolo          #+#    #+#             */
/*   Updated: 2024/01/30 12:34:11 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	dlen = 0;

	while (dlen < dstsize && dst[dlen])
		dlen++;

	if (dlen == dstsize)
		return (dstsize + slen);

	i = dlen;
	j = 0;

	while (src[j] && i + 1 < dstsize)
		dst[i++] = src[j++];

	dst[i] = '\0';
	return (dlen + slen);
}
