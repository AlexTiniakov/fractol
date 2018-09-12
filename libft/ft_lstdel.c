/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 21:30:47 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/30 13:46:01 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *tab;

	if (alst && del)
	{
		tmp = *alst;
		tab = NULL;
		while (tmp)
		{
			tab = tmp->next;
			del((void *)tmp->content, tmp->content_size);
			free(tmp);
			tmp = tab;
		}
		*alst = NULL;
	}
}
