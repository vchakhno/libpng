
SRCS_DIR		:= sources
SRCS			:= decoder.c
SRCS			:= $(addsuffix $(SRCS_DIR)/,$(SRCS))

CRITERION_PATH	:= /mnt/nfs/homes/vchakhno/Documents/Criterion
CRITERION_BIN	:= $(CRITERION_PATH)/build/src/
CRITERION_INC	:= $(CRITERION_PATH)/include

LIBFT_PATH		:= $(LIB_DIR)/libft
LIBFT_INC		:= $(LIBFT_PATH)/include

CFLAGS			:=	-Wall -Wextra -Werror -I includes \
					-I $(CRITERION_INC) \
					-I $(LIBFT_INC)
LDFLAGS			:=	-L $(CRITERION_BIN) -lcriterion -Wl,-rpath,$(CRITERION_BIN) \
					-L $(LIBFT_PATH) -lft


test: sources/decoder.c tests/test_decoder.c
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

.PHONY: test