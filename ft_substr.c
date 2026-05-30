/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:19:09 by kabasolo          #+#    #+#             */
/*   Updated: 2024/01/03 18:04:57 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	if (!s)
		return (NULL);

	slen = ft_strlen(s);

	if (start >= slen)
		return (ft_strdup(""));

	if (len > slen - start)
		len = slen - start;

	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);

	ft_strlcpy(str, s + start, len + 1);
	return (str);
}