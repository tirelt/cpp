CXX=g++
TARGET=main

$(TARGET): utils.cpp main.cpp utils.h
	$(CXX) -fdiagnostics-color=always -g utils.cpp main.cpp -I. -o $(TARGET)

run:
	./main

clean: 
	rm -f $(TARGET)