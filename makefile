main: funkcijos.o klase.o
	g++ -O3 -o main main.cpp funkcijos.o klase.o

testai: funkcijos.o klase.o
	g++ -O3 -o testai catch2/testai.cpp funkcijos.o klase.o
	./testai.exe

funkcijos: 
	g++ funkcijos.cpp

klase:
	g++ klase.cpp

run: main
	./main.exe

clean: 
	del *.o main.exe