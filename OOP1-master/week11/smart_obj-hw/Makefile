.SUFFIXES: .cpp .o

OBJECTS = human.o student.o shared_ref.o smart_obj.o weak_pointer.o test.o

CXX = g++

TARGET = test

$(TARGET) : $(OBJECTS)
			$(CXX) -o $(TARGET) $(OBJECTS)
			
clean:
		rm -rf $(TARGET) $(OBJECTS)

human.o = human.cpp
student.o = student.cpp
shared_ref.o = shared_ref.cpp
smart_obj.o = smart_obj.cpp
weak_pointer.o = weak_pointer.cpp
test.o = test.cpp