LIB_PATH = ../../lib

queue-sq-test: queue-sq-test.o
	gcc -L$(LIB_PATH) -o $@ $^ -lqueue-sq

libqueue-sq.a: queue-sq.o
	ar -rcs $@ $<
	mv $@ $(LIB_PATH)

queue-sq.o: queue-sq.c
	gcc -c -o $@ $<

queue-sq-test.o: queue-sq-test.c
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a queue-sq-test 
