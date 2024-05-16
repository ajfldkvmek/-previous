.SUFFIXES: .cpp .o

OBJECT = main.o print.o student_id.o
CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECT)
	$(CXX) -o $(TARGET) $(OBJECT)

clean :
	rm -rf $(TARGET) $(OBJECT)

main.o : main.cpp
print.o: print.cpp
student_id.o: student_id.cpp
