/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 15:21:49 by jbakker       #+#    #+#                 */
/*   Updated: 2023/10/04 16:06:30 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*origin_ptr;
	t_list	*new_ptr;
	t_list	*output;

	if (!lst || !f || !del)
		return (0);
	origin_ptr = lst->next;
	output = ft_lstnew(f(lst->content));
	new_ptr = output;
	while (new_ptr && origin_ptr)
	{
		new_ptr->next = ft_lstnew(f(origin_ptr->content));
		origin_ptr = origin_ptr->next;
		new_ptr = new_ptr->next;
	}
	if (origin_ptr || !new_ptr)
		ft_lstclear(&output, del);
	else
		return (output);
	return (0);
}
