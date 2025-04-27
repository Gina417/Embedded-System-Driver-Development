CC=arm-none-eabi-gcc
MACH=cortex-m4
OBJCOPY=arm-none-eabi-objcopy
CFLAGS= -mcpu=$(MACH) \
			-mthumb \
			-mlittle-endian \
			-g -Wall
LDFLAGS= -mcpu=$(MACH) -mthumb --specs=nano.specs -T ./stm32_ls.ld -Wl,-Map=output.map

CFLAGS+=-I./inc

STARTUP=./stm32_startup.c
STARTUP_OBJ=./stm32_startup.o

SYSCALLS=./syscalls.c
SYSCALLS_OBJ=./syscalls.o

SRC=./main.c
SRC+=./src/rcc.c \
		./src/gpio.c

SRC_OBJS:=$(SRC:.c=.o)
SRC_OBJS:=$(patsubst ./src/%, %, $(SRC_OBJS))

EXECUTABLE=main.elf
BIN=main.bin

all: $(SRC_OBJS) $(STARTUP_OBJ) $(SYSCALLS_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXECUTABLE) $(SRC_OBJS) $(STARTUP_OBJ) $(SYSCALLS_OBJ)
	$(OBJCOPY) -O binary $(EXECUTABLE) $(BIN)

$(SRC_OBJS): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

$(STARTUP_OBJ): $(STARTUP)
	$(CC) $(CFLAGS) -c $(STARTUP)

$(SYSCALLS_OBJ): $(SYSCALLS)
	$(CC) $(CFLAGS) -c $(SYSCALLS)

dump: main.elf
	arm-none-eabi-objdump -h main.elf

flash: main.bin
	st-flash write main.bin 0x8000000

debug:
	arm-none-eabi-gdb -q -x ./.gdbinit

monitor:
	openocd -f /usr/share/openocd/scripts/interface/stlink.cfg -f /usr/share/openocd/scripts/target/stm32f4x.cfg

clean:
	rm -f *.o *.elf *.bin *.map