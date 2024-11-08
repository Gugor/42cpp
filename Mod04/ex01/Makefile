BLACK		:= \033[1;30m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
MAGENTA		:= \033[1;35m
CYAN		:= \033[1;36m
WHITE		:= \033[1;37m
RESET		:= \033[1;0m


NAME		:= polymorph 
NAME_TEST	:= polymorph-DEBUG 

CC		:= c++
GCC		:= g++
CFLAGS		:= -Wall -Wextra -Werror 
VFLAGS		:= -std=c++98 
DFLAGS		:= -g -fsanitize=leak -Wshadow

INCS		:= Animal.hpp Dog.hpp Cat.hpp Brain.hpp Brain.hpp 
SRCS		:= main.cpp \
			Animal.cpp \
			Dog.cpp \
			Cat.cpp \
			Brain.cpp \
			Brain.cpp
OBJS		:= $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME):: $(OBJS) $(INCS) 
	@printf "$(GREEN)√ $(RESET)$(WHITE)%s$(RESET)\n  " "$<"
	$(CC) $(DFLAGS) $(CFLAGS) $(OBJS) $(VFLAGS) -o $(NAME)

%.o : %.cpp Makefile
	@printf "$(GREEN)√ $(RESET)$(WHITE)%s$(RESET)\n  " "$<"
	$(CC) $(DFLAGS) $(CFLAGS) $(VFLAGS) -c $< -o $@

clean:
	@rm -vf *.o

test:: $(OBJS) $(INCS)
	@printf "$(GREEN)√ $(RESET)$(WHITE)%s$(RESET)\n  " "$<"
	$(GCC) $(DFLAGS) $(CFLAGS) $(OBJS) $(VFLAGS) -o $(NAME_TEST)

fclean: clean
	@rm -vf $(NAME)
	@rm -vf $(NAME_TEST)

re: fclean all
	@echo "\n==========================================="
	@echo "|| \033[1;32m√\033[0m Recompiled  \033[1;33m$(NAME)\033[0m"
	@echo "==========================================="

.PHONY: all clean fclean re
