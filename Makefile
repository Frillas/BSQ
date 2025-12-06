NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
OBJ_DIR = ./obj

SRC = main.c\
	  handler.c\
	  handler_utils.c\
	  print.c\
	  read.c\
	  read_utils.c\
	  square.c\
	  utils.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean: 
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
