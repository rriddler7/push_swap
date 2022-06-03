NAME = push_swap
FLAGS = -Wall -Werror -Wextra
CC = gcc
RM = rm -f

SOURCES_DIR = ./
SOURCES_LIST = main.c utills.c push_atoi.c parse.c operations_rotate.c operations_reverse.c operations_swap.c operations_push.c find_order.c sorting.c maxsorting.c
HEADERS_LIST = push_swap.h

SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))
OBJECTS_DIR = obj/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS    = $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

all: $(NAME)

$(NAME): $(OBJECTS_DIR) $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)

$(OBJECTS_DIR):
	mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c $(HEADERS_LIST)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM)r $(OBJECTS_DIR)

fclean: clean
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re
