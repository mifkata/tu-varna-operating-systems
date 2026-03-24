all: clean
	gcc -o app7.bin main.c -lpthread

run:
	@test -f app7.bin || $(MAKE) all
	./app7.bin

clean:
	rm -f app7.bin

.PHONY: all run clean
