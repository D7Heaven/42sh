##
## Makefile for  in /home/jeanj/Rendu/PSU_2015/PSU_2015_minishell2
## 
## Made by Jean Jonathan
## Login   <jeanj@epitech.net>
## 
## Started on  Tue Apr 12 18:57:02 2016 Jean Jonathan
## Last update Mon May 30 14:41:45 2016 Remi
##

CC=	gcc

NAME=	42sh

SRC_DIR	:= src
OBJ_DIR := obj

SRC	:= main.c \
           alias.c \
           builtins.c \
           builtins2.c \
           file.c \
           helper.c \
           tree.c \
           check.c \
           list.c \
           helper2.c \
           tree2.c \
           exec.c \
	   pipe.c \
	   tree3.c

SRC	:= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ	:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

LIB=	-Llib -lmy

CFLAGS=	-I include/ -W -Wall -Wextra
CDEBUG=	-O2 -g -ggdb

ECHO=	echo -e
RM=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@$(ECHO) '\033[0;32m> Compiled\033[0m'

clean	:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) \#*#
	@$(ECHO) '\033[0;31m> Directory cleaned\033[0m'


fclean	: clean
	$(RM) $(NAME)
	@$(ECHO) '\033[0;31m> Remove executable\033[0m'

re	: fclean all

.PHONY	: all clean fclean re

debug	: $(OBJ)
	$(CC) $(INC) $(CDEBUG) -o $(NAME) $(OBJ) $(LIB)
	@$(ECHO) '\033[0;33m> Mode Debug: done\033[0m'
