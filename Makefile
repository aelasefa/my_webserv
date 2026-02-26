# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: webserv                                    +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2026/02/26                               #+#    #+#             #
#    Updated: 2026/02/26                              ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME		= webserv

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
INCLUDES	= -I./include

ifdef DEBUG
	CXXFLAGS += -g3 -fsanitize=address
endif

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include

SRC_CORE	= $(SRC_DIR)/core/Socket.cpp \
			  $(SRC_DIR)/core/Client.cpp \
			  $(SRC_DIR)/core/Server.cpp \
			  $(SRC_DIR)/core/ServerManager.cpp \
			  $(SRC_DIR)/core/EventLoop.cpp \
			  $(SRC_DIR)/core/Webserv.cpp

SRC_CONFIG	= $(SRC_DIR)/config/LocationConfig.cpp \
			  $(SRC_DIR)/config/ServerConfig.cpp \
			  $(SRC_DIR)/config/ConfigManager.cpp

SRC_HTTP	= $(SRC_DIR)/http/HttpRequest.cpp \
			  $(SRC_DIR)/http/HttpResponse.cpp \
			  $(SRC_DIR)/http/RequestParser.cpp \
			  $(SRC_DIR)/http/ResponseBuilder.cpp

SRC_ROUTING	= $(SRC_DIR)/routing/Router.cpp \
			  $(SRC_DIR)/routing/RouteResolver.cpp

SRC_HANDLERS = $(SRC_DIR)/handlers/StaticFileHandler.cpp \
			   $(SRC_DIR)/handlers/DeleteHandler.cpp \
			   $(SRC_DIR)/handlers/CGIHandler.cpp \
			   $(SRC_DIR)/handlers/UploadHandler.cpp \
			   $(SRC_DIR)/handlers/AutoIndexHandler.cpp

SRC_UTILS	= $(SRC_DIR)/utils/Logger.cpp \
			  $(SRC_DIR)/utils/MimeTypes.cpp \
			  $(SRC_DIR)/utils/StatusCodes.cpp \
			  $(SRC_DIR)/utils/ErrorHandler.cpp

SRC_MAIN	= $(SRC_DIR)/main.cpp

SRCS		= $(SRC_CORE) $(SRC_CONFIG) $(SRC_HTTP) $(SRC_ROUTING) $(SRC_HANDLERS) $(SRC_UTILS) $(SRC_MAIN)

OBJS		= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
BLUE		= \033[0;34m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✓ Clean complete$(RESET)"

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)✓ Full clean complete$(RESET)"

re: fclean all

debug: CXXFLAGS += -g3 -fsanitize=address
debug: re

run: $(NAME)
	@echo "$(BLUE)Starting $(NAME)...$(RESET)"
	@./$(NAME)

help:
	@echo "$(BLUE)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)     - Build the project"
	@echo "  $(GREEN)clean$(RESET)   - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)  - Remove object files and executable"
	@echo "  $(GREEN)re$(RESET)      - Rebuild the project"
	@echo "  $(GREEN)debug$(RESET)   - Build with debug flags"
	@echo "  $(GREEN)run$(RESET)     - Build and run the server"
	@echo "  $(GREEN)help$(RESET)    - Show this help message"

.PHONY: all clean fclean re debug run help
