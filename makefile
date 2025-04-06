main: funkcijos.o
	g++ -O3 -o main main.cpp funkcijos.o

funkcijos: 
	g++ funkcijos.cpp

run: main
	./main.exe

clean: 
	del *.o main.exe