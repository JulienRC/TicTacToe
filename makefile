bin/TicTacToe: obj/TicTacToe.o
	g++ obj/TicTacToe.o -o bin/TicTacToe
    
obj/TicTacToe.o: src/TicTacToe.cpp
	g++ -c src/TicTacToe.cpp -o obj/TicTacToe.o

clean:
	rm obj/*