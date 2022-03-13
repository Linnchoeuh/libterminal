NAME = terminal
CC = gcc
CCLIB = ar
PREFIX = lib
EXTENSION = .a
FULLNAME = $(PREFIX)$(NAME)$(EXTENSION)
SRC = $(shell find ./ -name "*.c")
OBJ = $(SRC:.c=.o)
ECHO = /bin/echo -e
INCLUDEPATH = ./include/
INCLUDEFILE = $(shell find $(INCLUDEPATH)*.h)
INSTALLPATH = /home/${LOGNAME}/.froot/
INCLUDEFILENAME = $(shell find $(INCLUDEPATH)*.h -type f -printf "$(INSTALLPATH)include/%f\n")
CFLAG = -g3 -std=c11
ERRCFLAG = -Wextra -Wall -Werror

DEFLT	=	"\033[00m"
PINK	=	"\033[0;36m"
GREEN	=	"\033[1;32m"
TEAL	=	"\033[1;36m"
RED		=	"\033[0;31m"
BLINK 	= 	"\033[1;92m"
SBLINK	= 	"\033[0m"

all:$(FULLNAME)

%.o : %.c
	@ $(CC) -o $@ -c $< -I$(INCLUDEPATH) $(CFLAG) $(ERRCFLAG) && \
	$(ECHO) $(BLINK) "[OK]"$(SBLINK) $(PINK) $< $(DEFLT) || \
	$(ECHO) $(RED) "[KO]" $(PINK) $< $(DEFLT)

$(FULLNAME):$(OBJ)
	@ $(CCLIB) -rsc $(FULLNAME) $(OBJ) && \
	$(ECHO) $(BLINK) "[LIB - OK]"$(SBLINK) $(PINK) $(FULLNAME) $(DEFLT) || \
	$(ECHO) $(RED) "[LIB - KO]" $(TEAL) $(FULLNAME) $(DEFLT)

clean:
	@ find -name "*.o" -delete && find -name "*~" -delete && \
	$(ECHO) $(BLINK) "[CLEAN SUCCESS]" $(DEFLT)

fclean:
	@find . -name "*.so" -delete -or -name "*.exe" -delete \
        -or -name "*.a" -delete -or -name "*.o" -delete    \
        -or -name "*~" -delete -or -name "vgcore*" -delete \
		-or -name "a.out" -delete
	@$(ECHO) $(GREEN) "All temporal file deleted!" $(DEFLT)
	@find -name $(FULLNAME) -delete
	@$(ECHO) $(GREEN) "$(FULLNAME) deleted!" $(DEFLT)

re: 	fclean all

install:	all
	@mv $(FULLNAME) $(INSTALLPATH)lib/$(FULLNAME)
	@cp $(INCLUDEFILE) $(INSTALLPATH)include/
	@$(ECHO) $(GREEN) "Library installed!" $(DEFLT)

reinstall : fclean install

uninstall:
	@rm -f $(INSTALLPATH)lib/$(FULLNAME)
	@rm -f $(INCLUDEFILENAME)
	@$(ECHO) $(GREEN) "Library deleted!" $(DEFLT)
