SRCC_FILES = client.c
SRCS_FILES = server.c
UTILS_FILES = utils.c
BONUS_SRCC_FILES = client_bonus.c
BONUS_SRCS_FILES = server_bonus.c
SRC_DIR = src/
BONUS_DIR = bonus/
INCLUDE_DIR = include/
PRINTF_DIR = printf/
PRINTF_LIB = $(PRINTF_DIR)libftprintf.a
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
UTILS = $(addprefix $(SRC_DIR), $(UTILS_FILES))
BONUS_SRCC = $(addprefix $(BONUS_DIR), $(BONUS_SRCC_FILES))
BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_SRCS_FILES))
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
OBJS_UTILS = ${UTILS:.c=.o}
BONUS_OBJC = ${BONUS_SRCC:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I $(INCLUDE_DIR) -I $(PRINTF_DIR)
RM = rm -rf

NAMEC = client
NAMES = server
NAMEC_BONUS = client_bonus
NAMES_BONUS = server_bonus

all: $(NAMEC) $(NAMES)

$(NAMEC): $(OBJC) $(OBJS_UTILS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJC) $(OBJS_UTILS) $(PRINTF_LIB) $(INCLUDE) -o $(NAMEC)

$(NAMES): $(OBJS) $(OBJS_UTILS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_UTILS) $(PRINTF_LIB) $(INCLUDE) -o $(NAMES)

bonus: $(NAMEC_BONUS) $(NAMES_BONUS)

$(NAMEC_BONUS): $(BONUS_OBJC) $(OBJS_UTILS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJC) $(OBJS_UTILS) $(PRINTF_LIB) $(INCLUDE) -o $(NAMEC_BONUS)

$(NAMES_BONUS): $(BONUS_OBJS) $(OBJS_UTILS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(OBJS_UTILS) $(PRINTF_LIB) $(INCLUDE) -o $(NAMES_BONUS)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BONUS_DIR)%.o: $(BONUS_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJC) $(OBJS) $(OBJS_UTILS) $(BONUS_OBJC) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAMEC) $(NAMES) $(NAMEC_BONUS) $(NAMES_BONUS)

re: fclean all