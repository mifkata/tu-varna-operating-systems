all: clean
	gcc -O0 -o app7_mutex.bin main_mutex.c -lpthread
	gcc -O0 -o app7_sem.bin main_sem.c -lpthread

run-mutex:
	@test -f app7_mutex.bin || $(MAKE) all
	./app7_mutex.bin

run-sem:
	@test -f app7_sem.bin || $(MAKE) all
	./app7_sem.bin

run: run-mutex

clean:
	rm -f app7_mutex.bin app7_sem.bin

.PHONY: all run run-mutex run-sem clean
