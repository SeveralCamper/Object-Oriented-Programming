CFLAGS := -Wall -Werror -std=c++17
CPPFLAGS := -MMD
CXX := g++

TARGET := bin/OOP

SOURCES := $(wildcard src/OOP/main.cpp)
LIBSOURCES := $(wildcard src/lib/*.cpp)
LIBMSOURCES := $(wildcard src/mlib/*.cpp)

LIBOBJ := $(patsubst src/lib/%.cpp, obj/src/%.o, $(LIBSOURCES))
LIB := obj/lib/functionLib.a

MLIBOBJ := $(patsubst src/mlib/%.cpp, obj/src/%.o, $(LIBMSOURCES))
MLIB := obj/mlib/methodsLib.a

OBJ := $(patsubst src/OOP/%.cpp, obj/src/%.o, $(SOURCES))

TEST := $(wildcard test/*.cpp)
TESTOBJ := $(patsubst test/%.cpp, obj/test/%.o, $(TEST))
TESTTARGET := bin/TestOOP
CTEST := thirdparty/ctest.h

all:$(TARGET)

$(TARGET): $(LIB) $(MLIB) $(OBJ)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $(TARGET) $(OBJ)  -L. $(MLIB) -L. $(LIB)  

$(LIB): $(LIBOBJ)
	ar rcs $@ $^

$(MLIB): $(MLIBOBJ)
	ar rcs $@ $^

obj/src/%.o: src/lib/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@  -I src/lib -I src/mlib

obj/src/%.o: src/mlib/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ $ -I src/lib -I src/mlib

obj/src/%.o: src/OOP/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@  -Isrc/lib -I src/mlib  

test: $(TESTTARGET)
	./$(TESTTARGET)

$(TESTTARGET): $(TESTOBJ) $(CTEST) $(LIB)
	$(CXX) $(CPPFLAGS) $(CFLAGS) $(TESTOBJ) -o $@ -L. $(MLIB) -L. $(LIB)  -I src/lib -I src/mlib -I thirdparty

obj/test/%.o: test/%.cpp $(CTEST)
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ -L. $(MLIB) -L. $(LIB)  -Isrc/lib -I src/mlib -I thirdparty

run: $(TARGET)
	./bin/OOP


clean:
	find . -name "*.o" -exec rm '{}' \;
	find . -name "*.d" -exec rm '{}' \;
	find . -name "*.a" -exec rm '{}' \;
	find ./bin -type f -name "OOP" -exec rm -f '{}' \;
	find ./bin -type f -name "TestOOP" -exec rm -f '{}' \;

format:
	cd src; find . -name "*.cpp" -exec clang-format -i {} \;
	cd src; find . -name "*.h" -exec clang-format -i {} \;

.PHONY: clean test run all format 
