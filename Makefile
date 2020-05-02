CC=g++
SRC=testd.cpp
OBJ=$(SRC:.cpp=.0)
TARGET=testd
PREFIX=/usr/local/bin

all: $(TARGET)

$(TARGET): $(OBJ)

$(OBJ):
	$(CC) $(SRC) -o $(OBJ)

install:
	cp $(TARGET) $(PREFIX)/$(TARGET)

uninstall:
	rm -rf $(PREFIX)/$(TARGET)

clean:
	rm -rf $(TARGET) $(TARGET).0
