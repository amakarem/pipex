/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:52:57 by aelaaser          #+#    #+#             */
/*   Updated: 2024/10/17 18:33:03 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*obj;
	void	*ptr;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		ptr = f(lst->content);
		obj = ft_lstnew(ptr);
		if (obj == NULL)
		{
			del(ptr);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, obj);
		lst = lst->next;
	}
	return (new);
}
