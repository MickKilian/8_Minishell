# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 18:34:29 by mbourgeo          #+#    #+#              #
#    Updated: 2022/09/21 22:33:30 by mbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	=	all

LEX_SRCS	=	lexer_main.c lexer_utils.c lexer_ascii.c lexer_memory.c lexer_list.c \
				lexer_actions.c lexer_error.c lexer_init_decisions.c lexer_initializations.c \
				lexer_apply_decision.c
LEX_SRCDIR	=	src/lex
LEX_PATH	=	$(addprefix $(LEX_SRCDIR)/, $(LEX_SRCS))
LEX_OBJDIR	=	obj
LEX_OBJS	=	$(patsubst $(LEX_SRCDIR)/%, $(LEX_OBJDIR)/%, $(LEX_PATH:.c=.o))

BONUS_SRCS	=	bonus_main.c
BONUS_SRCDIR	=	minishell_bonus/src
BONUS_PATH	=	$(addprefix $(BONUS_SRCDIR)/, $(BONUS_SRCS))
BONUS_OBJDIR	=	minishell_bonus/obj
BONUS_OBJS	=	$(patsubst $(BONUS_SRCDIR)/%, $(BONUS_OBJDIR)/%, $(BONUS_PATH:.c=.o))

MD_DEP_DIR	=	dep
LEX_DEP	=	$(patsubst $(LEX_OBJDIR)/%.o, $(MD_DEP_DIR)/%.d, $(LEX_OBJS))
BN_DEP_DIR	=	minishell_bonus/dep
BONUS_DEP	=	$(patsubst $(BONUS_OBJDIR)/%.o, $(BN_DEP_DIR)/%.d, $(BONUS_OBJS))

#MD_HD_SRCS	=	minishell.h
MD_HD_DIR	=	inc
MD_HD_PATH	=	$(addprefix $(MD_HD_DIR)/, $(MD_HD_SRCS))
BN_HD_SRCS	=	minishell_bonus.h
BN_HD_DIR	=	minishell_bonus/inc
BN_HD_PATH	=	$(addprefix $(BN_HD_DIR)/, $(BN_HD_SRCS))

NAME		=	minishell
NAME_BONUS	=	minishell_bonus/minishell_bonus
LIB1_DIR	=	lib/gnl
LIB1_NAME	=	libgnl.a
HDLIB1_DIR	=	$(LIB1_DIR)/inc
CC			=	gcc
RM			=	rm -f
RMD			=	rm -rvf
MK			=	mkdir -p
#DEBUG		=	-g -fsanitize=address
#DEBUG		=	-g -fsanitize=thread
DEBUG		=	-g
CFLAGS		=	-Wall -Wextra -Werror
#LFLAGS		=	-lpthread -lreadline
DFLAGS		=	-MMD -MF
#gcc code.c -L/usr/local/lib -I/usr/local/include -lreadline
#################################

all:		$(NAME)

$(NAME):	$(LEX_OBJS) | $(LIB1_NAME) Makefile
				$(CC) $(CFLAGS) $(DEBUG) $^ -I$(MD_HD_DIR) -I$(HDLIB1_DIR) -L$(LIB1_DIR) -lgnl -o $@

bonus:		$(BONUS_OBJS) | $(LIB1_NAME) Makefile 
				$(CC) $(CFLAGS) $(DEBUG) $^ -I$(BN_HD_DIR) -I$(HDLIB1_DIR) -L$(LIB1_DIR) -lgnl -o $(NAME_BONUS)

$(LIB1_NAME):
				$(MAKE) -C $(LIB1_DIR) all

-include $(LEX_DEP)
$(LEX_OBJDIR)/%.o:		$(LEX_SRCDIR)/%.c | $(LIB1_NAME) $(LEX_OBJDIR) $(MD_DEP_DIR) $(MD_HD_PATH)
							$(CC) $(CFLAGS) $(DEBUG) $(DFLAGS) $(MD_DEP_DIR)/$*.d -I$(MD_HD_DIR) -I$(HDLIB1_DIR) -c $< -o $@

$(LEX_OBJDIR) $(MD_DEP_DIR):		;
				@$(MK) $@

-include $(BONUS_DEP)
$(BONUS_OBJDIR)/%.o:		$(BONUS_SRCDIR)/%.c | $(LIB1_NAME) $(BONUS_OBJDIR) $(BN_DEP_DIR) $(MD_HD_PATH)
							$(CC) $(CFLAGS) $(DEBUG) $(DFLAGS) $(BN_DEP_DIR)/$*.d -I$(BN_HD_DIR) -I$(HDLIB1_DIR) -c $< -o $@

$(BONUS_OBJDIR) $(BN_DEP_DIR):		;
				@$(MK) $@

clean:		;
				@$(RMD) $(LEX_OBJDIR) $(MD_DEP_DIR)
				@$(RMD) $(BONUS_OBJDIR) $(BN_DEP_DIR)
				$(MAKE) -C $(LIB1_DIR) fclean

fclean:		clean
				@$(RM) $(NAME)
				@$(RM) $(NAME_BONUS)

re:			fclean all

.PHONY:		all clean fclean re bonus
