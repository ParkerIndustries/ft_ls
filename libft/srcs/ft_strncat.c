/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 23:14:17 by smickael          #+#    #+#             */
/*   Updated: 2018/03/30 23:14:18 by smickael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dst);
	while (*src && n--)
		dst[i++ + len] = *src++;
	dst[i + len] = '\0';
	return (dst);
}
