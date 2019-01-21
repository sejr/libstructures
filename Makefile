CC=gcc

linkedlist:
	mkdir build && $(CC) test/TestLinkedList.c -o build/TestLinkedList

clean:
	rm -rf build