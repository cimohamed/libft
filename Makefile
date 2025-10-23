# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Library name
NAME = libft.a

# Source files (only selected)
SRC = ft_strlen.c ft_isascii.c ft_toupper.c

# Object files
OBJ = $(SRC:.c=.o)

# Header file
HDR = libft.h

# Default target: build the library
all: $(NAME)

# Build the library from object files
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Compile .c files to .o files, depends on header
%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Clean object files + library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
