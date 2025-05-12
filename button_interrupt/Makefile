CC=arm-none-eabi-gcc
MACH=cortex-m4
OBJCOPY=arm-none-eabi-objcopy
CFLAGS= -mcpu=$(MACH) \
			-mthumb \
			-mlittle-endian \
			-g -Wall
LDFLAGS= -mcpu=$(MACH) -mthumb --specs=nano.specs -T ./stm32_ls.ld -Wl,-Map=output.map

# Include headers
CFLAGS+=-I./
CFLAGS+=-I./driver/inc
CFLAGS+=-I./interrupt
CFLAGS+=-I./Cortex-M4/inc

STARTUP=./stm32_startup.c
STARTUP_OBJ=./stm32_startup.o

SYSCALLS=./syscalls.c
SYSCALLS_OBJ=./syscalls.o

SRC=./main.c
SRC+=./driver/src/rcc.c \
		./driver/src/gpio.c \
		./driver/src/exti.c \
		./driver/src/syscfg.c 
SRC+=./interrupt/interrupt.c 
SRC+= ./Cortex-M4/src/nvic.c

SRC_OBJS:=$(SRC:.c=.o)
SRC_OBJS:=$(patsubst ./driver/src/%, %, $(SRC_OBJS))
SRC_OBJS:=$(patsubst ./interrupt/%, %, $(SRC_OBJS))
SRC_OBJS:=$(patsubst ./Cortex-M4/src/%, %, $(SRC_OBJS))

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