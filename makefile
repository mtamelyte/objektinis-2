main: funkcijos.o klase.o
	g++ -O3 -o main main.cpp funkcijos.o klase.o

funkcijos: 
	g++ funkcijos.cpp

klase:
	g++ klase.cpp

run: main
	./main.exe

clean: 
	del *.o main.exe