# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 22:08:10 by abrunet           #+#    #+#              #
#    Updated: 2020/11/25 14:28:29 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	test

#######   DIRECTORIES   #######
HEADERS		=	include
SRCDIR		=	examples
OBJDIR		=	obj

DIRS		=	$(patsubst $(SRCDIR)%, $(OBJDIR)%, $(shell find $(SRCDIR) -type d))

##########   FLAGS   ##########
CXFLAGS		=	-Wall					\
			-Wextra					\
			-Werror					\
			-Wpadded				\
			-std=c++17				\
			-pedantic				\
			-g -O0

INCFLAG		=	-I $(HEADERS)

#########   SOURCES   #########
SRCS		=	$(shell find $(SRCDIR) -type f -o -type l -name "*.cc")

OBJS		=	$(patsubst $(SRCDIR)%.cc, $(OBJDIR)%.o, $(SRCS))

DEPENDS		=	${OBJS:.o=.d}

#########   COLORS   ##########
STD		=	\033[0m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m

##########   RULES   ##########
all	: $(NAME)

$(NAME)	: $(OBJS)
	@printf "$(YELLOW)%-45s$(STD)" "Building executable $@ ..."
	@$(CXX) $(CXFLAGS) $(INCFLAG) $(OBJS) -o $@
	@echo "$(GREEN)DONE$(STD)"

-include $(DEPENDS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	@mkdir -p $(DIRS)
	@printf "%-45s" " > Compiling $* ..."
	@$(CXX) $(CXFLAGS) -MMD $(INCFLAG) -c $< -o $@
	@echo '✓'

stripped: $(NAME)
	@printf "$(YELLOW)%-45s$(STD)" "Stripping executable $(NAME) ..."
	@strip $(NAME)
	@echo "$(GREEN)DONE$(STD)"

clean	:
	@if [ -d $(OBJDIR) ]; then \
		printf "$(YELLOW)%-45s$(STD)" "Removing objects ...";\
		/bin/rm -rf $(OBJDIR);\
		echo "$(GREEN)DONE$(STD)";\
	fi;

fclean	: clean
	@if [ -f $(NAME) ]; then \
		printf "$(YELLOW)%-45s$(STD)" "Removing $(NAME) ...";\
		/bin/rm -f $(NAME);\
		echo "$(GREEN)DONE$(STD)";\
	fi;

re	: fclean all

.PHONY	: all $(NAME) stripped clean fclean re
