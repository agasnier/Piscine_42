# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algasnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/30 10:25:25 by algasnie          #+#    #+#              #
#    Updated: 2025/07/30 11:40:29 by algasnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRC_DIR = src/

BUILD_DIR = build/

SRCS = 	\
		$(SRC_DIR)main.c \
		$(SRC_DIR)structs.c \
		$(SRC_DIR)find.c \
		$(SRC_DIR)parsing.c \
		$(SRC_DIR)parsing_utils.c \

OBJS = $(subst src,$(BUILD_DIR),$(SRCS:.c=.o))

INCLUDE = -I include

NAME = bsq 

all: $(NAME)

$(BUILD_DIR):
		@mkdir -p $@

$(NAME): $(BUILD_DIR) $(OBJS)
		@$(CC) $(OBJS) -o $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)%.c
		@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $< 

clean:
		rm -f $(OBJS)
		rm -rf $(BUILD_DIR)

fclean:
		rm -f $(OBJS)
		rm -rf $(BUILD_DIR)
		rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
