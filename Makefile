NAME = ubercube
CC = g++
WIN_LDFLAGS = -lglfw3 -lglew32 -lopengl32 -lgdi32
INCLUDES = includes/
LIBS = libs/
FILES = main.cpp display.cpp
SRCS = $(addprefix src/,$(FILES))
OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME):
	$(CC) -c $(SRCS) -I $(INCLUDES) -L $(LIBS) $(WIN_LDFLAGS)
	$(CC) -o $(NAME) $(OBJS) -L $(LIBS) $(WIN_LDFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
