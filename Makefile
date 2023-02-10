##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

# Compilation Settings
CC			:=		g++
FLAGS		:=		-std=c++17 -Wall -g
VALG		:=		valgrind --leak-check=full --log-file=report.txt
SFML		:=		-lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window -lsfml-network

# Binary File Settings
BINDIR		:=		bin
BINEXT		:=		app
BINNAME		:=		template
BIN			:=		$(BINDIR)/$(BINNAME).$(BINEXT)

# Source Files Settings
SRCDIR		:=		src
SRCEXT		:=		cpp
SRC			:=		$(shell find $(SRCDIR) -type f -name *.$(SRCEXT))

# Objects Files Settings
OBJDIR		:=		obj
OBJEXT		:=		o
OBJ			:=		$(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SRC:.$(SRCEXT)=.$(OBJEXT)))

# Dependencies Settings
LIB			:=		lib
INCLUDE		:=		include

# Command Settings
RM			:=		rm -rf

# Display Settings
RED			:=		\033[1;31m
GREEN		:=		\033[1;32m
YELLOW		:=		\033[1;33m
BLUE		:=		\033[1;34m
MAGENTA		:=		\033[1;35m
CYAN		:=		\033[1;36m
NC			:=		\033[0m
TEXT		:=		$(GREEN)➜$(NC)  $(CYAN)Root$(BLUE)
INTRO		:=		$(YELLOW)================================================================$(NC)\n

.PHONY:		all	clean	fclean	re	compil	valgrind	remove_windows	directories
.SILENT:	all	$(OBJ)	$(BIN)	clean	fclean	re	compil	valgrind	remove_windows	directories

all:	$(BIN)

# Compiled all .c file not compiled in .o
$(OBJ): $(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -I$(INCLUDE) -c -o $@ $<
	printf "$(TEXT) file $(RED)$@$(BLUE) created$(NC)\n"

# Compiled project with lib and all .o files
$(BIN):	$(OBJ)
	$(CC) $(FLAGS) -I$(INCLUDE) -o $@ $^ $(SFML)
	printf "\n$(INTRO)$(YELLOW) · Compilation Succesfully Finished$(NC)\n$(INTRO)\n"

# Removes all .o files
clean:
	find $(OBJDIR) -type f -name *.$(OBJEXT) -exec printf "$(TEXT) file $(RED){}$(BLUE) removed$(NC)\n" \;
	$(RM) $(OBJDIR)/*

# Removes all useless files, binary and library
fclean:	clean
	find $(BINDIR) -type f -name *.$(BINEXT) -exec printf "$(TEXT) binary $(RED){}$(BLUE) removed$(NC)\n" \;
	$(RM) $(BIN)
	$(RM) report.txt
	$(RM) vgcore.*
	$(RM) report.txt.core.*

# Clean all and compile the project
re:	fclean all

# Recompile and Start the project
compil:	re
	./$(BIN)

# Start the project with valgrind in a report file
valgrind:
	$(VALG) ./$(BIN)

# Create all folder needed by the compilation
directories:
	mkdir -p $(BINDIR)
	mkdir -p $(SRCDIR)
	mkdir -p $(OBJDIR)
	mkdir -p $(LIB)
	mkdir -p $(INCLUDE)

# Remove useless file used by windows
remove_windows:
	$(RM) bin/*
	$(RM) lib/*
	$(RM) include/SFML
	$(RM) Template.vcxproj*
	printf "$(TEXT) Windows files has been removed$(NC)\n"
