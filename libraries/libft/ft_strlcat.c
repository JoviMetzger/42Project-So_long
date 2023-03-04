/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 07:28:44 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/01/12 00:18:17 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	char	*s;
	size_t	i;
	size_t	dest_len;

	s = (char *)src;
	dest_len = 0;
	while (dest_len < n && *dest)
	{
		dest++;
		dest_len++;
	}
	if (dest_len == n)
		return (dest_len + ft_strlen(src));
	i = 0;
	while (s[i] != '\0')
	{
		if (i < n - dest_len - 1)
		{
			*dest = s[i];
			dest++;
		}
		i++;
	}
	*dest = '\0';
	return (dest_len + i);
}	
