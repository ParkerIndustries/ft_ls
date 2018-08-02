/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 23:09:01 by smickael          #+#    #+#             */
/*   Updated: 2018/03/30 23:09:02 by smickael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char			*s;
	char			*d;
	unsigned int	i;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	while (n--)
	{
		d[i] = s[i];
		if (s[i++] == (char)c)
			return ((char *)dest + i);
	}
	return (NULL);
}
