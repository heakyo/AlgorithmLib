queue-sq-test: queue-sq.o queue-sq-test.o
	gcc -o $@ $^

queue-sq.o: queue-sq.c
	gcc -c -g -o $@ $<

queue-sq-test.o: queue-sq-test.c
	gcc -c -g -o $@ $<

clean:
	rm -f *.o queue-sq-test 
