CC=gcc

linkedlist:
	mkdir build && $(CC) test/TestLinkedList.c -o build/TestLinkedList

binarytree:
	mkdir build && $(CC) test/TestBinaryTree.c -o build/TestBinaryTree

clean:
	rm -rf build