CC=gcc
SRC=src
BUILD=build
BIN=bin
CFLAGS=-g -Wall -Wextra # -Werror

.PHONY: all
all: $(BIN)/cache $(BIN)/revele

.DELETE_ON_ERROR:

$(BUILD)/image.o: $(SRC)/include/image.c
	@$(CC) $(CFLAGS) -c -o $@ $<
$(BUILD)/cache.o: $(SRC)/cache.c
	@$(CC) $(CFLAGS) -c -o $@ $<
$(BUILD)/revele.o: $(SRC)/revele.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(BIN)/cache: $(BUILD)/image.o $(BUILD)/cache.o
	@$(CC) $(CFLAGS) -o $@ $^

$(BIN)/revele: $(BUILD)/image.o $(BUILD)/revele.o
	@$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(BIN)/*
