stack-sq-test: stack-sq.o stack-sq-test.o
	gcc -o $@ $^

stack-sq.o: stack-sq.c
	gcc -c -o $@ $<

stack-sq-test.o: stack-sq-test.c
	gcc -c -o $@ $<

clean:
	rm -f *.o stack-sq-test 
