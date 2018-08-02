#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smickael <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/30 22:57:37 by smickael          #+#    #+#              #
#    Updated: 2018/03/30 22:57:41 by smickael         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

INC = -I ./includes/

FLAGS = -Wall -Wextra -Werror

SRCS_NAME = ft_memset.c \
		   ft_bzero.c \
		   ft_memcpy.c \
		   ft_memmove.c \
		   ft_memccpy.c \
		   ft_strchr.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_strcpy.c \
		   ft_strdup.c \
		   ft_strlen.c \
		   ft_strncpy.c \
		   ft_strcat.c \
		   ft_strncat.c \
		   ft_strlcat.c \
		   ft_strrchr.c \
		   ft_strstr.c \
		   ft_strnstr.c \
		   ft_strcmp.c \
		   ft_strncmp.c \
		   ft_atoi.c \
		   ft_isalpha.c \
		   ft_isdigit.c \
		   ft_isalnum.c \
		   ft_isascii.c \
		   ft_isprint.c \
		   ft_toupper.c \
		   ft_tolower.c \
		   ft_memalloc.c \
		   ft_itoa.c \
		   ft_memdel.c \
		   ft_putchar_fd.c \
		   ft_putchar.c \
		   ft_putendl_fd.c \
		   ft_putendl.c \
		   ft_putnbr_fd.c \
		   ft_putnbr.c \
		   ft_putstr_fd.c \
		   ft_putstr.c \
		   ft_strclr.c \
		   ft_strdel.c \
		   ft_strequ.c \
		   ft_striter.c \
		   ft_striteri.c \
		   ft_strjoin.c \
		   ft_strmap.c \
		   ft_strmapi.c \
		   ft_strnequ.c \
		   ft_strnew.c \
		   ft_strsplit.c \
		   ft_strsub.c \
		   ft_strtrim.c \
		   ft_lstnew.c \
		   ft_lstdelone.c \
		   ft_lstdel.c \
		   ft_lstadd.c \
		   ft_lstiter.c \
		   ft_lstmap.c \
		   ft_strndup.c \
		   ft_isspace.c \
		   ft_printf.c \
		   pf_bonus.c \
		   pf_character.c \
		   pf_number.c \
		   pf_parsing.c \
		   pf_string.c \
		   ft_putstr_free.c \
		   ft_pow.c \
		   ft_putwchar.c \
		   ft_wcharlen.c \
		   ft_wstrlen.c \
		   ft_putwstr.c 

SRCS_PATH = srcs/
OBJ_PATH  = obj/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) created"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAGS) $(INC) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
