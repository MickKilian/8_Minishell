typedef struct s_smpl_cmd_list	t_smpl_cmd_list;
typedef struct s_cmd_table		t_cmd_table;

struct s_cmd_table
{
	int				nb_of_smpl_cmd;
	char			*input_file;
	char			*output_file;
	char			*err_file;
	t_smpl_cmd_list	*smpl_cmd;
};

struct s_smpl_cmd_list
{
	int				nb_of_tokens;
	t_token			*token;
	t_smpl_cmd_list	*prev;
	t_smpl_cmd_list	*next;
};

-----------------------

t_smpl_cmd_list	*ft_new_smpl_cmd(void);
void			ft_smpl_cmd_addnext(t_smpl_cmd_list *current, t_smpl_cmd_list *new);

t_smpl_cmd_list	*ft_new_smpl_cmd()
{
	t_smpl_cmd_list	*new;

	if (ft_mallocator(&new, sizeof(t_smpl_cmd_list)))
		return (NULL);
	new->nb_of_tokens = 0;
	new->token = NULL;
	new->prev = new;
	new->next = new;
	return (new);
}

void	ft_smpl_cmd_addback(t_smpl_cmd_list *current, t_smpl_cmd_list *new)
{
	if (!new)
		return ;
	new->prev = current->prev;
	new->next = current;
	if (current->next == current)
		current->next = new;
	else
		current->prev->next = new;
	current->prev = new;
	return ;
}
