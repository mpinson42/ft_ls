NAME = ft_ls

SRC = srcs/ft_ls.c srcs/ft_ls_R.c srcs/ft_ls_l.c srcs/ft_ls_rp.c srcs/main.c srcs/ft_pars.c srcs/ft_mod.c

FLAGS = -Wall -Wextra -Werror

SRC2 = ft_ls.o ft_ls_R.o ft_ls_l.o ft_ls_rp.o ft_mod.o ft_pars.o main.o

all: $(NAME)

%.o : %.c
	gcc -c -o $@ $^

$(NAME): $(SRC)
	@echo "mpinson" > auteur
	@make -C ./libft all
	@cp ./libft/libft.a ./lib
	gcc -I ./include/ lib/libft.a -o $(NAME) $(SRC)


clean:
	/bin/rm -f $(SRC2)
	@make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
