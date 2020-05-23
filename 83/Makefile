TARGET:=main
OBJECT:=main.o

CXX:=g++
CXXFLAGS:=-Wall -g -std=c++11

all:$(TARGET)
$(TARGET):$(OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^
%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
.PHONEY:all

clean:
	rm $(TARGET) $(OBJECT)
.PHONEY: clean
