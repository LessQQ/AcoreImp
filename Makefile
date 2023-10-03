all: libimp impconfig auth world

auth:
	g++ -o bin/acoreauth acoreauth.cpp bin/libimp.so -O2

world:
	g++ -o bin/acoreworld acoreworld.cpp bin/libimp.so -O2

impconfig:
	g++ -o bin/impconfig impconfig.cpp bin/libimp.so -O2

libimp:
	g++ -o bin/libimp.so -shared -fPIC Imp/*.cpp -O2

clean:
	rm bin/*
