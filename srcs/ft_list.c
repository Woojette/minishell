#include "minishell.h"

t_parse	*ft_lstnew_parse(char *val)
{
	t_parse	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->val = val;
	lst->state = GENERAL;
	lst->next = NULL;
	return (lst);
}

// void	ft_lstadd_front(t_parse **list, t_parse *new)
// {
// 	if (!list || !new)
// 		return ;
// 	new->next = *list;
// 	*list = new;
// }

// void	ft_lstadd_back(t_parse **lst, t_parse *new)
// {
// 	t_parse	*temp;

// 	if (!lst || !new)
// 		return ;
// 	if (!(*lst))
// 	{
// 		(*lst) = new;
// 		return ;
// 	}
// 	temp = *lst;
// 	while (temp->next != NULL)
// 		temp = temp->next;
// 	temp->next = new;
// }
