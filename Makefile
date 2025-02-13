CC = gcc
CFLAGS = -Wall -std=c++11
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -lstdc++

SRC = src/main.cpp src/playerOne.cpp src/ball.cpp src/playerTwo.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = pong

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
