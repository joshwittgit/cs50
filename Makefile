CC = clang
CFLAGS = -Wall -Wextra -Werror -std=c11 -L../lib -lcs50

# Traverse all subdirectories and build each .c file in those directories
SUBDIRS := $(wildcard */)

# Default target (when you just run 'make')
all: $(SUBDIRS)

# Build each program for every subdirectory (weekX)
$(SUBDIRS): %:
	$(MAKE) -C $@

# Individual rule for compiling each program in each weekly directory
%/$(notdir %): %/$(notdir %).c
	$(CC) -o $@ $^ $(CFLAGS)

# Clean rule to remove compiled files from all subdirectories
clean:
	$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir) clean;)
	rm -f $(SUBDIRS)