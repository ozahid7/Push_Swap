PUSH_SWAP = push_swap
PUSH_SWAP_B = push_swap_b
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I ./inc
BUILD = build
BUILD_B = build

FILES = ft_printf/ft_argp ft_printf/ft_hexa ft_printf/ft_printf  ft_printf/ft_putchar\
		ft_printf/ft_putnbr ft_printf/ft_putstr ft_printf/ft_unsignednumber\
		push_swap_utilis_fun push_swap push_swap_split \
		
		


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