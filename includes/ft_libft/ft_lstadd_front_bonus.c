/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:48:57 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/16 15:49:14 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **list, t_list *new)
{
	if (!list || !new)
		return ;
	new->next = *list;
	*list = new;
}
/*
int	main(void)
{
    t_list	*head = ft_lstnew("A");
    t_list	*new1 = ft_lstnew("X");

    printf("Avant : %s\n", (char *)head->content);

    ft_lstadd_front(&head, new1);

    printf("Après : %s\n", (char *)head->content);

    return (0);
}*/
