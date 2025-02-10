CC = clang
CFLAGS = -lcs50 -Wall -Wextra -Werror -std=c11

# Get the folder name (assumes you run make from the project root)
DEFAULT_PROGRAM = $(notdir $(shell pwd))

all: $(DEFAULT_PROGRAM)

$(DEFAULT_PROGRAM): $(DEFAULT_PROGRAM).c
	$(CC) -o $(DEFAULT_PROGRAM) $(DEFAULT_PROGRAM).c $(CFLAGS)

clean:
	rm -f $(DEFAULT_PROGRAM)