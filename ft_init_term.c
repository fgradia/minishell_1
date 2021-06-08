#include "my_minishell.h"

void	ft_init_term(t_data *data)
{
	tcgetattr(0, &data->old_term);
	tcgetattr(0, &data->my_term);
	data->my_term.c_lflag &= ~(ICANON | ECHO);
	//data->my_term.c_cc[VEOF] = 4;
	tcsetattr(0, 0, &data->my_term);
}