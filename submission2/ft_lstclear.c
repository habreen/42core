/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshamudh <hshamudh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2025/12/18 21:30:58 by hshamudh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

// int main(void)
// {
//     t_list *list = NULL;

//     // Create some nodes
//     int *a = malloc(sizeof(int));
//     int *b = malloc(sizeof(int));
//     int *c = malloc(sizeof(int));
//     *a = 10; *b = 20; *c = 30;

//     list = ft_lstnew(a);
//     list->next = ft_lstnew(b);
//     list->next->next = ft_lstnew(c);

//     // Clear the list
//     ft_lstclear(&list, del);

//     if (list == NULL)
//         printf("List cleared successfully!\n");

//     return 0;
// }