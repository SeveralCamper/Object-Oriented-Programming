CFLAGS := -Wall -Werror -std=c++17
CPPFLAGS := -MMD
CXX := g++

TARGET := bin/OOP

LIBS= -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system 

SOURCES := $(wildcard src/OOP/main.cpp)
LIBSOURCES := $(wildcard src/lib/*.cpp)

LIBOBJ := $(patsubst src/lib/%.cpp, obj/src/%.o, $(LIBSOURCES))
LIB := obj/lib/functionLib.a

OBJ := $(patsubst src/OOP/%.cpp, obj/src/%.o, $(SOURCES))

all:$(TARGET)

$(TARGET): $(LIB) $(MLIB) $(OBJ)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $(TARGET) $(OBJ) -L. $(LIB) $(LIBS)

$(LIB): $(LIBOBJ)
	ar rcs $@ $^

obj/src/%.o: src/lib/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ $(LIBS)  -I src/lib

obj/src/%.o: src/OOP/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ $(LIBS)  -Isrc/lib

run: $(TARGET)
	./bin/OOP


clean:
	find . -name "*.o" -exec rm '{}' \;
	find . -name "*.d" -exec rm '{}' \;
	find . -name "*.a" -exec rm '{}' \;
	find ./bin -type f -name "OOP" -exec rm -f '{}' \;

format:
	cd src; find . -name "*.cpp" -exec clang-format -i {} \;
	cd src; find . -name "*.h" -exec clang-format -i {} \;

.PHONY: clean test run all format 
