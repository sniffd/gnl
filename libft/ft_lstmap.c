/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 05:23:06 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 05:23:12 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_else(t_list *tmp, t_list **list, t_list **head)
{
	if (!(*list))
	{
		*list = tmp;
		*head = *list;
	}
	else
	{
		(*list)->next = tmp;
		*list = (*list)->next;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*tmp;
	t_list	*head;

	list = 0;
	head = 0;
	if (!lst || !f)
		return (0);
	while (lst)
	{
		if (!(tmp = ft_lstnew((f(lst))->content, f(lst)->content_size)))
		{
			while (list)
			{
				tmp = list->next;
				free(list);
				list = tmp;
			}
		}
		else
			ft_else(tmp, &list, &head);
		lst = lst->next;
	}
	return (head);
}
