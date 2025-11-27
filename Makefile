NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJ_DIR = ./obj

SRC = main.c\
	  free.c\
	  handler.c\
	  handler_utils.c\
	  print.c\
	  read.c\
	  read_utils.c\
	  square.c\
	  square_utils.c\
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
