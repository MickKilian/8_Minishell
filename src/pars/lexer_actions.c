/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/05 22:25:17 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_lex_actions(t_lex *lex)
{
	lex->ft[LEX_CATCH] = ft_lex_catch;
	lex->ft[LEX_KEEP] = ft_lex_keep;
	lex->ft[LEX_DROP] = ft_lex_drop;
	lex->ft[LEX_TAKE] = ft_lex_take;
	lex->ft[LEX_SKIP] = ft_lex_skip;
	lex->ft[LEX_END] = ft_lex_end;
	lex->ft[LEX_SYNT_ERR] = ft_lex_synt_err;
	return (0);
}

int	ft_lex_catch(t_lex *lex)
{
	//printf("in ft_catch\n");
	//if (lex->token)
	//	printf("\n\n*****current token is : %s\n", lex->token->id);
	ft_lex_record(lex);
	lex->nb_taken_char = 0;
	//printf("lex->token : %p <%p>\n", lex->token, &(lex->token));
	//if (lex->token)
	//{
	//	printf("entered\n");
	//	printf("%s <%s>\n", lex->token->id, ft_getlabel_token_types(lex->token->type));
	//}
	//printf("ready to catch : %s\n", lex->temp);
	if (lex->temp)
	{
		lex->token = ft_token_addnext(lex->token, ft_new_token(lex->temp));
		//printf("caugth lex->token : %s\n",lex->token->id);
		//printf(" token caught: %s\n", lex->token->id);
		//printf(" token->prev : %s\n", lex->token->prev->id);
		//printf(" token->next : %s\n", lex->token->next->id);
		lex->nb_of_tokens++;
		//printf("nb of tokens : %d\n",lex->nb_of_tokens);
		//printf("------------------nb = %d\n", lex->nb_of_tokens);
		lex->token->type =  lex->prev_decision.token_type;
		//printf("%s <%s>\n", lex->token->id, ft_getlabel_token_types(lex->token->type));
		//printf("nb_of_tokens = %d\n", lex->nb_of_tokens);
		//printf("1-%s    %s\n", lex->token->id, ft_getlabel_token_types(lex->token->type));
		//printf("2-%s    %s\n", lex->temp, ft_getlabel_token_types(lex->token->type));
		free(lex->temp);
		lex->temp = NULL;
	}
	return (0);
}

int	ft_lex_keep(t_lex *lex)
{
	//printf("in ft_keep\n");
	(void)lex;
	return (0);
}

int	ft_lex_drop(t_lex *lex)
{
	(void)lex;
	//printf("in ft_drop\n");
	//if (lex->temp)
	//{
	//	free(lex->temp);
	//	lex->temp = NULL;
	//}
	return (0);
}

int	ft_lex_take(t_lex *lex)
{
	//printf("in ft_take\n");
	lex->nb_taken_char++;
	return (0);
}

int	ft_lex_skip(t_lex *lex)
{
	(void)lex;
	//printf("in ft_skip\n");
	//ft_lex_record(lex);
	return (0);
}

int	ft_lex_record(t_lex *lex)
{
	char	*temp1;
	char	*temp2;

	//printf("in ft_record\n");
	//printf("taken char : %d\n", lex->nb_taken_char);
	//printf("lex->temp : %s\n", lex->temp);
	if (lex->nb_taken_char)
	{
		if (!lex->temp)
		{
			lex->temp = malloc(sizeof(char));
			ft_bzero(lex->temp, sizeof(char));
			temp1 = lex->temp;
		}
		else
		{
			temp1 = ft_strndup(lex->temp, 0);
			free(lex->temp);
		}
		temp2 = ft_substr(lex->user_input - lex->nb_taken_char, 0, lex->nb_taken_char);
		lex->temp = ft_strjoin(temp1, temp2);
		//printf("lex->temp : %s\n", lex->temp);
		free(temp1);
		free(temp2);
		lex->nb_taken_char = 0;
	}
	return (0);
}

int	ft_lex_end(t_lex *lex)
{
	//printf("in ft_end\n");
	ft_lex_take(lex);
	lex->prev_decision.token_type = lex->new_decision.token_type;
	ft_lex_catch(lex);
	return (0);
}

int	ft_lex_synt_err(t_lex *lex)
{
	//ft_freeall(lex);
	//lex->nb_of_tokens = 0;
	(void)lex;
	//printf("Here in the case of error : %d\n", lex->new_decision.token_type);
	//return (ft_msgerr(ERR_SYNTAX), 1);
	return (1);
}
