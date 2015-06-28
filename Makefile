CC = g++
EXEC = AI-Chatbot
FLAGS = -Wall
LIBS =

all:
	$(CC) src/main.cpp -o $(EXEC) $(FLAGS) $(LIBS)

clean:
	rm $(EXEC)
