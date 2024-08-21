output: main.o vector3d.o
	g++ main.o vector3d.o -o app

main.o: Sources/main.cpp
	g++ -c Sources/main.cpp

vector3d.o: Sources/vector3d.cpp
	g++ -c Sources/vector3d.cpp

segment3d.o: Sources/segment3d.cpp
	g++ -c Sources/segment3d.cpp

clean:
	rm *.o app