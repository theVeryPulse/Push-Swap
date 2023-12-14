#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"

/* Circular doubly linked list */
typedef struct s_cbl_list
{
	int					number;
	struct s_cbl_list	*prev;
	struct s_cbl_list	*next;
}	t_cbl_list;


#endif