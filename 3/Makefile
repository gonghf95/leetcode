TARGET := main
OBJECT := main.o

CXX := g++
CXX_FLAGS := -Wall -g -std=c++11

all:$(TARGET)
$(TARGET):$(OBJECT)
	$(CXX) $(CXX_FLAGS) -o $@ $<
%.o:%.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@
.PHONEY:all

clean:
	-rm $(TARGET) $(OBJECT)
.PHONEY:clean
