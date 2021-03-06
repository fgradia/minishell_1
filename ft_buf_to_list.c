#include "my_minishell.h"

int	ft_buf_to_node(int len, int x, char *buf, t_read *new)
{
	int	y;

	y = 0;
//	if (!ft_check_buf(buf + x, len))
//		return (-1);
	new->line = (char *)malloc(sizeof(char) * (len + 1));
	new->line[len] = '\0';
	while (buf[x] == ' ')
		x++;
	while (buf[x] != '\n' && buf[x] != '\0')
	{
		new->line[y] = buf[x];
		x++;
		y++;
	}
	new->line[y] = '\0';
	new->next = NULL;
	x++;
	return (x);
}

void	ft_append_read(t_read *new, t_read **head)
{
	t_read	*tmp;

	tmp = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_buf_to_list(char *buf, t_data *data)
{
	int		len;
	int		x;
	t_read	*new;

	x = 0;
	len = 0;
	while (buf && buf[x])
	{
		len = ft_strchr('\n', buf + x);
		if (len < 0)
			break ;
		//else if (len > 3 || len < 2)
		//	ft_exit("Error: wrong op!\n", data);
		new = (t_read *)malloc(sizeof(t_read) * 1);
		x = ft_buf_to_node(len, x, buf, new);
	//	if (x < 0)
	//		ft_exit("Error:!\n", data);
		ft_append_read(new, data->cmd_head);
		new = new->next;
	}
}