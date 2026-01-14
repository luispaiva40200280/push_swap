NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror -I.
# --- directoris and files needed to make push_swap --- #
AUX_DIR = libft_src/
SRC_DIR = src_pushswap/
AUX_SRC = $(AUX_DIR)aux_printf.c $(AUX_DIR)ft_atol.c $(AUX_DIR)ft_dprintf.c \
	   	  $(AUX_DIR)ft_split.c $(AUX_DIR)ft_strndup.c 
SORT_SRC = $(SRC_DIR)build_stack.c $(SRC_DIR)handler.c $(SRC_DIR)oper_stack_a.c \
		 $(SRC_DIR)sort_lst_smaller.c $(SRC_DIR)butterfly_sort.c \
		 $(SRC_DIR)nodes_utils.c  $(SRC_DIR)oper_stack_b.c $(SRC_DIR)parser_arr.c \
		 $(SRC_DIR)op_both_stacks.c

MAIN = main.c
BONUS_AUX = $(AUX_DIR)get_next_line.c $(AUX_DIR)get_next_line_utils.c
BONUS = checker_bonus.c
OBJS = $(SORT_SRC:.c=.o) $(AUX_SRC:.c=.o) $(MAIN:.c=.o)
#--- extra for making more appiling 
## --- COLLORS 
#\033: This is the ESC (Escape) character in octal.
  #It tells the terminal "Pay attention, a command is coming!"
  #[: Starts the control sequence.
  #0;31m: The actual code for the color use.
RESET = \033[0m #Resets all colors/styles back to default.
RED = \033[38;5;203m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
CYAN = \033[0;36m

#---all rules mandatory
   #--@ :> is used to hide the compiling mesage 
all: norm $(NAME)
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo " ✅🚀 $(GREEN)SUCCESS: $(NAME) is ready to use $(RESET)✅🚀"


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo " 💻 $(CYAN)Compiling: $(BLUE)$<$(RESET)"

clean:
	@for file in $(OBJS); do \
		printf "$(RED)Removing $$file ...$(RESET)\n"; \
		rm -f $$file; \
		sleep 0.02; \
	done
	@echo "$(YELLOW)OBJECTS REMOVE.$(RESET)"
	
fclean: clean
	@rm -f $(NAME)
	@rm -f checker
	@echo "$(RED)$(NAME) Remove..$(RESET)"

re: fclean 
	@echo " ✅ $(GREEN) RECOPILING... $(NAME)...$(RESET)🚀"
	@$(MAKE) all --no-print-directory
#--- norminette complaince 
norm:
	@echo "$(BLUE)Checking Norminette...$(RESET)"
	@norminette $(SRC_DIR) $(AUX_DIR) $(MAIN) push_swap.h | grep -v "ok!" || true	

bonus: all
	@$(CC) $(CFLAGS) $(filter-out $(MAIN:.c=.o), $(OBJS))  $(BONUS_AUX) $(BONUS) -o checker
	@echo " ✅🚀 $(GREEN)SUCCESS: your CHECKER is ready to use $(RESET)✅🚀"

.PHONY: all clean fclean re norm bonus