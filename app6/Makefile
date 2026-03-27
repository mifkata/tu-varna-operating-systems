all: clean
	gcc -O0 -o app6.bin main.c producer.c capitalizer.c consumer.c ../shared/shared.c

run:
	@test -f app6.bin || $(MAKE) all
	./app6.bin

clean:
	rm -f app6.bin

.PHONY: all run clean
