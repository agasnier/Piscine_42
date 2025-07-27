CC = cc

CFLAGS = -Wall -Werror -Wextra -g

##here put every .c that the exec need 
SRCS = \
	$(SRC_DIR)main.c \
	$(SRC_DIR)convert.c \
	$(SRC_DIR)pars.c \
	$(SRC_DIR)stock.c

SRC_DIR = src/

BUILD_DIR = build/

OBJS = $(subst src,$(BUILD_DIR),$(SRCS:.c=.o)) ##obj are .o files made from compiling .c files with the -c option, here we tell the make file that we want every SRCS but replacing the extension .c by .o

INCLUDE = -Iinclude

NAME = rush-02 ##name of the exec


##Background_Colors
RESET  = \033[0m
B_GREY=  \033[40m
B_RED=   \033[41m
B_GREEN= \033[42m
B_YELLOW=\033[43m
B_BLUE=  \033[44m
B_PURPLE=\033[45m
B_CYAN=  \033[46m
B_WHITE= \033[47m

##Font_Colors
BLACK           =   \033[0;30m
FBLACK          =   \033[1;30m
RED             =   \033[0;31m
FRED            =   \033[1;31m
GREEN           =   \033[0;32m
FGREEN          =   \033[1;32m
FBROWN         =   \033[1;33m
BROWN          =   \033[0;33m
BLUE            =   \033[0;34m
FBLUE           =   \033[1;34m
PURPLE          =   \033[0;35m
FPURPLE         =   \033[1;35m
CYAN            =   \033[0;36m
FCYAN           =   \033[1;36m
FWHITE          =   \033[1;37m
WHITE           =   \033[0;37m
RESET           =   \033[0m

all: $(NAME)

$(BUILD_DIR):
	@mkdir -p $@

$(NAME): $(BUILD_DIR) $(OBJS)
	@printf "$(B_PURPL)$(FRED)      ___           ___           ___           ___       __   __$(RESET)\n"
	@printf "$(B_PURPL)$(FBLUE)     /\  \         /\__\         /\  \         /\__\     /  \ /  \ $(RESET)\n"
	@printf "$(B_PURPL)$(FRED)    /::\  \       /:/  /        /::\  \       /:/  /     |  |    /$(RESET)\n"
	@printf "$(B_PURPL)$(FBLUE)   /:/\:\  \     /:/  /        /:/\ \  \     /:/__/      |  |   /     $(RESET)\n"
	@printf "$(B_PURPL)$(FRED)  /::\~\:\  \   /:/  /  ___   _\:\~\ \  \   /::\  \ ___  \__/  /__$(RESET)\n"
	@printf "$(B_PURPL)$(FBLUE) /:/\:\ \:\__\ /:/__/  /\__\ /\ \:\ \ \__\ /:/\:\  /\__\ $(RESET)\n"
	@printf "$(B_PURPL)$(FRED) \/_|::\/:/  / \:\  \ /:/  / \:\ \:\ \/__/ \/__\:\/:/  / $(RESET)\n"
	@printf "$(B_PURPL)$(FBLUE)    |:|::/  /   \:\  /:/  /   \:\ \:\__\        \::/  /  $(RESET)\n"
	@printf "$(B_PURPL)$(FRED)    |:|\/__/     \:\/:/  /     \:\/:/  /        /:/  /   $(RESET)\n"
	@printf "$(B_PURPL)$(FBLUE)    |:|  |        \::/  /       \::/  /        /:/  /    $(RESET)\n"
	@printf "$(B_PURPL)$(FRED)     \|__|         \/__/         \/__/         \/__/     $(RESET)\n"
	@printf "\n\n✅$(FGREEN)Program compiled successfully$(RESET)\n"
	@$(CC) $(OBJS) -o $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	@if [ -f $(OBJS) ]; then rm -f $(OBJS);            printf "🚮$(FCYAN)deleting every .o files$(RESET)\n"; fi
	@if [ -d $(BUILD_DIR) ]; then rm -rf $(BUILD_DIR); printf "🚮$(FCYAN)deleting build directory$(RESET)\n" ; fi
fclean:
	@if [ -f $(OBJS) ]; then rm -f $(OBJS);            printf "🚮$(FCYAN)deleting every .o files$(RESET)\n"; fi
	@if [ -d $(BUILD_DIR) ]; then rm -rf $(BUILD_DIR); printf "🚮$(FCYAN)deleting build directory$(RESET)\n" ; fi
	@if [ -f $(NAME) ]; then rm -f $(NAME);            printf "🚮$(FCYAN)deleting exec called rush-02$(RESET)\n"; fi

re: fclean $(NAME)
	@printf "👷🔨$(FBROWN)Exec Rebuilt $(RESET)\n"

.PHONY: all clean fclean re
