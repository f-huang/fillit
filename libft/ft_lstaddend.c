/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:34:35 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/28 16:48:18 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*ptr;

	ptr = *alst;
	if (alst != NULL && *alst == NULL)
		*alst = new;
	else
	{
		while (ptr->next != *alst)
			ptr = ptr->next;
		ptr->next = new;
	}
}
