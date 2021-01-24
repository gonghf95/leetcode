TARGET:=main
OBJECT:=main.o

CC:=g++
CXXFLAGS:=-std=c++11 -Wall -g

all:$(TARGET)
$(TARGET):$(OBJECT)
	$(CC) $(CXXFLAGS) -o $@ $^
%.o:%.cc
	$(CC) $(CXXFLAGS) -c $< -o $@
.PHONY:all

clean:
	-rm $(TARGET) $(OBJECT)
.PHONY:clean
