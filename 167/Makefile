TARGET := main
OBJECT := main.o

CXX := g++
CXX_FLAGS := -Wall -fsanitize=address -g -std=c++11

all:$(TARGET)
$(TARGET):$(OBJECT)
	$(CXX) $(CXX_FLAGS) -o $@ $^
%.o:%.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@
.PHONEY:all

clean:
	-rm -r $(TARGET) $(OBJECT)
.PHONEY:clean
