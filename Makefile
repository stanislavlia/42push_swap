NAME = push_swap
CC = @gcc
RM = @rm -f

FLAGS = # -Wall -Wextra -Werror 

YELLOW = \033[33;49;1m
CYAN = \033[33;36;1m
END = \033[0;0m


SRC = $(shell find . -name '*.c')

INCLUDES = -I includes

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)
			@echo "$(YELLOW)${NAME} ✔️"
			@echo "$(CYAN)Mandatory files compiled successfully ✔️$(END)"

%.o: %.c includes/*.h
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@


clean:
	${RM} ${OBJ}
	@echo "$(CYAN)Object files have been deleted ✔️$(END)"

fclean: clean
	${RM} ${NAME}

libft:
	make re -C $(LIBFT_DIR)

re: clean fclean all

.PHONY: all clean fclean re 
