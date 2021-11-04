BINS = emu-rv32i quicksort

CROSS_COMPILE = riscv-none-embed-
RV32I_CFLAGS = -march=rv32i -mabi=ilp32 -O3 -nostdlib

CFLAGS = -O3 -Wall -std=gnu99
LDFLAGS = -lelf

all: $(BINS)
	
emu-rv32i: emu-rv32i.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

quicksort: quicksort.c
	$(CROSS_COMPILE)gcc $(RV32I_CFLAGS) -o $@ $<

check: $(BINS)
	./emu-rv32i quicksort

objdump:
	$(CROSS_COMPILE)objdump -d quicksort

readelf:
	$(CROSS_COMPILE)readelf -h quicksort

size:
	$(CROSS_COMPILE)size quicksort

clean:
	$(RM) $(BINS)
