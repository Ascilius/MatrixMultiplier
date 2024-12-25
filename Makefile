CC = gcc
CFLAGS = -g -Wall -Wextra

SRC = src/matrix_multiplier.c
OBJ = $(SRC:.c=.o)

TARGET = build/mm

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)