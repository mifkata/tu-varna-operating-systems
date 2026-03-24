all: clean
	@gcc -O0 -o app3_producer.bin producer.c ../shared/shared.c
	@gcc -O0 -o app3_consumer.bin consumer.c ../shared/shared.c

run: all
	./app3_producer.bin & ./app3_consumer.bin

clean:
	@rm -f app3_producer.bin app3_consumer.bin

.PHONY: all run clean
