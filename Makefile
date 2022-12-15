# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 23:48:05 by mnau              #+#    #+#              #
#    Updated: 2022/11/22 11:41:54 by mnau             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS			= -Wall -Wextra -Werror

SRCS			=	ft_printf.c \
					ft_printf_utils.c \
					
					
OBJS			= $(SRCS:.c=.o)

RM			= rm -f

NAME			= libftprintf.a

TEST			= ft-print-test

# COLORS #

BLACK	= \033[0;30m
RED 	= \033[0;31m
GREEN 	= \033[0;32m
YELLOW 	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN 	= \033[0;36m
WHITE	= \033[0;37m

# BOLD COLORS #

BBLACK	= \033[1;30m
BRED 	= \033[1;31m
BGREEN 	= \033[1;32m
BYELLOW = \033[1;33m
BBLUE	= \033[1;34m
BPURPLE	= \033[1;35m
BCYAN 	= \033[1;36m
BWHITE	= \033[1;37m



.c.o:			$(SRCS)
				@printf "$(BCYAN)⏳ Compiling... $(PURPLE)<$<> 🌸\n\e[0m"
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			@printf "$(BCYAN)⌛️ Compiling... $(GREEN)\"$(NAME)\"\e[0m 🌸\n"
			@ar rcs $(NAME) $(OBJS)

#$(TEST):		$(OBJS)
#			@printf "$(CYAN)Compiling... \"$(TEST)\"... \n\e[0m"
#			@$(CC) -o $(TEST) $(OBJS)
#			@printf "\e[1;36mExecuting \"$(TEST)\"... \n\e[0m"
#			@./$(TEST)

clean:
			@printf "$(BRED)Cleaning project... ✅\n\e[0m"
			@$(RM) $(OBJS)

fclean:
			@printf "$(BRED)Force cleaning project... ✅\n\e[0m"
			@$(RM) $(OBJS) $(NAME) $(TEST)

re:			fclean all

.PHONY:			all clean fclean re
