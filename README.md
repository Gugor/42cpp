# 42 Cpp Modules
This proyects is a cluster of small `c++` projects focused in learning c++ and OPP. This project is divided in 9 modules which give you some exercecies to solve tasks in c++.

----

# CPP Module creator
In order to handle module and exercice creation, I've designed a tool that is able to create modules and exercices with simple `make` commands. 
> [!NOTE]
> This tool has been develloped in Linux ecosystem.

## Prerequisites
- GNU Make ≥ 3.8
- Bash shell
- Execute permissions: `chmod +x CPPcreator.sh`


## Folder and files system
CPP Module proyects has a hierachical structure in wich you store several exercices in a `Mod0X` directory.

```
|_ /                  # root project's folder. I called it `/cppmods`
|__ Makefile
|__ CPPcreator.sh
|__ Mod00
|___ assets           # created to store Mod info such the subject or other files or documentation you are interested on.
|___ Makefile
|___ CPPcreator.sh
|___ex00
|____ Makefile
|____ BaseClass.hpp
|____ BaseClass.cpp
|____ main.cpp
|___ex01
|___ ex0N
|__ Mod01
|__ ...
|__ Mod09
|__ ...
```

- Each exercice has a `Makefile` and `.hpp` and `.cpp` files.
- Each Module folder has a `Makefile` and `CPPcreator.sh` besides folder for each exercice.
```bash
chmod +x CPPcreator.sh # ensure permissions to the script
```
> [!IMPORTANT]
> both files need to be in the same folder to work.

## How to use it
CPPcreator has some intelligence and acts differently depending in wich folder you are working on.

### Create new Mod directory
Doing `make` in `root` directory will create a consecutive `Mod0X` folder and and ex00 directory with a default clase.

```bash
make                                    # create a new Mod0X and ex00 inside with a default class.
make CLASSNAME="MyCustomizedClassname"  # the same as make but customize the name of your classs.
```

### Remove directory
You can also remove folders using this tool, by executing:
```bash
# Helps you to remove the last Mod0X directory created when executed in root
make rm-last
```

### Create exercice directory
You can create a new `ex0X` directory inside a `Mod0X`folder.

Enter in the `Mod0X` directory you want to create the exercice.
```bash
cd Mod00/
```

Do `make` to create a consecutive default exercice directory.
> [!NOTE]
> In case you had already created `ex0X`directory, CPP Creator will ask you if you want to copy the files form another directory.

```bash
make                                    # create new ex0x folder with default class.
make CLASSNAME="MyCustomizedClassname"  # the same as make but customize your class name.
```

### Remove directory
You can also remove folders using this tool:
```bash
make rm-last        # removes the last ex0X folder in a Mod0X directory.
make rm-exercices   # removes all ex0X folders in a Mod0X directory.
```




  



