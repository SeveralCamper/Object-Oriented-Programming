CFLAGS := -Wall -Werror -Wextra -std=c++17
CXX := g++

TARGET1 := bin/virtual
TARGET2 := bin/inheritance

LIBS= -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system 

SOURCES := $(src/OOP/main.cpp)
LIBSOURCES := $(wildcard src/lib/*.cpp)

LIBOBJ := $(patsubst src/lib/%.cpp, obj/src/%.o, $(LIBSOURCES))
LIB := obj/lib/functionLib.a

OBJ := $(patsubst src/OOP/%.cpp, obj/src/%.o, $(SOURCES))

all: virtual inheritance

virtual: $(TARGET1)

$(TARGET1): obj/src/main.o obj/src/virtualtPoint.o obj/src/tPoint.o
	$(CXX) obj/src/main.o obj/src/virtualtPoint.o obj/src/tPoint.o -o $(TARGET1) $(LIBS)

obj/src/main.o: src/OOP/main.cpp
	$(CXX) $(CFLAGS) -c $(LIBS) -c -DVIRTUAL src/OOP/main.cpp -o obj/src/main.o

obj/src/virtualtPoint.o: src/lib/virtualtPoint.cpp
	$(CXX) $(CFLAGS) -c $(LIBS) src/lib/virtualtPoint.cpp -o obj/src/virtualtPoint.o

obj/src/tPoint.o: src/lib/tPoint.cpp
	$(CXX) $(CFLAGS) -c $(LIBS) src/lib/tPoint.cpp -o obj/src/tPoint.o

inheritance: $(TARGET2)

$(TARGET2): obj/src/main.o obj/src/tPoint.o
	$(CXX) obj/src/main.o obj/src/tPoint.o -o $(TARGET2) $(LIBS)

obj/src/main.o: src/OOP/main.cpp
	$(CXX) $(CFLAGS) -c $(LIBS) -c -DINHERITANCE src/OOP/main.cpp -o obj/src/main.o

obj/src/tPoint.o: src/lib/tPoint.cpp
	$(CXX) $(CFLAGS) -c $(LIBS) src/lib/tPoint.cpp -o obj/src/tPoint.o

run: $(TARGET)
	./bin/virtual


clean:
	find . -name "*.o" -exec rm '{}' \;
	find . -name "*.d" -exec rm '{}' \;
	find . -name "*.a" -exec rm '{}' \;
	find ./bin -type f -name "OOP" -exec rm -f '{}' \;

format:
	cd src; find . -name "*.cpp" -exec clang-format -i {} \;
	cd src; find . -name "*.h" -exec clang-format -i {} \;

.PHONY: clean test run all format 
