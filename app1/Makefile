all: clean
	gcc -o app1.bin main.c

run:
	@test -f app1.bin || $(MAKE) all
	./run_kill.sh

clean:
	rm -f app1.bin

.PHONY: all run clean
