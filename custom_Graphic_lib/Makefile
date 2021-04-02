CC=avr-gcc
OBJCPY=avr-objcopy
CFLAGS= -std=c99 -Wall -ffunction-sections
DUDE = avrdude
F_CPU=8000000
PORT=/dev/cu.SLAB_USBtoUART
MCU = atmega328p

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

EXE := $(BIN_DIR)/exec
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LDLIBS := -lm
LDFLAGS  := -Llib

CDEFS = -DF_CPU=$(F_CPU)UL
ALL_CFLAGS = $(CFLAGS) -Iinclude -mmcu=$(MCU) $(CDEFS)
SCREEN_PID := $(shell ps -t cu.SLAB_USBtoUART | tail -n1 | awk '{print $$1}')

all: $(EXE) hex flash

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $(ALL_CFLAGS) $^ $(LDLIBS) -o $@.bin

$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(ALL_CFLAGS) -c $< -o $@

hex: 
	$(OBJCPY) -j .text -j .data -O ihex $(EXE).bin $(EXE).hex
	avr-size --format=avr --mcu=$(MCU) $(EXE).bin
flash:
		$(DUDE) -v -p $(MCU) -c arduino -P $(PORT) -b 57600 -U flash:w:$(EXE).hex:i
clean:
	rm $(OBJ_DIR)/*.o
fclean:
	rm $(BIN_DIR)/*
re: clean fclean all
ks:
	kill -3 $(SCREEN_PID)

reks: ks all

.PHONY: all hex flash clean
