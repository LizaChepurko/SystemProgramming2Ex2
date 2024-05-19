# ID: 211548268
 # Mail: lizachep@gmail.com

CC = g++
CFLAGS = -std=c++11
OBJECTS = Algorithms.o Graph.o 
TEST_OBJECTS = Test.o TestCounter.o
EXECUTABLE = demo
TEST_EXECUTABLE = test

all: $(EXECUTABLE) $(TEST_EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) Demo.o
	$(CC) $(CFLAGS) Demo.o $(OBJECTS) -o $(EXECUTABLE)

$(TEST_EXECUTABLE): $(OBJECTS) $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(TEST_OBJECTS) -o $(TEST_EXECUTABLE)

Algorithms.o: Algorithms.cpp Algorithms.hpp
	$(CC) $(CFLAGS) -c Algorithms.cpp

Graph.o: Graph.cpp Graph.hpp
	$(CC) $(CFLAGS) -c Graph.cpp

Demo.o: Demo.cpp
	$(CC) $(CFLAGS) -c Demo.cpp

Test.o: Test.cpp
	$(CC) $(CFLAGS) -c Test.cpp

TestCounter.o: TestCounter.cpp doctest.h
	$(CC) $(CFLAGS) -c TestCounter.cpp

clean:
	rm -f $(EXECUTABLE) $(OBJECTS) $(TEST_EXECUTABLE) $(TEST_OBJECTS) Demo.o