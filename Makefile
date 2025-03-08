
CLASSNAME	:= BaseClass
RMEX		:= ex00
CONF_FILE	:= ./CPPcreator.sh
SHELL		:= /bin/bash

all: $(CLASSNAME)

$(CLASSNAME) :
	@if [ -f $(CONF_FILE) ]; then \
		cdir=$$(pwd); \
		echo $$cdir; \
		bdir=$$(basename $$cdir); \
		if [[ "$$bdir" == Mod* ]]; then \
			bash $(CONF_FILE) EX  $(CLASSNAME); \
		else \
			bash $(CONF_FILE) MOD  $(CLASSNAME); \
		fi \
	else \
		printf " :: \033[1;32mX\033[0m $(CONF_FILE) does not exists. Check the spell of the file and in the CONF_FILE variable in this file.\n"; \
	fi

rm-exercices :
	@counter=-1; \
	cdir=$$(pwd); \
	bdir=$$(basename $$cdir); \
	if [[ "$$bdir" != Mod0* ]]; then \
		printf ":: \033[1;31mX\033[0m For security reasons this command only can be executed inside a Mod0X folder \n"; \
		exit 0; \
	else \
		printf ":: \033[1;31m!!\033[0m Are you sure you want to \033[1;31mremove ALL exercices\033[0m folders? (y/n): "; \
		read res && \
		if [ "$$res" = "y" ]; then \
			rm -vfR ex*; \
		else \
			printf ":: \033[1;31mX\033[0m Aborting remove exercice folders\n"; \
		fi; \
	fi;


rm-last :
	@printf ":: \033[1;31m!!\033[0m Are you sure you want to \033[1;31mremove ALL exercices\033[0m folders? (y/n): "
	@read res && \
	if [ "$$res" = "y" ]; then \
		rm -vfR ex*; \
	else \
		printf ":: \033[1;31mX\033[0m Aborting remove exercice folders\n"; \
		exit 0; \
	fi; \
	counter=-1; \
	cdir=$$(pwd); \
	bdir=$$(basename $$cdir); \
	if [[ "$$bdir" == Mod* ]]; then \
		folder=ex; \
	else \
		folder=Mod; \
	fi; \
	for item in *; do \
		if [ -d "$$item" ] && [[ $$(basename "$$item") == $$folder* ]]; then \
			((counter++)) \
		fi; \
        done; \
	if [[ "$$folder" == ex ]]; then \
		echo "Removing folder ex0$$counter"; \
		rm -vfR "ex0$$counter"; \
	elif [[ "$$folder" == Mod ]]; then \
		echo "Removing folder Mod0$$counter"; \
		rm -vfR "Mod0$$counter"; \
	fi; 
