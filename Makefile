# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:57:00 by gle-roux          #+#    #+#              #
#    Updated: 2023/02/16 13:00:45 by gle-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                          BANNER & COLOR SETINGS                              #
#------------------------------------------------------------------------------#

#Banner
define BANNER1
                       _                                 
 _ __  _   _       ___| |__        _________      ____ _ _ __  
| '_ \| | | |     / __| '_ \      / _______ \ /\ / / _` | '_ \ 
| |_) | |_| |_____\__ \ | | |_____\__ \    \ V  V / (_| | |_) |
| .__/ \__,___________/_| |_|_________/     \_/\_/ \__,_| .__/ 
|_|                                                     |_|    
endef
export BANNER1

# Colors settings
R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
Y = $(shell tput -Txterm setaf 3)
Z = $(shell tput -Txterm setaf 5)
C = $(shell tput -Txterm setaf 6)
W = $(shell tput -Txterm setaf 7)

#------------------------------------------------------------------------------#
#                                   TESTS                                      #
#------------------------------------------------------------------------------#

# For testing purposes only
TEST1_ARGS = "3 1 2"
TEST2_ARGS = 4 7 2
TEST3_ARGS = -18 47 65
TEST4_ARGS = 5 2 -3
TEST5_ARGS = 3 3 2
TEST6_ARGS = 3 A 2

#------------------------------------------------------------------------------#
#                                   TOOLS                                      #
#------------------------------------------------------------------------------#
define HELP
$Z---------------------------------------------------------------
$YTools available$Z
make checkup		$Y->$Z Run tests and norminette
make eval		$Y->$Z Open evaluation sheet
make help		$Y->$Z Display tools available
make mem		$Y->$Z Run test with leaks -atExit command
make norm		$Y->$Z Run Norminette
make pdf 		$Y->$Z Open PDF subject
make test		$Y->$Z Run a series of tests
---------------------------------------------------------------
endef
export HELP

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	= 	-Wall -Wextra -Werror

# Remove and Archives
ARCH	=	ar rcs
RM		=	rm -rf

# Dir. and files names
NAME		=	push_swap

SRCS_DIR	=	./src/
SRCS_LIST	=	index.c \
				main.c \
				parse.c \
				push.c \
				reverse.c \
				rotate.c \
				sort.c \
				stack.c \
				swap.c \
				utils.c \
				utils_moves.c \
				utils_parse.c \
				utils_sort.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR	=	./obj/
OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

HEADER_DIR	=	./includes/
HEADER_LIST	=	push_swap.h
HEADER	 	=	$(addprefix $(HEADER_DIR), $(HEADER_LIST))

LIBFT_DIR	=	./libft/
LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_H		=	$(LIBFT_DIR)includes/libft.h

#------------------------------------------------------------------------------#
#                                  RULES                                       #
#------------------------------------------------------------------------------#

# Creation of the executable
all: dir $(NAME)
	@echo $Y"$$BANNER1"$W
	@echo "				$Zmade by $Cgle-roux\n$W"

# Compile library
$(NAME): $(OBJS)
	@echo "\n\n$W>>>>>>>>>>>>>>>>>>>>> $Zpush_swap is $Gdone ✅ $W<<<<<<<<<<<<<<<<<<<<<"
	@echo "\n$W--------------------------- $Zlibft.a $W----------------------------"
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "\n-------------- $ZIf help is needed, type $Ymake help $W--------------"
	@echo "\n>>>>>>>>>>>>>>>>>>>> $ZPUSH_SWAP is $Gready ✅$W <<<<<<<<<<<<<<<<<<<<"

# Create all files .o (object) from files .c (source code)
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@printf "\n $GCompiling : $Z$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

#Create directory for *.o files
dir:
	@mkdir -p $(OBJS_DIR)

# Removes objects
clean:
	@echo "\n\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YCLEANING $W<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$W----------- $Z$(NAME) : $(OBJS_DIR)objects was $Rdeleted ❌$W-----------"

# Removes executables
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@echo "\n$W-------- $ZAll exec. and archives successfully $Rdeleted ❌$W--------\n"
	@echo "$W>>>>>>>>>>>>>>>>>>>>> $ZCleaning is $Gdone ✅ $W<<<<<<<<<<<<<<<<<<<<<\n\n"

# Removes objects and executables and remake
re: fclean
	@$(MAKE) all

# Displays tools available
help:
	@echo "$$HELP"

# For testing purposes
test:
	@echo "\n\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YTESTING $W<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
	@echo "$W---------------------- $Z./push_swap 3 1 2 $W-----------------------"
	@./$(NAME) $(TEST1_ARGS)
	@echo "$W---------------------- $Z./push_swap 4 7 2 $W-----------------------"
	@./$(NAME) $(TEST2_ARGS)
	@echo "$W-------------------- $Z./push_swap -18 47 65 $W---------------------"
	@./$(NAME) $(TEST3_ARGS)
	@echo "$W---------------------- $Z./push_swap 5 2 -3 $W----------------------"
	@./$(NAME) $(TEST4_ARGS)
	@echo "$W>>>>>>>>>>>>>>>>>>>>>>>>> $YEND TESTS ✅ $W<<<<<<<<<<<<<<<<<<<<<<<<<\n"

norm :
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>> $YNORMINETTE $W<<<<<<<<<<<<<<<<<<<<<<<<<<$Z\n"
	@norminette $(SRCS) $(HEADER) $(LIBFT_DIR)
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>> $YNORMINETTE ✅ $W<<<<<<<<<<<<<<<<<<<<<<<<<<"

#lsan : $(LSAN)
#lsan : CFLAGS += -Wno-gnu-include-next -ILeakSanitizer -LLeakSanitizer -llsan -lc++
#$(LSAN) :
#	@if [ ! -d "LeakSanitizer"]; then git clone https://github.com/mhahnFr/LeakSanitizer.git; fi
#	@$(MAKE) -C LeakSanitizer

# Verifications before sumission
checkup: 
	@$(MAKE) test
#	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YMEMORY $W<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
#	$(MAKE) lsan
#	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>> $YMEMORY ✅ $W<<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@$(MAKE) norm

# Opens the subject
pdf:
	@open https://cdn.intra.42.fr/pdf/pdf/66937/fr.subject.pdf

eval:
	@echo https://github.com/rizky/42-corrections/blob/master/push_swap.pdf

mem:
	@echo "\n\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YMEMORY $W<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
	@echo "$W---------------------- $Z./push_swap 3 1 2 $W-----------------------"
	@leaks -atExit -- ./$(NAME) $(TEST1_ARGS)
	@echo "$W---------------------- $Z./push_swap 3 1 2 $W-----------------------"
	@valgrind --leak-check=full ./$(NAME) $(TEST1_ARGS)
	@echo "$W---------------------- $Z./push_swap 3 3 2 $W-----------------------"
	@leaks -atExit -- ./$(NAME) $(TEST5_ARGS)
	@echo "$W---------------------- $Z./push_swap 3 3 2 $W-----------------------"
	@valgrind --leak-check=full ./$(NAME) $(TEST5_ARGS)
	@echo "$W---------------------- $Z./push_swap 3 A 2 $W-----------------------"
	@leaks -atExit -- ./$(NAME) $(TEST6_ARGS)
	@echo "$W---------------------- $Z./push_swap 3 A 2 $W-----------------------"
	@valgrind --leak-check=full ./$(NAME) $(TEST6_ARGS)
	@echo "$W>>>>>>>>>>>>>>>>>>>>>>>>> $YEND TESTS ✅ $W<<<<<<<<<<<<<<<<<<<<<<<<<\n"

	valgrind --leak-check=full ./programme

# Avoids file-target name conflicts
.PHONY: all dir clean fclean re test norm lsan checkup pdf help mem eval