BLACK           := \033[1;30m                                                                           
RED             := \033[1;31m
GREEN           := \033[1;32m
YELLOW          := \033[1;33m
BLUE            := \033[1;34m
MAGENTA         := \033[1;35m
CYAN            := \033[1;36m
WHITE           := \033[1;37m
RESET           := \033[1;0m

NAME 		:= easyfind
NAME_DEB 	:= easyfind_deb
CC		:= c++
GCC		:= g++
CFLAGS		:= -Wall -Wextra -Werror -I ./
CPPFLAGS	:= -std=c++98
DEBFLAGS	:= -g -fsanitize=address

INCS		:= easyfind.hpp
SRCS		:= main.cpp
OBJS		:= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):: $(OBJS) $(INCS)
	@printf "$(GREEN)√ $(RESET)$(WHITE)%s$(RESET)\n  " "$<"
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME)

debug:: $(OBJS) $(INCS)
	@printf "$(GREEN)√ $(RESET)$(YELLOW)[DEBUG-MODE]$(RESET) $(WHITE)%s$(RESET)\n  " "$<"
	$(GCC) $(CFLAGS) $(CPPFLAGS) $(DEBFLAGS) $(OBJS) -o $(NAME_DEB)

%.o : %.cpp Makefile
	@printf "$(GREEN)√ $(RESET)$(WHITE)%s$(RESET)\n  " "$<"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -vf *.o

fclean: clean
	@rm -vf $(NAME) $(NAME_DEB)

re: fclean all
	@echo "\n==========================================="
	@echo "|| \033[1;32m√\033[0m Recompiled  \033[1;33m$(NAME)\033[0m"
	@echo "==========================================="

.PHONY: all clean fclean re
