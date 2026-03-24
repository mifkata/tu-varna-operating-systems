N = $(word 2,$(MAKECMDGOALS))

build:
	make -C app$(N)

run:
	make -C app$(N) run

devcontainer:
	make -C .devcontainer

%:
	@true

.PHONY: build run devcontainer
