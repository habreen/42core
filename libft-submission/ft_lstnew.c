/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshamudh <hshamudh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2025/12/18 19:35:18 by hshamudh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// typedef struct s_list
// {
//     void          *content;
//     struct s_list *next;
// } t_list;

// t_list *ft_lstnew(void *content);

// int main(void)
// {
//     t_list *node = ft_lstnew("Hello");

//     if (node)
//         printf("Node content: %s\n", (char *)node->content);

//     free(node); // free the allocated memory
// }