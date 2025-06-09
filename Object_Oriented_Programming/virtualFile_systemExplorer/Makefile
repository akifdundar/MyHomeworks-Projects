CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = program

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(EXEC)
