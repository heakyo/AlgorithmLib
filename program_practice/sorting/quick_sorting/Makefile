main: main.o
	@gcc $< -o $@

main.S: main.c
	@gcc $< -S -o $@

main.o: main.S
	@gcc $< -g -c -o $@

disass: main
	objdump -d $< > main_dis

disass_o: main.o
	objdump -d $< > main_o_dis

clean:
	@rm -f main main.S main.o main_dis main_o_dis a.out
