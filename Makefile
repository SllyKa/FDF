#
#	Debug compiler variables
#

DG_CC_FLAGS= -g -O0

#
#	Compiler variables
#

CC= gcc
CC_FLAGS= -Wall -Wextra -Werror

#
#	FDF release variables
#

NAME= fdf

LIBDIR= libftprintf
LIB= libftprintf.a
LIBHEADER=libftprintf.h
LIBSHORT= ftprintf

LIBMXDIR= minilibx_macos
LIBMX= libmlx.a
LIBMXHEADER= mlx.h
LIBMXSHORT= mlx

HEADERDIR= includes
HEADER= fdf.h

SRCSDIR= srcs
OBJSDIR= objs
OBJS= $(patsubst $(SRCSDIR)/%.c, $(OBJSDIR)/%.o, $(wildcard $(SRCSDIR)/*.c))

SRCS= $(OBJS:.o=.c)

.PHONY: all debug clean fclean re
all: $(NAME)

#
#	Debug mode settings
#

debug: CC_FLAGS += $(DG_CC_FLAGS)
debug: $(NAME)

#
#	Release FDF
#

$(NAME): $(LIB) $(LIBMX) $(OBJS)
	$(CC) $(CC_FLAGS) -I$(HEADERDIR) -I$(LIBMXDIR) $(OBJS) -o $@ -L$(LIBDIR) -l$(LIBSHORT) -L$(LIBMXDIR) -l$(LIBMXSHORT) -framework OpenGL -framework AppKit

$(LIB):
	cd $(LIBDIR) && $(MAKE) -s

$(LIBMX):
	cd $(LIBMXDIR) && $(MAKE) -s

$(OBJS): $(OBJSDIR)/%.o : $(SRCSDIR)/%.c $(HEADERDIR)/$(HEADER) $(LIBMXDIR)/$(LIBMXHEADER)
	mkdir -p $(OBJSDIR)
	$(CC) $(CC_FLAGS) -I$(HEADERDIR) -I$(LIBDIR)/$(HEADERDIR) -c $< -o $@

#
#	Clean
#

clean:
	rm -rf $(OBJSDIR)
	cd $(LIBDIR) && $(MAKE) clean
	cd $(LIBMXDIR) && $(MAKE) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBDIR)/$(LIB)
	rm -rf $(LIBMXDIR)/$(LIBMX)

re: fclean all