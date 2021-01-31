TARGET:=main
OBJECT:=main.o

CC:=g++
CXXFLAGS:=-Wall -g -std=c++11

all:$(TARGET)
$(TARGET):$(OBJECT)
	$(CC) $(CXXFLAGS) -o $@ $^
%.o:%.cc
	$(CC) $(CXXFLAGS) -c $< -o $@
.PHONEY:all

clean:
	-rm $(TAGET) $(OBJECT)
.PHONEY:clean
