CC=avr-gcc
OBJCPY=avr-objcopy
CFLAGS= -std=c99 -Wall -ffunction-sections
DUDE = avrdude
F_CPU=16000000
PORT=/dev/cu.SLAB_USBtoUART
MCU = atmega328p

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

EXE := $(BIN_DIR)/exec
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CDEFS = -DF_CPU=$(F_CPU)UL
ALL_CFLAGS = $(CFLAGS) -Iinclude -mmcu=$(MCU) $(CDEFS)

all: $(EXE) hex flash

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(ALL_CFLAGS) $^ -o $@.bin

$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(ALL_CFLAGS) -c $< -o $@

hex: 
	#$(CC) $(ALL_CFLAGS) -c $(SRC).c -o $(SRC).o $@
	#$(CC) $(ALL_CFLAGS) -o $(SRC).bin  $(SRC).o $@
	$(OBJCPY) -j .text -j .data -O ihex $(EXE) $(EXE).hex
	avr-size --format=avr --mcu=$(MCU) $(EXE)
flash:
		$(DUDE) -v -p $(MCU) -c arduino -P $(PORT) -b 57600 -U flash:w:$(EXE).hex:i
clean:
	rm $(SRC).o
	rm $(SRC).bin
	rm $(SRC).hex


.PHONY: all
