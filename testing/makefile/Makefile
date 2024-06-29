.PHONY = create_objects
CXX=g++
PATH_SRC=src
PATH_LIB1=src/lib1
PATH_LIB2=src/lib2
PATH_INLUCE=include
TARGET=MyApp

SRCS := $(wildcard $(PATH_SRC)/*.cpp)
BINS := $(SRCS:%.cpp=%)
OBJS := $(SRCS:%cpp=%o)

all:$(PATH_LIB1)/lib1.a $(PATH_LIB2)/lib2.so $(TARGET)

$(TARGET): ${OBJS}
	${CXX} ${OBJS} $(PATH_LIB1)/lib1.a $(PATH_LIB2)/lib2.so -o $@

$(PATH_SRC)/%.o: $(PATH_SRC)/%.cpp $(PATH_INLUCE)/%.h
	${CXX} -c $< -I $(PATH_INLUCE) -o $@

$(PATH_LIB1)/lib1.a:$(PATH_LIB1)/*.cpp
	$(CXX) -c $(PATH_LIB1)/lib1.cpp -I $(PATH_INLUCE) -o $(PATH_LIB1)/lib1.o
	ar rcs $(PATH_LIB1)/lib1.a $(PATH_LIB1)/lib1.o

$(PATH_LIB2)/lib2.so:$(PATH_LIB2)/*.cpp
	$(CXX) -fPIC -c $(PATH_LIB2)/lib2.cpp -I $(PATH_INLUCE) -o $(PATH_LIB2)/lib2.o
	$(CXX) -shared -o $(PATH_LIB2)/lib2.so $(PATH_LIB2)/lib2.o


