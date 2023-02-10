##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

# Compilation
CXX			:=		g++ -g
FLAGS		:=		-std=c++17 -Wall -Wextra
SFML		:=		-lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window -lsfml-network

# Binary
BINDIR		:=		.
BINNAME		:=		Wanted
BIN			:=		$(BINDIR)/$(BINNAME)

# Source
SRCDIR		:=		src
SRCEXT		:=		cpp
SRC			:=		$(shell find $(SRCDIR) -type f -name *.$(SRCEXT))

# Objects
OBJDIR		:=		obj
OBJEXT		:=		o
OBJ			:=		\
$(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SRC:.$(SRCEXT)=.$(OBJEXT)))

# Library / Include
LIB			:=		-L./lib/
INC			:=		-I./include/

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
LINE			:=		\n================================================\n
INTRO_SUCCES	:=		$(GREEN)➜$(NC)
INTRO_FAILED	:=		$(RED)➜$(NC)

.PHONY:		all	clean	fclean	re
.SILENT:	all	$(OBJ)	$(BIN)	clean	fclean	re

all:	$(BIN)

# Compiled all .c file not compiled in .o
$(OBJ): $(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	mkdir -p $(dir $@)
	$(CXX) $(FLAGS) $(INC) -c -o $@ $< $(SFML) \
	&& printf "$(GREEN)➜  $(BLUE)file $(CYAN)$@ $(GREEN)created$(NC)\n" \
	|| printf "$(RED)➜  $(BLUE)file $(CYAN)$@ $(RED)failed$(NC)\n"

# Compiled project with lib and all .o files
$(BIN):	$(OBJ)
	$(CXX) $(FLAGS) $(INC) -o $@ $^ $(SFML) \
	&& printf "$(YELLOW)$(LINE) · Compilation Done$(LINE)$(NC)\n" \
	|| printf "$(RED)$(LINE) · Compilation Failed$(LINE)$(NC)\n"

# Removes all .o files
clean:
	find $(OBJDIR) -type f -name *.$(OBJEXT) \
	-exec printf "$(GREEN)➜  $(BLUE)file $(CYAN){} $(BLUE)removed$(NC)\n" \;
	$(RM) $(OBJDIR)/*

# Removes all useless files, binary and library
fclean:	clean
	find $(BINDIR) -type f -name $(BINNAME) \
	-exec printf "$(GREEN)➜  $(BLUE)binary $(CYAN){} $(BLUE)removed$(NC)\n" \;
	$(RM) $(BIN)
	$(RM) vgcore.*
	$(RM) report.*

# Clean all and compile the project
re:	fclean all
