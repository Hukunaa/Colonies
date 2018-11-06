SHELL 	:= /bin/bash
NAME	= ./bin/project

CC	= g++
INC 	= -Iinclude
LIBS	= -lSDL2 -lSDL2_image
CFLAGS	= -W -Wall -Werror -pedantic -Wconversion -Wwrite-strings -Wfloat-equal -Wunreachable-code -std=c++17
LDFLAGS =
PREFLAGS= -E -P

SRCDIR  = src
INCDIR	= include
OBJDIR	= obj
BINDIR	= bin
TEMPDIR	= templates

SRC	:= $(shell find $(SRCDIR) -name "*.cpp")
OBJ	= $(SRC:%.cpp=$(OBJDIR)/%.o)

RMD	= rm -f
RMDIR	= rm -rf
ECHO 	= echo -e
MKDIR	= mkdir -p

FILE_UPPER = $(shell echo $(file) | tr 'a-z' 'A-Z')

all	: $(NAME)

$(NAME)	: $(OBJ)
	@$(ECHO) '\033[0;32m> Linking\033[0m'
	$(CC) $(LDFLAGS) $+ -o $@ $(INC) $(LIBS)
	@$(ECHO) '\033[0;32m> Linked\033[0m'

$(OBJ): $(OBJDIR)/%.o: %.cpp
	@$(ECHO) '\033[0;34m> Compiling\033[0m' $<
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) $(INC) $(LIBS) -c -o $@ $<

clean	:
	@$(RM) $(OBJ)
	@$(RM) *~
	@$(RM) ./**/*~
	@$(RM) \#*#
	@$(ECHO) '\033[0;31m> Directory cleaned\033[0m'

fclean	: clean
	@$(RM) $(NAME)
	@$(RMDIR) $(OBJDIR)
	@$(ECHO) '\033[0;31m> Remove executable\033[0m'

re	: fclean all

prepro	:
	$(CC) $(PREFLAGS) $(INC) $(SRC) | cat

start	:
	@$(MKDIR) $(SRCDIR)
	@$(MKDIR) $(INCDIR)
	@$(MKDIR) $(BINDIR)
	@cp $(TEMPDIR)/main.cpp $(SRCDIR)/main.cpp

generate:
ifdef file
	@cat $(TEMPDIR)/custom_class.h | sed s/__CUSTOM_CLASS_/__$(FILE_UPPER)_/g | sed s/CUSTOM_CLASS/$(file)/g > $(INCDIR)/$(file).h
	@cat $(TEMPDIR)/custom_class.cpp | sed s/CUSTOM_CLASS/$(file)/g > $(SRCDIR)/$(file).cpp
	@$(ECHO) '\033[0;32m> $(file) generated\033[0m'

else
	@$(ECHO) '\033[0;31m> No filename given\033[0m'

endif