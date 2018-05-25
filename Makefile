##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile of the source file
##

ROOT	=	.

SRC_DIR	=	sources

CC	=	gcc

SYM_PRE =  	--redefine-sym add=hashmap_add \
	  	--redefine-sym del=hashmap_del \
	  	--redefine-sym get=hashmap_get \
	  	--redefine-sym has=hashmap_has \
	  	--redefine-sym hash=hashmap_hash \

SYM_NAM = 	-K hashmap_add \
		-K hashmap_del \
		-K hashmap_get \
		-K hashmap_has \
		-K hashmap_hash


NAME	=	libhashmap.so

REAL	=	$(ROOT)/release

SRC	=	$(SRC_DIR)/utils.c	\
		$(SRC_DIR)/hashmap.c

WARN	=	-W -Wall -Wextra

CFLAGS	=	-I $(ROOT)/includes $(WARN) -fPIC

LDFLAGS	=	-shared

LIB	?=	1

TEST	?=	0

DEB	?=      0

V	?=	@

OBJS	=	$(patsubst $(SRC_DIR)/%.c, $(REAL)/%.o, $(SRC))

ifeq ($(DEB), 1)
	CFLAGS += $(G)
endif

ifeq ($(TEST), 1)
	CFLAGS	+= $(MACRO)
endif

#COLOR

GREEN	=		\e[1;32m

WHITE	=		\e[0m

ORANGE	=		\e[1;33m

RED	=		\e[1;35m

BLUE	=		\e[1;34m

all:			$(NAME)

$(NAME):		echo_build $(REAL)/$(NAME)
			$(V)cp $(REAL)/$(NAME) $(ROOT)
			$(V)printf "$(GREEN)Dup $(NAME) into root directory.$(WHITE)\n"


$(REAL)/$(NAME):	buildrepo $(OBJS)
			$(V)printf "$(GREEN)Compile sources.$(WHITE)\n"
			$(V)printf "$(BLUE)Changing symbols names.$(WHITE)\n"
			$(V)objcopy $(SYM_PRE) $(REAL)/hashmap.o $(REAL)/hashmap.o
			$(V)$(CC) -o $(REAL)/$(NAME) $(OBJS) $(LDFLAGS)
			$(V)printf "$(GREEN)Linking obj and Libraries.$(WHITE)\n"
			$(V)objcopy --strip-unneeded $(SYM_NAM) $(REAL)/$(NAME) $(REAL)/$(NAME)
			$(V)printf "$(BLUE)Removing unneeded symbols.$(WHITE)\n"

$(REAL)/%.o:		$(SRC_DIR)/%.c
			$(V)printf "$(BLUE)Compiling [$(GREEN)$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]\n$(WHITE)"
			$(V)$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)
clean:
			$(V)rm -rf $(OBJS)
			$(V)printf "$(ORANGE)Removing object files.$(WHITE)\n"

fclean:			clean
			$(V)rm -f $(REAL)/$(NAME)
			$(V)rm -f $(ROOT)/$(NAME)
			$(V)rm -rf $(REAL)
			$(V)printf "$(ORANGE)Removing binary file.$(WHITE)\n"

buildrepo:
			$(call make-repo)

re:			fclean
			$(V)make --no-print-directory all

echo_build:		echo_debug
			$(V)printf "$(GREEN)Begin of the build !\n$(ORANGE)Warnings : \n$(WHITE)"

echo_debug:
			$(V)if [ $(DEB) == 1 ]; then\
				printf "$(RED)Debug mode initialized.$(WHITE)\n";\
			fi

.PHONY: clean fclean debug all re echo_build echo_debug buildrepo

define make-repo
	$(V)for dir in $(dir $(OBJS)); \
	do 			  \
		mkdir -p $$dir;	  \
	done
endef
