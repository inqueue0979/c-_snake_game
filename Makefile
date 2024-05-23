run:
	g++ -o run ./src/main.cpp -lncurses
	./run

clean:
	rm -f run