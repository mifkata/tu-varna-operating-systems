all: clean
	@gcc -o app1.bin main.c

run: all
	./run_kill.sh

clean:
	@rm -f app1.bin

.PHONY: all run clean
