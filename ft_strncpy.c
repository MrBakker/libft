/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 16:57:06 by jbakker       #+#    #+#                 */
/*   Updated: 2025/01/10 16:57:52 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strncpy(char *src, char *dest, size_t n)
{
	size_t	i;

	if (!src || !dest)
		return ;
	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		++i;
	}
}
