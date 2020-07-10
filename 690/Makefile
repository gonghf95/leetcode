TARGET:=main
OBJECT:=main.o

CXX:=g++
CXXFLAGS:=-Wall -fsanitize=address -g -std=c++11

all:$(TARGET)
$(TARGET):$(OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^
%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
.PHONEY:all

clean:
	rm $(OBJECT) $(TARGET)
.PHONEY:clean