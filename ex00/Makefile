# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 13:34:22 by ladloff           #+#    #+#              #
#    Updated: 2024/04/18 15:29:16 by ladloff          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Use the standard shell
SHELL := /bin/sh
# Name of the output executable
NAME := megaphone

# Directory containing source files
srcdir := ./
# Directory where binary files will be placed
bindir := ./bin
# Specify search path for prerequisites
VPATH := $(srcdir)

# List of source files
SRCS := megaphone.cpp
# List of object files, placed in the bindir
OBJS := $(patsubst %.cpp,$(bindir)/%.o,$(notdir $(SRCS)))
# Dependency files for object files
DEPS := $(OBJS:.o=.d)

# Compiler flags
CXXFLAGS := -Wall -Wextra -Werror -MMD -MP -std=c++98

# Declare phony targets
.PHONY: all clean fclean re directories

# Default target
all: directories $(NAME)

# Ensure the bin directory exists
directories: $(bindir)

# Rule to create the bindir
$(bindir):
	@mkdir -p $@

# Compile .cpp files to .o files, ensure directories are prepared
$(bindir)/%.o: %.cpp | directories
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link the object files into the executable
$(NAME): $(OBJS)
	$(CXX) $^ -o $@

# Remove the bin directory and its contents
clean:
	rm -rf $(bindir)

# Perform clean and also remove the executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Include dependency files
-include $(DEPS)

# Clear out the default suffixes
.SUFFIXES:
# Specify our own suffix list
.SUFFIXES: .cpp .o
