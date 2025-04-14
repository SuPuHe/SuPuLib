# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 10:40:58 by omizin            #+#    #+#              #
#    Updated: 2025/04/14 11:10:16 by omizin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = SuPuLib.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

#DIRS
FT_PRINTF_DIR = ft_printf
GNL_DIR = get_next_line
LIBFT_DIR = libft

FT_PRINTF_SRCS_DIR = $(FT_PRINTF_DIR)/srcs
FT_PRINTF_OBJS_DIR = $(FT_PRINTF_DIR)/objs
FT_PRINTF_INC_DIR = $(FT_PRINTF_DIR)/includes

GNL_SRCS_DIR = $(GNL_DIR)/srcs
GNL_OBJS_DIR = $(GNL_DIR)/objs
GNL_INC_DIR = $(GNL_DIR)/includes

LIBFT_SRCS_DIR = $(LIBFT_DIR)/srcs
LIBFT_OBJS_DIR = $(LIBFT_DIR)/objs
LIBFT_INC_DIR = $(LIBFT_DIR)/includes

INCLUDE = -I$(FT_PRINTF_INC_DIR) -I$(GNL_INC_DIR) -I$(LIBFT_INC_DIR)

#SRCS
FT_PRINTF_SRCS_FILES = ft_printf.c ft_helpers.c ft_detailed_checks.c ft_print_str.c ft_print_char.c \
		ft_int_handle.c ft_int_helpers.c ft_print_int.c ft_helpers2.c ft_print_uns_ptr.c \
		ft_handle_hex.c ft_print_hex.c ft_print_other.c

FT_PRINTF_SRCS = $(addprefix $(FT_PRINTF_SRCS_DIR)/, $(FT_PRINTF_SRCS_FILES))

GNL_SRCS_FILES = get_next_line.c get_next_line_utils.c

GNL_SRCS = $(addprefix $(GNL_SRCS_DIR)/, $(GNL_SRCS_FILES))

LIBFT_SRCS_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c

LIBFT_SRCS := $(addprefix $(LIBFT_SRCS_DIR)/, $(LIBFT_SRCS_FILES))

#OBJS
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:$(FT_PRINTF_SRCS_DIR)/%.c=$(FT_PRINTF_OBJS_DIR)/%.o)
GNL_OBJS = $(GNL_SRCS:$(GNL_SRCS_DIR)/%.c=$(GNL_OBJS_DIR)/%.o)
LIBFT_OBJS = $(LIBFT_SRCS:$(LIBFT_SRCS_DIR)/%.c=$(LIBFT_OBJS_DIR)/%.o)

#ALL OBJS
OBJS = $(FT_PRINTF_OBJS) $(GNL_OBJS) $(LIBFT_OBJS)

#CLEAN
RM = rm -rf

all: $(NAME)

#compile all the sources
$(FT_PRINTF_OBJS_DIR)/%.o: $(FT_PRINTF_SRCS_DIR)/%.c | $(FT_PRINTF_OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(GNL_OBJS_DIR)/%.o: $(GNL_SRCS_DIR)/%.c | $(GNL_OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT_OBJS_DIR)/%.o: $(LIBFT_SRCS_DIR)/%.c | $(LIBFT_OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

#create directories for object files
$(FT_PRINTF_OBJS_DIR):
	mkdir -p $(FT_PRINTF_OBJS_DIR)

$(GNL_OBJS_DIR):
	mkdir -p $(GNL_OBJS_DIR)

$(LIBFT_OBJS_DIR):
	mkdir -p $(LIBFT_OBJS_DIR)

#compile the library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: all

clean:
	$(RM) $(FT_PRINTF_OBJS_DIR) $(GNL_OBJS_DIR) $(LIBFT_OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
