/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector_actions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/06 22:46:09 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_redir_actions(t_pars *pars)
{
	pars->ft_redir[REDIR_NONE] = ft_redir_none;
	pars->ft_redir[REDIR_NEW] = ft_redir_new;
	pars->ft_redir[REDIR_CATCH] = ft_redir_catch;
	pars->ft_redir[REDIR_KEEP] = ft_redir_keep;
	pars->ft_redir[REDIR_DROP] = ft_redir_drop;
	pars->ft_redir[REDIR_TAKE] = ft_redir_take;
	pars->ft_redir[REDIR_SKIP] = ft_redir_skip;
	pars->ft_redir[REDIR_END] = ft_redir_end;
	pars->ft_redir[REDIR_ERR] = ft_redir_err;
	return (0);
}

int	ft_redir_none(t_pars *pars)
{
	//printf("in ft_none\n");
	(void)pars;
	return (0);
}

int	ft_redir_new(t_pars *pars)
{
	int	id;

	id = 0;
	//if (ft_mallocator(&pars->command, sizeof(t_command)))
	//	return (0);
	if (pars->command)
	{
		//printf("shifting token in command from : %s to : %s\n", pars->command->token->id, pars->command->token->next->id);
		pars->command->token = pars->command->token->next;
		id = pars->command->id;
	}
	pars->command = ft_command_addnext(pars->command, ft_new_command(pars->token));
	//printf("\033[33;2mstill empty%d\033[0m\n", pars->nb_of_commands);
	//printf("check : %d\n", pars->nb_of_commands);
	id++;
	pars->nb_of_commands++;
	//printf("\033[33;2mnb_of_commands : %d\033[0m\n", pars->nb_of_commands);
	pars->command->nb_of_tokens = 1;
	pars->command->id = id;
	return (0);
}

int	ft_redir_catch(t_pars *pars)
{
	(void)pars;
/*	//printf("in ft_catch\n");
	//if (pars->token)
	//	printf("\n\n*****current token is : %s\n", pars->token->id);
	ft_redir_record(pars);
	pars->nb_taken_char = 0;
	//printf("pars->token : %p <%p>\n", pars->token, &(pars->token));
	//if (pars->token)
	//{
	//	printf("entered\n");
	//	printf("%s <%s>\n", pars->token->id, ft_getlabel_token_types(pars->token->type));
	//}
	//printf("ready to catch : %s\n", pars->temp);
	if (pars->temp)
	{
		pars->token = ft_token_addnext(pars->token, ft_new_token(pars->temp));
		//printf(" token caught: %s\n", pars->token->id);
		//printf(" token->prev : %s\n", pars->token->prev->id);
		//printf(" token->next : %s\n", pars->token->next->id);
		pars->nb_of_tokens++;
		//printf("------------------nb = %d\n", pars->nb_of_tokens);
		pars->token->type =  pars->redir_prev_decision.token_type;
		//printf("%s <%s>\n", pars->token->id, ft_getlabel_token_types(pars->token->type));
		//printf("nb_of_tokens = %d\n", pars->nb_of_tokens);
		//printf("1-%s    %s\n", pars->token->id, ft_getlabel_token_types(pars->token->type));
		//printf("2-%s    %s\n", pars->temp, ft_getlabel_token_types(pars->token->type));
		free(pars->temp);
		pars->temp = NULL;
	}
	*/
	return (0);
}

int	ft_redir_keep(t_pars *pars)
{
	//printf("in ft_keep\n");
	(void)pars;
	return (0);
}

int	ft_redir_drop(t_pars *pars)
{
	(void)pars;
	//printf("in ft_drop\n");
	//if (pars->temp)
	//{
	//	free(pars->temp);
	//	pars->temp = NULL;
	//}
	return (0);
}

int	ft_redir_take(t_pars *pars)
{
	//printf("\033[33;2min take\033[0m\n");
	if (!pars->command)
	{
		//printf("\033[33;2mhere!\033[0m\n");
		ft_redir_new(pars);
	}
	else
	{
		pars->command->token = ft_token_addnext(pars->command->token, ft_new_token(pars->token->id));
		pars->command->nb_of_tokens++;
	}
	pars->command->token->type = pars->token->type;
	return (0);
}

int	ft_redir_skip(t_pars *pars)
{
	//printf("\033[33;2min skip\033[0m\n");
	pars->nb_of_tokens--;
	pars->token = pars->token->next;
	//printf("in ft_skip\n");
	//ft_redir_record(pars);
	return (0);
}

int	ft_redir_record(t_pars *pars)
{
	(void)pars;
	/*char	*temp1;
	char	*temp2;

	//printf("in ft_record\n");
	//printf("taken char : %d\n", pars->nb_taken_char);
	//printf("pars->temp : %s\n", pars->temp);
	if (pars->nb_taken_char)
	{
		if (!pars->temp)
		{
			pars->temp = malloc(sizeof(char));
			ft_bzero(pars->temp, sizeof(char));
			temp1 = pars->temp;
		}
		else
		{
			temp1 = ft_strndup(pars->temp, 0);
			free(pars->temp);
		}
		temp2 = ft_substr(pars->user_input - pars->nb_taken_char, 0, pars->nb_taken_char);
		pars->temp = ft_strjoin(temp1, temp2);
		//printf("pars->temp : %s\n", pars->temp);
		free(temp1);
		free(temp2);
		pars->nb_taken_char = 0;
	}
	*/
	return (0);
}

int	ft_redir_end(t_pars *pars)
{
	(void)pars;
/*	//printf("in ft_end\n");
	ft_redir_take(pars);
	pars->redir_prev_decision.token_type = pars->redir_new_decision.token_type;
	ft_redir_catch(pars);
	*/
	return (0);
}

int	ft_redir_err(t_pars *pars)
{
	//ft_freeall(pars);
	//pars->nb_of_tokens = 0;
	(void)pars;
	return (ft_msgerr(ERR_SYNTAX), 0);
}
