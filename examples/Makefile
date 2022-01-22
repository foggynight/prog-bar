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

.PHONY: chicken
chicken:
	cd .. ;\
	csc -c -J prog-bar.scm -unit prog-bar ;\
	csc -o examples/chicken examples/chicken.scm prog-bar.o -uses prog-bar ;\
	rm prog-bar.import.scm prog-bar.o
	./chicken
	rm -f chicken
