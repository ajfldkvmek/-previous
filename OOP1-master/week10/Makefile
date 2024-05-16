.SUFFIXES: .cpp .o

OBJECTS = vechile.o bike.o car.o main.o

CXX = g++
CPPFLAGS = -c

TARGET = main

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

clean: 
	rm -rf $(OBJECTS) $(TARGET)


vechile.o : Vechile.cpp
bike.o : Bike.cpp
car.o : Car.cpp
main.o: main.cpp
