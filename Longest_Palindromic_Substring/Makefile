objects = solution.o
CC = clang++
CFLAGS = -std=c++11 -g -fsanitize=address

test: $(objects)
	$(CC) $(CFLAGS) -o test $(objects)

solution.o: solution.cpp
	$(CC) $(CFLAGS) -c solution.cpp 

.phony: cleanall
cleanall:
	-rm test $(objects)

.phony: clean
clean:
	-rm test
