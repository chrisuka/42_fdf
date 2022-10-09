# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 16:57:32 by ikarjala          #+#    #+#              #
#    Updated: 2022/10/09 21:13:56 by ikarjala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT	:= ./
NAME	:= libft.a
BIN		= $(ROOT)$(NAME)
SO		= $(NAME:.a=.so)

FUNC_P12	= \
ft_isdigit ft_isalpha ft_isalnum ft_isprint ft_isascii \
ft_tolower ft_toupper ft_strlen ft_itoa ft_atoi \
\
ft_putchar_fd ft_putchar ft_putstr_fd ft_putstr ft_putendl_fd ft_putendl \
ft_putnbr_fd ft_putnbr \
\
ft_bzero ft_memset ft_memdel ft_memcpy ft_memccpy ft_memmove ft_memchr \
ft_memcmp ft_memalloc \
\
ft_strcmp ft_strncmp ft_strequ ft_strnequ \
ft_strchr ft_strrchr ft_strstr ft_strnstr \
ft_strcat ft_strncat ft_strlcat ft_strcpy ft_strncpy ft_striter ft_striteri \
ft_strnew ft_strdel ft_strclr ft_strdup ft_strsub ft_strmap ft_strmapi \
ft_strjoin ft_strtrim ft_strsplit

FUNC_BONUS	= \
ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap

FUNC_EXTRA	= \
ft_isspace ft_isupper ft_islower ft_isxdigit ft_toinverse \
ft_abs ft_log10 ft_pow ft_strword ft_wordcount ft_mapi \
ft_swap ft_memdup ft_memclr ft_aiter ft_freearray \
\
ft_lstlen ft_lstclen ft_lstn ft_lstbuflen \
ft_lstinit ft_lstcut ft_lststr \
ft_bool2sign ft_min ft_max \
ft_bset64

CFUNC	= $(FUNC_P12) $(FUNC_BONUS) $(FUNC_EXTRA)

SRC_DIR		= $(ROOT)src/
OBJ_DIR		= $(ROOT)obj/
INC_DIR		= $(ROOT)

SRC			= $(CFUNC:%=$(SRC_DIR)%.c)
OBJ			= $(CFUNC:%=$(OBJ_DIR)%.o)
INCLUDE		= $(addprefix -I , $(INC_DIR))
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror
DEBUG_FLAGS	= -g -fsanitize=address
RIGOR_FLAGS	= -Wimplicit -Wconversion
SOFLAGS		= -nostartfiles -fPIC
CC			= clang
AR			= ar -cr

.PHONY: all clean fclean re db debug so

all: $(NAME)
$(NAME): $(OBJ) Makefile
	@echo	$(BMSG_AR)
	@$(AR)		$(BIN) $(OBJ)
	@ranlib		$(BIN)
	@echo	$(BMSG_FIN)
$(SO): NAME := $(SO)
$(SO): $(NAME)

$(OBJ): $(OBJ_DIR)%.o:$(SRC_DIR)%.c Makefile
	@printf	"$<    \t\t... "
	@$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@
	@echo	"DONE"

clean:
	@echo	'Cleaning objects...'
	@$(RM) $(OBJ)
fclean: clean
	@echo	'Removing binaries...'
	@$(RM) $(BIN) $(BIN:.a=.so)
re: fclean all

so: CFLAGS += $(SOFLAGS)
so: BMSG_FORM := SO (dylib)
so: $(SO)

db: debug
debug: CFLAGS += $(DEBUG_FLAGS)
debug: BMSG_FORM := =DEBUG=
debug: $(NAME)

PRE_BUILD_MESSAGE:
	@echo	$(BMSG_BIN)
	@echo	$(BMSG_CC)
	@echo	$(BMSG_RELINK)

BMSG_BIN	= '$(PURPLE)$(NAME) :: Starting $(BMSG_FORM) build... $(RESET)'
BMSG_FORM	:= deploy

BMSG_CC		= "$(PURPLE)$(NAME) :: Using $(CC) with $(CFLAGS) $(RESET)"
BMSG_RELINK	= "$(PURPLE)$(NAME) :: Compiling C objects:"
BMSG_AR		= "$(PURPLE)$(NAME) :: Linking..."
BMSG_FIN	= "$(GREEN)$(NAME) :: Build success! $(RESET)"

RED		:= \033[1;31m
GREEN	:= \033[1;32m
PURPLE	:= \033[1;35m
CYAN	:= \033[1;36m
RESET	:= \033[0m

##	UTILS ====
CMD_NORME	= norminette -R CheckForbiddenSourceHeader
norme:
	$(CMD_NORME) $(SRC_DIR)*.c $(INC_DIR)*.h
