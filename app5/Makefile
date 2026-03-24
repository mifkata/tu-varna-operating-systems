all: clean
	@gcc -O0 -o app5_producer.bin producer.c ../shared/shared.c
	@gcc -O0 -o app5_consumer.bin consumer.c ../shared/shared.c

run: all
	./app5_producer.bin & ./app5_consumer.bin

clean:
	@rm -f app5_producer.bin app5_consumer.bin

.PHONY: all run clean
