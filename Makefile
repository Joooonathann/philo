NAME 		= 	philo
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror $(INCLUDE)
INCLUDE 	=	-I include

SRC			=	./src/is_valid_input.c\
				./src/utils.c\
				./src/init_simulation.c\
				./src/start_simulation.c\
				./src/process_philo.c\
				./philo.c
				
OBJ			=	${SRC:.c=.o}

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re