COMPOSE := docker compose
SERVICE := devcontainer

.DEFAULT_GOAL := default
.PHONY: default start stop restart build rebuild

default: start
	@$(COMPOSE) exec -u dev $(SERVICE) zsh

start:
	@$(COMPOSE) up -d

stop:
	@$(COMPOSE) down

restart: stop start

build:
	@$(COMPOSE) build

rebuild:
	@$(COMPOSE) build --no-cache
