# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Names of your executable programs
SERVER = server
CLIENT = client

# Source files for each program
SERVER_SRC = server.c
CLIENT_SRC = client.c

.PHONY: all clean

all: $(SERVER) $(CLIENT)

# rule to build each program
$(SERVER): $(SERVER_SRC)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_SRC)

$(CLIENT): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_SRC)

clean:
	rm -f $(SERVER) $(CLIENT)
