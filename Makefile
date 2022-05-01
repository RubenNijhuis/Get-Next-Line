# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rubennijhuis <rubennijhuis@student.coda      +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/13 16:51:02 by rubennijhui   #+#    #+#                  #
#    Updated: 2022/05/01 11:35:05 by rubennijhui   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#=====================================#
#========= General variables =========#
#=====================================#

NAME := get-next-line
INCLUDE_DIR := include
SRC_DIR := src
OBJS_DIR := objs
OUTPUT := $(NAME).a

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
	@ar -cr $(OUTPUT) $(OBJS)
	@echo "✅ Built $(NAME) \n"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "🧹 Done cleaning $(NAME) objects"

fclean: clean
	@rm -f $(OUTPUT)
	@echo "🧹 Done cleaning $(NAME) archive \n"

norm:
	-norminette $(INCLUDE_DIR)
	-norminette $(SRC_DIR)

re: fclean all

.PHONY: all re clean fclean
