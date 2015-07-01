CC = g++
EXEC = AI-Chatbot
FLAGS = -Wall -std=c++11
LIBS =

all:
	$(CC) src/main.cpp -o $(EXEC) $(FLAGS) $(LIBS)

clean:
	rm $(EXEC)
