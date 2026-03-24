N = $(word 2,$(MAKECMDGOALS))

build:
	make -C app$(N)

run:
	make -C app$(N) run

%:
	@true

.PHONY: build run
