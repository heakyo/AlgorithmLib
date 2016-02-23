LIB_PATH = ~/study/linux_study/AlgorithmLib/lib/

stack-sq-test: stack-sq-test.o
	gcc -L $(LIB_PATH) -o $@ $^ -lstack-sq

stack-sq.o: stack-sq.c
	gcc -c -o $@ $<

stack-sq-test.o: stack-sq-test.c
	gcc -c -o $@ $<

clean:
	rm -f *.o stack-sq-test 
