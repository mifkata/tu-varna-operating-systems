all: clean
	@gcc -o app2.bin main.c input.c sort.c output.c

run: all
	./app2.bin

clean:
	@rm -f app2.bin

.PHONY: all run clean
