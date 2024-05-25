/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:32:09 by jbakker       #+#    #+#                 */
/*   Updated: 2024/05/14 13:42:52 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (new)
			new->next = *lst;
		else
			new->next = NULL;
		*lst = new;
	}
	else
	{
		new->next = NULL;
		*lst = new;
	}
}
