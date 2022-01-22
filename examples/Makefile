define execute
	gcc -o $(1) -Wall -Wextra -Wpedantic $(1).c
	./$(1)
	rm -f $(1)
endef

.PHONY: simple
simple:
	$(call execute,simple)

.PHONY: overwrite
overwrite:
	$(call execute,overwrite)

.PHONY: multistep
multistep:
	$(call execute,multistep)
