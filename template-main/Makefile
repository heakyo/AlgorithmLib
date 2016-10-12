HEAD = main.h

main: main.o
	@gcc $< -o $@

main.S: main.c $(HEAD)
	@gcc $< -S -o $@

main.o: main.S
	@gcc $< -c -o $@

disass: main
	@objdump -d $< > main_dis

disass_o: main.o
	@objdump -d $< > main_o_dis

debug_main: main.c $(HEAD)
	@gcc $^ -g -o $@

clean:
	rm -f main main.S main.o main_dis main_o_dis debug_main

.PHONY: clean
