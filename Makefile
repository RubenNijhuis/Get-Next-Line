# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rubennijhuis <rubennijhuis@student.coda      +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/13 16:51:02 by rubennijhui   #+#    #+#                  #
#    Updated: 2022/05/07 19:28:50 by rubennijhui   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#=====================================#
#========= General variables =========#
#=====================================#

NAME := get-next-line.a
INCLUDE_DIR := include
SRC_DIR := src
OBJS_DIR := objs

#=====================================#
#============ Input files ============#
#=====================================#

INC := -I $(INCLUDE_DIR)

SRCS := get_next_line.c \
		get_next_line_utils.c 

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

#=====================================#
#========= Command arguments =========#
#=====================================#

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g $(INC)
LDFLAGS =

#=====================================#
#=============== Rules ===============#
#=====================================#

objs/%.o:src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $^
	@echo "🔨 Compiling: $^"
	
all: $(NAME)

$(NAME): $(OBJS)
	@ar -cr $(NAME) $(OBJS)
	@echo "✅ Built $(NAME)"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "🧹 Done cleaning $(NAME) objects"

fclean: clean
	@rm -f $(NAME)
	@echo "🧹 Done cleaning $(NAME) archive"

norm:
	@echo "\033[92m========= $(NAME) norm ========\033[0m"
	@-norminette $(INCLUDE_DIR)
	@-norminette $(SRC_DIR)
	@echo "\033[92m========= $(NAME) norm ========\033[0m"

re: fclean all

.PHONY: all re clean fclean
