all: libimp impconfig auth world

auth:
	g++ -o bin/acoreauth acoreauth.cpp /usr/local/lib/libimp.so -O2

world:
	g++ -o bin/acoreworld acoreworld.cpp /usr/local/lib/libimp.so -O2

impconfig:
	g++ -o bin/impconfig impconfig.cpp /usr/local/lib/libimp.so -O2

libimp:
	g++ -o bin/libimp.so -shared -fPIC Imp/*.cpp -O2

clean:
	rm bin/*

install:
	install -d /usr/local/etc/imp
	install -m 644 bin/libimp.so /usr/local/lib
	install -m 755 bin/impconfig /usr/local/bin
	install -m 755 bin/acoreauth /usr/local/bin
	install -m 755 bin/acoreworld /usr/local/bin
