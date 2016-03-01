LIB_PATH = ../../lib

btree-node-test: btree-node-test.o
	gcc -L$(LIB_PATH) -o $@ $^ -lbtree-node

libbtree-node.a: btree-node.o
	ar -rcs $@ $<
	mv $@ $(LIB_PATH)

btree-node.o: btree-node.c
	gcc -c -o $@ $<

btree-node-test.o: btree-node-test.c
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a btree-node-test 
