
#include "push_swap.h"

void	ft_opti_end_b(t_stacks *stacks, int *tab)
{
	if (tab[0] < tab[1] && tab[1] < tab[2])
	{
		ft_inst_rot_b(stacks);
		ft_inst_swap_b(stacks);
		ft_inst_push_a(stacks);
		ft_inst_push_a(stacks);
		ft_inst_push_a(stacks);
	}
	else if (tab[0] < tab[1] && tab[0] < tab[2] && tab[1] > tab[2])
	{
		ft_inst_rot_b(stacks);
		ft_inst_push_a(stacks);
		ft_inst_push_a(stacks);
		ft_inst_push_a(stacks);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
	{
		ft_inst_rev_rot_b(stacks);
		ft_inst_push_a(stacks);
		ft_inst_push_a(stacks);
		ft_inst_push_a(stacks);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
	{
		ft_inst_swap_b(stacks);
		ft_inst_push_a(stacks);
		ft_inst_push_a(stacks);
		ft_inst_push_a(stacks);
	}
}

void	ft_opti_sub_b(t_stacks *stacks, int *tab)
{

}

int		ft_opti_3_b(t_stacks *stacks, t_struct *data)
{
	int	*tab;

	tab = (int*)malloc(sizeof(int) * 3);
	tab[0] = *(int*)(*stacks->s_a)->content;
	tab[1] = *(int*)(*stacks->s_a)->next->content;
	tab[2] = *(int*)(*stacks->s_a)->next->next->content;
	if (ft_lst_size(*stacks->s_b) == 3)
	{
		ft_opti_end_b(t_stacks *stacks, t_struct *data);
		free(tab);
		return (1);
	}
	else
	{
		ft_opti_sub_b(t_stacks *stacks, t_struct *data);
		free(tab);
		return (1);
	}
	free(tab);
	return (0);
}
