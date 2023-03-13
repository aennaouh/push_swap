#include "push_swap.h"

unsigned int lst_size(t_data *stack)
{
	unsigned int	i;

	i = 0;
	if (stack == NULL)
		return (i);
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	print_stack(t_data *stack)
{
	while (stack != NULL)
	{
		printf("[%d] %d|",stack->index, stack->content);
		stack = stack->next;
	}
	printf("\n");
}
