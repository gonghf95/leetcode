TARGET := main
OBJECT := main.o

CC := g++
CXX_FLAGS := -std=c++11 -Wall -g

all:$(TARGET)
$(TARGET):$(OBJECT)
	$(CC) $(CXX_FLAGS) -o $@ $^
%.o:%.cc
	$(CC) $(CXX_FLAGS) -c $< -o $@
.PHONEY:all

clean:
	-rm $(TARGET) *.o
.PHONTY:clean
