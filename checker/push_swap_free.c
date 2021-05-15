#include "../includes/push_swap.h"

void		free_stack(t_stack *stack)
{
	t_stack		*next;
	t_stack		*delete;

	if (stack)
	{
		next = stack->next;
		while (next != stack)
		{
			delete = next;
			next = next->next;
			free(delete);
		}
		free(next);
	}
}

void		free_all(t_all *all)
{
	if (all)
	{
		if (all->stack_a)
			free_stack(all->stack_a);
		if (all->stack_b)
			free_stack(all->stack_b);
		free(all);
	}
}

void	ft_error2(t_all *all)
{
    free_all(all);
	write(1, "Error\n", 6);
	exit (0);
}

void	ft_error()
{
	write(1, "Error\n", 6);
	exit (0);
}