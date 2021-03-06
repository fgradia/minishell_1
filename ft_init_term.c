#include "my_minishell.h"

void	ft_init_term(t_data *data)
{
	data->std_fd[0] = dup(0);
	data->std_fd[1] = dup(1);
	tgetent(NULL, getenv ("TERM"));
	tcgetattr(0, &data->old_term);
	tcgetattr(0, &data->my_term);
	data->my_term.c_lflag &= ~(ICANON | ECHO);

//	printf("VINTR= %hhu\n", data->my_term.c_cc[VINTR]);
	data->my_term.c_cc[VINTR] = 0;
	data->my_term.c_cc[VQUIT] = 0;
	//data->my_term.c_cc[VEOF] = 4;
	tcsetattr(0, 0, &data->my_term);
}