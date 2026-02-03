/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshamudh <hshamudh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2025/12/18 19:21:47 by hshamudh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// typedef struct s_list
// {
//     void          *content;
//     struct s_list *next;
// } t_list;

// int main(void)
// {
//     t_list node3 = { "Node 3", NULL };
//     t_list node2 = { "Node 2", &node3 };
//     t_list node1 = { "Node 1", &node2 };

//     printf("List size: %d\n", ft_lstsize(&node1)); // Output: 3
// }