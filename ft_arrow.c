#include "my_minishell.h"
#include "my_minishell2.h"

void	ft_line_to_linod(t_char **line_head, char *line)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_free_char(line_head);
	while (line[x])
	{
		ft_buffering(line[x], &y, line_head);
		x++;
	}
}

void	ft_arrow_up(t_char **line_head, t_data *data, int x, int *len)
{
	t_read	*tmp;

	if (!*data->cmd_head)
		return ;
	tmp = *data->cmd_head;
	while (tmp->next && x > 0)
	{
		tmp = tmp->next;
		x--;
	}
	ft_line_to_linod(line_head, tmp->line);
	ft_write(tgetstr("cr", NULL));
	ft_write(tgetstr("cd", NULL));
	ft_write("\033[0;32mminishell% \033[0m");
	if (x == -1)
	{
		*len = 0;
		ft_free_char(line_head);
		line_head = NULL;
		return ;
	}
	ft_write(tmp->line);
	*len = ft_strlen(tmp->line);
}

int	ft_ctrl_l(t_char **line_head)
{
	ft_write(tgetstr("ho", NULL));
	ft_write(tgetstr("cd", NULL));
	ft_write("\033[0;32mminishell% \033[0m");
	ft_write_char(line_head);
	return (1);
}

int	ft_canc(t_char **line_head, int *len)
{
	if (!*line_head)
		return (1);
	ft_write(tgetstr("le", NULL));
	ft_write(tgetstr("cd", NULL));
	ft_canc_char(line_head);
	*len = ft_char_len(line_head);
	return (1);
}

int	ft_new_line(t_char **line_head, char buf, t_data *data)
{
	write(data->std_fd[1], &buf, 1);
	if (*line_head == NULL)
		free(*line_head);
	return (1);
}
