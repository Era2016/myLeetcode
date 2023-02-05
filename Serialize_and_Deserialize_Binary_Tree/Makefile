objects = ../utils/binaryTree.o v2_solution.o
CC = clang++
CFLAGS = -std=c++11 -g -fsanitize=address

edit: $(objects)
	@echo $(objects)	

test: $(objects)
	$(CC) $(CFLAGS) -o test $(objects) 

solution.o: v2_solution.cpp
	$(CC) $(CFLAGS) -c v2_solution.cpp

.phony: clean
clean:
	-rm test

.phony: cleanall
cleanall:
	-rm test $(objects)
