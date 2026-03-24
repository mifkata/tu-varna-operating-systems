all: clean
	gcc -O0 -o app6_producer.bin producer.c ../shared/shared.c
	gcc -O0 -o app6_capitalizer.bin capitalizer.c ../shared/shared.c
	gcc -O0 -o app6_consumer.bin consumer.c ../shared/shared.c

run:
	@test -f app6_producer.bin -a -f app6_capitalizer.bin -a -f app6_consumer.bin || $(MAKE) all
	./app6_producer.bin & ./app6_capitalizer.bin & ./app6_consumer.bin

clean:
	rm -f app6_producer.bin app6_capitalizer.bin app6_consumer.bin

.PHONY: all run clean
