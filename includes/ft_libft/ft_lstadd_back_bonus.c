/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:39:46 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/16 18:45:39 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp->next = new;
	}
}

// int	main(void)
// {
// 	t_list	*list;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*new_node;

// 	list = malloc(sizeof(t_list));
// 	node1 = malloc(sizeof(t_list));
// 	node2 = malloc(sizeof(t_list));
// 	new_node = malloc(sizeof(t_list));
// 	list->content = "premier";
// 	list->next = node1;
// 	node1->content = "deuxieme";
// 	node1->next = node2;
// 	node2->content = "troisieme";
// 	node2->next = NULL;
// 	new_node->content = "new node";
// 	new_node->next = NULL;
// 	ft_lstadd_back(&list, new_node);
// 	while (list)
// 	{
// 		printf("%s\n", (char *)list->content);
// 		list = list->next;
// 	}
// 	free(list);
// 	free(node1);
// 	free(node2);
// 	free(new_node);
// 	return (0);
// }
