DEBUG  ?= 0

CC		= g++
CFLAGS	= -Wall -Werror -Wextra -Wunused

ifeq ($(DEBUG), 1)
	CFLAGS += -DDEBUG
endif

output: main.o vector3d.o segment3d.o worker.o
	$(CC) main.o vector3d.o segment3d.o worker.o $(CFLAGS) -o app

main.o: Sources/main.cpp
	$(CC) $(CFLAGS) -c Sources/main.cpp

vector3d.o: Sources/vector3d.cpp
	$(CC) $(CFLAGS) -c Sources/vector3d.cpp

segment3d.o: Sources/segment3d.cpp
	$(CC) $(CFLAGS) -c Sources/segment3d.cpp

worker.o: Sources/worker.cpp
	$(CC) $(CFLAGS) -c Sources/worker.cpp

clean:
	rm *.o app