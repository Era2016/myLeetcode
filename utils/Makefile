objects = binaryTree.o listNode.o
CC = clang++
CFLAGS = -std=c++11 -g -fsanitize=address

edit: $(objects)
	@echo $(objects)	

binaryTree.o: 
	$(CC) $(CFLAGS) -c binaryTree.cpp
listNode.o: 
	$(CC) $(CFLAGS) -c listNode.cpp

.phony: clean
clean:
	-rm edit $(objects)
