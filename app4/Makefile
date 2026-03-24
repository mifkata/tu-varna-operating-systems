all: clean
	gcc -O0 -o app4_producer.bin producer.c ../shared/shared.c
	gcc -O0 -o app4_consumer.bin consumer.c ../shared/shared.c

run:
	@test -f app4_producer.bin -a -f app4_consumer.bin || $(MAKE) all
	./app4_producer.bin & ./app4_consumer.bin

clean:
	rm -f app4_producer.bin app4_consumer.bin

.PHONY: all run clean
