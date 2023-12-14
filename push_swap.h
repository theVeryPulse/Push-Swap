#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"

/* Circular doubly linked list */
typedef struct s_cbl_list
{
	int					value;
	struct s_cbl_list	*prev;
	struct s_cbl_list	*next;
}	t_cbl_list;

/* List operations */

void		list_append(t_cbl_list **top, int value);

t_cbl_list	*list_pop(t_cbl_list **top);

void		list_push(t_cbl_list **top, t_cbl_list *node_to_push);

int			get_node_count(t_cbl_list *top);

void		isolate_node(t_cbl_list *node);

/* Designated operations */

#endif