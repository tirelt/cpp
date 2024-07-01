CXX=g++
TARGET=helloworld

$(TARGET): utils.cpp helloworld.cpp utils.h
	$(CXX) -fdiagnostics-color=always -g utils.cpp helloworld.cpp -I. -o $(TARGET)

run:
	./helloworld

clean: 
	rm -f $(TARGET)