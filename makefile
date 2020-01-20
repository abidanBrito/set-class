# VARIABLES
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
SRC_DIR = code
BUILD_DIR = build
TARGET1 = $(BUILD_DIR)/tests
TARGET2 = $(BUILD_DIR)/testsEspecific
OBJS1 = mainTests.o SetVector.o
OBJS2 = mainTestsEspecific.o SetVector.o

all: $(TARGET1) $(TARGET2)

# OBJECT FILES
mainTests.o: $(SRC_DIR)/mainTests.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/mainTests.cpp

mainTestsEspecific.o: $(SRC_DIR)/mainTestsEspecific.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/mainTestsEspecific.cpp

SetVector.o: $(SRC_DIR)/SetVector.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/SetVector.cpp

# EXECUTABLES
$(TARGET1): $(OBJS1)
	$(CXX) -o $(TARGET1) $(OBJS1)

$(TARGET2): $(OBJS2)
	$(CXX) -o $(TARGET2) $(OBJS2)

# DELETE BINARIES
rmobj:
	rm *.o

clean:
	rm -f $(TARGET1) $(TARGET2) *.o
	rmdir $(BUILD_DIR)

# CREATE BUILD DIRECTORY
$(shell mkdir -p $(BUILD_DIR))
