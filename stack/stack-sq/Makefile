LIB_PATH = ../../lib

stack-sq-test: stack-sq-test.o
	gcc -L$(LIB_PATH) -o $@ $^ -lstack-sq

libstack-sq.a: stack-sq.o
	ar -rcs $@ $<
	mv $@ $(LIB_PATH)

stack-sq.o: stack-sq.c
	gcc -c -o $@ $<

stack-sq-test.o: stack-sq-test.c
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a stack-sq-test 
