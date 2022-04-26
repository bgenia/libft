include maketools/common_config.mk
include maketools/source_list.mk

NAME := libft.a

SRC := $(call source_list,$(SRC_DIR))
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDE += include-internal

CPPFLAGS += $(addprefix -D,$(FT_OPTIONS))

ifneq ($(FT_OPTIMIZE),)
	CFLAGS := $(FT_OPTIMIZE) $(filter-out -O2,$(CFLAGS))
endif

all: $(NAME)

$(NAME): $(OBJ)

include maketools/common_rules.mk

-include $(OBJ:.o=.d)
