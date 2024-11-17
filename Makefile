SRCS			:=	srcs/main.cpp
OBJS			:=	$(SRCS:.cpp=.o)

HEADERS_SRCS	:= GameManager.hpp
HEADERS			:=	-I headers/$(HEADERS_SRCS)
NAME			:=	chess

CXX				:=	g++
CXXFLAGS		:=	-Wall -Wextra --std=c++11
LIBFLAGS		:=	-lsfml-graphics -lsfml-window -lsfml-system

all:	$(NAME)

%.o:	%.cpp
	@$(CXX) $(CXXFLAGS) $(HEADERS) -c -o $@ $<
	@echo "Compiled $@"

$(NAME):	$(OBJS)
	@$(CXX) $(OBJS) -o $(NAME) $(LIBFLAGS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
