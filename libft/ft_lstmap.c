/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:03:50 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/30 14:51:26 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tab;
	t_list *beg;
	t_list *tmp;

	beg = NULL;
	if (lst && f)
	{
		tab = f(lst);
		if (!(beg = ft_lstnew(tab->content, tab->content_size)))
			return (NULL);
		tmp = beg;
		while (lst->next)
		{
			lst = lst->next;
			if (!(tab = f(lst)))
				return (NULL);
			if (!(tmp->next = ft_lstnew(tab->content, tab->content_size)))
			{
				free(tab);
				return (NULL);
			}
			tmp = tmp->next;
		}
	}
	return (beg);
}
