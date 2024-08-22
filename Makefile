output: main.o vector3d.o segment3d.o worker.o
	g++ main.o vector3d.o segment3d.o worker.o -Wall -Wextra -Wunused -o app

main.o: Sources/main.cpp
	g++ -c Sources/main.cpp

vector3d.o: Sources/vector3d.cpp
	g++ -c Sources/vector3d.cpp

segment3d.o: Sources/segment3d.cpp
	g++ -c Sources/segment3d.cpp

worker.o: Sources/worker.cpp
	g++ -c Sources/worker.cpp

clean:
	rm *.o app