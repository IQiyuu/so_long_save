NAME = scotch.a
LIB = libft/libft.a

FILES = map_manager\
		moves\
		pathfinder\
		reef\
		struct_init\
		struct_init_bis\
		term_graph\
		utils\
		window_manager\
		graph_moves\
		ennemy_manager\
		end_game\
		animation\
		key_manager

S = $(foreach f, $(FILES), srcs/$(f).c)

OBJ = $(S:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I headers/ -I minilibx/include
G_FLG = -fsanitize=address minilibx/libmlx42.a -lglfw -L "/Users/$(shell echo $(USER))/.brew/opt/glfw/lib/"

C1			= $(shell bc <<< "((($(CMP_COUNT)*100)/($(CMP_TOTAL) / 2))*255)/200")
C2			= $(shell bc <<< "((($(CMP_COUNT)*100)/($(CMP_TOTAL) / 2))*255)/100")
C4			= $(shell bc <<< "255 - (((($(CMP_COUNT) - ($(CMP_TOTAL) / 2))*100)/($(CMP_TOTAL) / 2))*255)/100")
C5			= $(shell bc <<< "255 - $(C1)")
CMP_TOTAL	= $(shell awk -F' ' '{printf NF}' <<< "$(S) $(S_BON)")
CMP_COUNT	= $(shell ls | grep -c '\.o')

CLEAR		= "\x1b\2K\r
GREEN		= \x1b[38;2;0;255;0m
WHITE		= \x1b[0m
CMP_OK		= has been successfully compiled!                                                    \n
CMP_DELETE	= has been successfully deleted!													 \n

RBW_P1		= \x1b[38;2;$(C4);255;$(C5)m $(CMP_COUNT) / $(CMP_TOTAL) » $<                                                    
RBW_P2		= \x1b[38;2;255;$(C2);$(C1)m $(CMP_COUNT) / $(CMP_TOTAL) » $<                                                    


all: $(NAME)

run: all
	./so_long

$(NAME): $(LIB) $(OBJ)
	@ar -rcs scotch.a $(OBJ)
	@gcc -o so_long srcs/main.c scotch.a $(CFLAGS) $(G_FLG) -g
	@printf "\n$(WHITE)> $(GREEN)$(NAME) $(CMP_OK)$(WHITE)"

.c.o:
	@gcc $(CFLAGS) -o $@ -c $<
	@$(eval CMP_COUNT = $(shell expr $(CMP_COUNT) + 1))
	@if [ $(CMP_COUNT) -gt $(shell expr $(CMP_TOTAL) / 2) ]; \
		then printf $(CLEAR)>$(RBW_P1)";\
		else printf $(CLEAR)>$(RBW_P2)";\
	fi

libft/libft.a:
	@make -C libft/
	@cp $(LIB) ./scotch.a

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)
	@printf "> $(GREEN)all .o $(CMP_DELETE)$(WHITE)"

fclean: clean
	@rm -rf $(NAME) $(LIB) ./so_long
	@printf "> $(GREEN)$(NAME), libft.a and so_long $(CMP_DELETE)$(WHITE)"

re: fclean all

.PHONY: all bonus clean fclean re
