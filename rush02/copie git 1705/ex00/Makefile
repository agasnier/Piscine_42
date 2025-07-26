CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRCS = src/main.c    ##here put every .c that the exec need

OBJS = $(SRCS:.c=.o) ##obj are .o files made from compiling .c files with the -c option, here we tell the make file that we want every SRCS but replacing the extension .c by .o

NAME = rush-02 ##name of the exec

all: $(NAME)
	@echo "🔨 Exec Built"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@if [ -f $(OBJS) ]; then rm -f $(OBJS); echo "🚮 deleting every .o files"; fi

fclean:
	@if [ -f $(OBJS) ]; then rm -f $(OBJS); echo "🚮 deleting every .o files"; fi
	@if [ -f $(NAME) ]; then rm -f $(NAME); echo "🚮 deleting exec called rush-02"; fi

re: fclean $(NAME)
	@echo "👷🔨 Exec Rebuilt"

.SILENT:
.PHONY: all clean fclean re
