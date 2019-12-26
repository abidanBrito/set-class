# VARIABLES
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
SRC_DIR = code
BUILD_DIR = build
TARGET1 = $(BUILD_DIR)/pruebasVector
TARGET2 = $(BUILD_DIR)/pruebasVectorEspecificas
OBJS1 = mainPruebas.o ConjuntoVector.o
OBJS2 = mainPruebasEspecificas.o ConjuntoVector.o

all: $(TARGET1) $(TARGET2)

# OBJECT FILES
mainPruebas.o: $(SRC_DIR)/mainPruebas.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/mainPruebas.cpp

mainPruebasEspecificas.o: $(SRC_DIR)/mainPruebasEspecificas.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/mainPruebasEspecificas.cpp

ConjuntoVector.o: $(SRC_DIR)/ConjuntoVector.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/ConjuntoVector.cpp

# EXECUTABLES
$(TARGET1): $(OBJS1)
	$(CXX) -o $(TARGET1) $(OBJS1)

$(TARGET2): $(OBJS2)
	$(CXX) -o $(TARGET2) $(OBJS2)

# DELETE BINARIES UPON COMMAND
rmobj:
	rm *.o

clean:
	rm -f $(TARGET1) $(TARGET2) *.o
	rmdir build

$(shell mkdir -p $(BUILD_DIR))
