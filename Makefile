# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 16:57:32 by ikarjala          #+#    #+#              #
#    Updated: 2022/04/19 21:06:44 by ikarjala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT		::= ./

NAME	::= fdf
BIN		::= $(ROOT)$(NAME)

CFUNC	::= \
main

SRC_DIR		::= $(ROOT)src/
OBJ_DIR		::= $(ROOT)
SRC			::= $(addprefix $(SRC_DIR),$(addsuffix .c,$(CFUNC)))
OBJ			= $(SRC:.c=.o)
INC_DIR		= $(SRC_DIR) $(LIB_DIR)/
LIB_DIR		::= $(ROOT)libft
LIB			::= ft
LIBS		?= $(addprefix $(LIB_DIR)/lib,$(addsuffix .a,$(LIB)))

CMD_INC		?= $(addprefix -I, $(INC_DIR))

CFLAGS		::= -Wall -Wextra -Werror
DEBUG_FLAGS	::= -Wimplicit -Wconversion -g -fsanitize=address -fsanitize=memory
CC			::= clang

##	BUILD ====
all: $(NAME)
$(NAME): lib
	@echo	$(BMSG_BIN)
	$(CC) -c $(CFLAGS) $(SRC) $(CMD_INC)
	$(CC) -o $(BIN) $(OBJ) -L$(LIB_DIR) -l $(LIB)
	@echo	$(BMSG_FIN)
lib:
ifeq (,$(wildcard $(LIBS)))
	@echo '\_,-->' $(BMSG_LIB)
	make -C $(LIB_DIR)	re
endif
install: re clean
debug:
	@echo	$(BMSG_DBG)
	$(CC) -c $(CFLAGS) $(DEBUG) $(SRC) $(CMD_INC)
	$(CC) -o $(BIN) $(OBJ) -L$(LIB_DIR) -l $(LIB)
	@echo	$(BMSG_FIN)

##	CLEAN ====
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(BIN) $(LIB)
	rm -f libft.so
lclean: clean
	make -C $(LIB_DIR)	fclean
re: fclean all

.PHONY: lib clean lclean fclean re install
COL_NUL		::= \e[0;0m
COL_HL		::= \e[0;33m
COL_CS		::= \e[0;32m

BMSG_BIN	= '$(COL_HL)' '$(NAME) :: Starting build...' '$(COL_NUL)'
BMSG_LIB	= '$(COL_HL)' '$(LIBS) :: Compiling libraries...' '$(COL_NUL)'
BMSG_FIN	= '$(COL_CS)' '$(NAME) :: Build success!' '$(COL_NUL)'
BMSG_DBG	= '$(COL_HL)' '$(NAME) :: Starting =DEBUG= build...' '$(COL_NUL)'

##	UTILS ====
CMD_NORME	::= norminette -R CheckForbiddenSourceHeader
norme:
	$(CMD_NORME) $(SRC_DIR)*.c $(LIB_DIR)/*.c $(addsuffix *.h,$(INC_DIR))
