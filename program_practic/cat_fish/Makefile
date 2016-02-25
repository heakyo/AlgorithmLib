LIB_PATH = ../../lib/
HEAD_PATH = ../../include/

cat_fish: cat_fish.o
	gcc -L$(LIB_PATH) -o $@ $< -lqueue-sq -lstack-sq

cat_fish.o: cat_fish.c
	gcc -I$(HEAD_PATH) -g -c -o $@ $<
	
clean:
	rm -f *.o cat_fish
