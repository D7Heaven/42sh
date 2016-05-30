##
## Makefile for Makefile in /home/jean_j/rendu/Piscine_C_J10/lib/my
## 
## Made by jean jonathan
## Login   <jean_j@epitech.net>
## 
## Started on  Fri Oct  9 09:13:41 2015 jean jonathan
## Last update Sun Jan 17 17:36:18 2016 JEAN Jonathan
##

SRC	=	*.c

LIB	=	libmy.a

CC	=	cc -c $(SRC) -Wall

AR	=	ar rc $(LIB) *.o

RANLIB	=	ranlib $(LIB)

RM	= 	rm -f

all:
	$(CC)
	$(AR)
	$(RANLIB)
	cp -f libmy.a ../
	cp -f my.h ../../include/

clean:	
	$(RM) *.o

fclean:
	$(RM) *.o
	$(RM) $(LIB)
	$(RM) ../$(LIB)

re:	fclean all
