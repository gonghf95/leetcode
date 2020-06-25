TARGET:=main
OBJECT:=main.o

CXX:=g++
CXXFLAGS:=-Wall -std=c++11 -fsanitize=address -fno-omit-frame-pointer -g

all:$(TARGET)
$(TARGET):$(OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^
%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
.PHONEY:all

clean:
	rm $(OBJECT) $(TARGET)
.PHONEY:clean