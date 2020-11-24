# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 22:08:10 by abrunet           #+#    #+#              #
#    Updated: 2020/11/24 16:18:12 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	deeplib.a

#######   DIRECTORIES   #######
HEADERS		=	include
SRCDIR		=	srcs
OBJDIR		=	obj

DIRS		=	$(patsubst $(SRCDIR)%, $(OBJDIR)%, $(shell find $(SRCDIR) -type d))

##########   FLAGS   ##########
CCFLAGS		=	-Wall					\
			-Wextra					\
			-Werror					\
			-pedantic				\
			-std=c++17				\
			-g -O0 #debug

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
	@printf "$(YELLOW)%-45s$(STD)" "Building static library $@ ..."
	@ar -rcL $@ $(OBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)DONE$(STD)"

-include $(DEPENDS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	@mkdir -p $(DIRS)
	@printf "%-45s" " > Compiling $* ..."
	@$(CXX) $(CCFLAGS) -MMD $(INCFLAG) -c $< -o $@
	@echo '✓'

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

.PHONY	: all stripped clean fclean re
