# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 15:56:06 by azinchen          #+#    #+#              #
#    Updated: 2024/12/23 18:16:14 by azinchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME			=	philo

# Directories
SRC_DIR			=	./src
OBJ_DIR			=	./obj
INC_DIR			=	./include

# Compiler and compilation flags
CC				=	cc
CFLAGS			=	-g -pthread -Wall -Wextra -Werror
RM				=	rm -f

# Source files
SRC				=	philosophers.c \
					initialization.c \
					routine.c \
					threads.c \
					actions.c \
					printing.c \
					utils.c \
					args_validation.c \
					atoi_libft.c \
					errors.c \
					cleaners.c \

# Object files
OBJ				=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Colors
BLUE			=	\033[1;34m
GREEN			=	\033[1;32m
NC				=	\033[0m

# Build rules
all:				$(NAME)

$(NAME):			$(OBJ)
					@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
					@echo "$(GREEN)--> Created philo!$(NC)"

# Object file compilation
$(OBJ_DIR)/%.o: 	$(SRC_DIR)/%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Cleaning rules
clean:
					@$(RM) -r $(OBJ_DIR)
					@echo "$(BLUE)*.o files removed!$(NC)"
		
fclean:				clean 
					@$(RM) $(NAME)
					@echo "$(BLUE)All files removed!$(NC)"
			
re:					fclean all

.PHONY:				all clean fclean re
