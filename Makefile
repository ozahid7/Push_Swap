PUSH_SWAP = push_swap
PUSH_SWAP_B = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INC = -I ./inc
BUILD = build
BUILD_B = build

FILES = ft_printf/ft_argp ft_printf/ft_hexa ft_printf/ft_printf  ft_printf/ft_putchar\
		ft_printf/ft_putnbr ft_printf/ft_putstr ft_printf/ft_unsignednumber\
		push_swap_utilis_fun push_swap push_swap_split ps_moves ps_parsing_fun ps_tree_five_sort\
		ps_position_fun ps_oneh_fiveh_fun ps_fun_2\

B_FILES = ft_printf/ft_argp ft_printf/ft_hexa ft_printf/ft_printf  ft_printf/ft_putchar\
		ft_printf/ft_putnbr ft_printf/ft_putstr ft_printf/ft_unsignednumber\
		push_swap_bonus/push_swap_utilis_fun_bonus push_swap_bonus/push_swap_bonus\
		push_swap_bonus/push_swap_split_bonus push_swap_bonus/ps_moves_bonus\
		push_swap_bonus/ps_parsing_fun_bonus\
		push_swap_bonus/ps_fun_2_bonus push_swap_bonus/ps_last_edition_fun\
		get_next_line/get_next_line_utils get_next_line/get_next_line\
		
		


OBJ = $(addprefix $(BUILD)/, $(FILES:=.o))

OBJ_B = $(addprefix $(BUILD_B)/, $(B_FILES:=.o))

all: $(PUSH_SWAP)

bonus: $(PUSH_SWAP_B)

$(PUSH_SWAP) : $(OBJ)
	$(CC) $(OBJ) -o $(PUSH_SWAP)
	
$(PUSH_SWAP_B) : $(OBJ_B)
	$(CC) $(OBJ_B) -o $(PUSH_SWAP_B)
	
$(BUILD)/%.o : src/%.c 
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	
$(BUILD_B)/%.o : src/%.c 
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	
clean :
	rm -rf $(BUILD) rm -rf $(BUILD_B)
fclean : clean
	rm -rf $(PUSH_SWAP) $(PUSH_SWAP_B)

re : fclean all

.PHONY : re fclean clean all