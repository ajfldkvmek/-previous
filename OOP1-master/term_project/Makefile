.SUFFIXES : .cpp .o 

 
OBJECTS = array.o block.o cross.o fold.o tree.o 
 
 
MAIN = main.o $(OBJECTS) 
CXX = g++ 

 
TARGET = test 

 
$(TARGET) : $(MAIN) 
 	$(CXX) -o $(TARGET) $(MAIN) 
 
 
clean: 
rm -rf $(MAIN) $(TARGET) 

array.o = array.cpp
block.o = block.cpp
cross.o = cross.cpp
fold.o = fold.cpp
tree.o = tree.cpp