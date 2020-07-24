TARGET:=main
OBJECT:=main.o

CXX:=g++
CXXFLAGS:=-std=c++11 -Wall -fsanitize=address -g

all:$(TARGET)
$(TARGET):$(OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^
%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
.PHONEY:all

clean:
	rm $(OBJECT) $(TARGET)
.PHONEY:clean