#!/bin/bash

# This script creates a folder that contains:
# Makefile
# *.hpp header file with a class passed by parameter to the script
# *.cpp file with the a basic implementation of the orthodox canonical class create in the .hpp file.


create_makefile()
{
path="$1/Makefile"
touch $path
cat << EOF | cat > $path
BLACK           := \033[1;30m                                                                           
RED             := \033[1;31m
GREEN           := \033[1;32m
YELLOW          := \033[1;33m
BLUE            := \033[1;34m
MAGENTA         := \033[1;35m
CYAN            := \033[1;36m
WHITE           := \033[1;37m
RESET           := \033[1;0m

NAME 		:= $3
NAME_DEB 	:= $3_deb
CC		:= c++
GCC		:= g++
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -std=c++98
DEBFLAGS	:= -g -fsanitize=address

INCS		:= $2.hpp
SRCS		:= main.cpp $2.cpp
OBJS		:= \$(SRCS:.cpp=.o)

all: \$(NAME)

\$(NAME):: \$(OBJS) \$(INCS)
	@printf "\$(GREEN)√ \$(RESET)\$(WHITE)%s\$(RESET)\n  " "$<"
	\$(CC) \$(CFLAGS) \$(CPPFLAGS) \$(OBJS) -o \$(NAME)

debug:: \$(OBJS) \$(INCS)
	@printf "\$(GREEN)√ \$(RESET)\$(YELLOW)[DEBUG-MODE]\$(RESET) \$(WHITE)%s\$(RESET)\n  " "$<"
	\$(GCC) \$(CFLAGS) \$(CPPFLAGS) \$(DEBFLAGS) \$(OBJS) -o \$(NAME_DEB)

%.o : %.cpp Makefile
	@printf "\$(GREEN)√ \$(RESET)\$(WHITE)%s\$(RESET)\n  " "$<"
	\$(CC) \$(CFLAGS) \$(CPPFLAGS) -c $< -o \$@

clean:
	@rm -vf *.o

fclean: clean
	@rm -vf \$(NAME) \$(NAME_DEB)

re: fclean all
	@echo "\n==========================================="
	@echo "|| \033[1;32m√\033[0m Recompiled  \033[1;33m\$(NAME)\033[0m"
	@echo "==========================================="

.PHONY: all clean fclean re
EOF

	printf " \033[1;32m¬\033[0m Makefile has been created ($path)\n"
}

to_lowercase() 
{
	lowercase=$(echo "$1" | tr '[:upper:]' '[:lower:]')
	echo $lowercase
}
to_uppercase() 
{
	uppercase=$(echo "$1" | tr '[:lower:]' '[:upper:]')
	echo $uppercase
}

create_hpp_file()
{
path="$1/$2.hpp"
touch $path
cat << EOF | cat > $path
#ifndef $4_H 
# define $4_H 

# include <iostream>
# include <string>

class $2
{
public:
	$2(void);
	$2(const $2 &other);
	$2 &operator=(const $2 &$3);
	~$2(void);
	std::string getName(void) const; 
private:
	std::string _name;
};

#endif

EOF
printf " \033[1;32m¬\033[0m $2.hpp has been created ($path)\n"
}

create_cpp_file()
{
path="$1/$2.cpp"
touch $path
cat << EOF | cat > $path
#include "$2.hpp"

$2::$2(void)
{
std::cout << ":: $2 has been created." << std::endl; 
}

$2::$2(const $2 &other)
{
if (this != &other)
{
	this->_name = other.getName();
}
std::cout << ":: $2 has been deep copied." << std::endl; 
}
$2 &$2::operator=(const $2 &other)
{
if (this != &other)
{
	this->_name = other.getName();
}
std::cout << ":: $2 has been deep assigned." << std::endl; 
return (*this);
}

$2::~$2(void){}

std::string $2::getName(void) const
{
return (this->_name);
}

EOF
printf " \033[1;32m¬\033[0m $2.cpp has been created ($path)\n"
}

create_main()
{
path="$1/main.cpp"
touch $path
cat << EOF | cat > $path
#include "$2.hpp"

int main (void)
{
$2	$3;

std::cout << ":: My name is " << $3.getName() << std::endl;
return (0);
}
EOF
printf " \033[1;32m¬\033[0m main.cpp crated ($path)\n"
}

# Config Variables
folder=""
conffile="CPPcreator.sh"
classname="BaseClass"
lowercase="baseclass"
uppercase="BASECLASS"
counter=-1
cpy=0

count_folders()
{
	for item in *; do
		# echo "Comparing item $item" 
		if [ -d "$item" ] && [[ $(basename "$item") == $10* ]]; then
			((counter++))
		fi
		# echo "No args $counter"
	done
}

create_mod_folder()
{
	printf "\033[1;33m=> ?\033[0m Would you like to create a new  \033[1;32m Mod \033[0m folder? (y/n) "
	read res
	if [ "$res" != y ]; then
		printf " :: \033[1;31mX\033[0m Aborting Mod creation\n"
		exit 1
	fi
	count_folders "Mod"
	((counter++))
	folder="Mod0$counter"
	classname=$1
	echo $classname
	mkdir -p $folder
	mkdir -p $folder/assets
	cp -vf Makefile $folder
	cp -vf $conffile $folder
	folder="$folder/ex00"
	mkdir -p $folder
	echo "Created folder project $folder"
}

create_ex_folder()
{
	printf " \033[1;33m=> ?\033[0m Would you like to create a new \033[1;32mexercice\033[0m folder (\033[1;34m$1\033[0m)? (y/n) "
	read res
	if [ $res != y ]; then
		printf " :: \033[1;31mX\033[0m Aborting Exercice creation\n"
		exit 0
	fi
	count_folders "ex"
	# echo "ex0x folders: $counter";
	if [ -d "ex00" ]; then
		printf " \033[1;33m=> ?\033[0m Would you like to copy files form another \033[1;32mexercice\033[0m folder (\033[1;34m$1\033[0m)? (y/n) "
		read $res2
		echo $res2;
		if [ $res2 = y ]; then
			printf " \033[1;33m=> \033[0m Insert folder: "
			read src
			cdir=$(pwd)/$src
			if [ -d  "$cdir" ]; then
				echo "";
				cpy=1;		
			else
				printf " :: \033[1;31mX\033[0m Dir $src not found\n"
				exit 0
			fi
		fi
	fi
	((counter++))
	classname=$1
	echo $classname
	folder="ex0$counter"
	mkdir -p $folder 
	lowercase=$(to_lowercase "$1")
	uppercase=$(to_uppercase "$1")
	if [ $cpy -eq 1 ]; then
		printf " :: \033[1;32mV\033[0m  Copying \033[1;34m$src\033[0m files in \033[1;34m$folder\033[0m\n"
		cp -vf "$src"/* "ex0$counter"
	fi
}

# Create folders
if [ $# -eq 0 ]; then
	create_mod_folder $2
elif [ $# -eq 2 ]; then
	if [ $1 = MOD ]; then
		create_mod_folder $2
	elif [ $1 = EX ]; then
		create_ex_folder $2
	fi
	lowercase=$(to_lowercase "$2")
	uppercase=$(to_uppercase "$2")
fi
if [ $counter -gt -1 ]; then
	if [ $cpy -eq 0 ]; then
		create_makefile "$folder" "$classname" "$lowercase"  
		create_main "$folder" "$classname" "$lowercase"
	fi
	create_hpp_file "$folder" "$classname" "$lowercase" "$uppercase"
	create_cpp_file "$folder" "$classname"
	printf " :: \033[1;32mV\033[0m  Created project files in \033[1;34m$folder\033[0m\n"
	exit 0
fi
echo "Couldn't create project folder or files"
exit 1

