all: impconfig auth world

auth:
	g++ -o bin/impauth acoreauth.cpp /usr/local/lib/libimp.so -O2

world:
	g++ -o bin/impworld acoreworld.cpp /usr/local/lib/libimp.so -O2

impconfig:
	g++ -o bin/impconfig impconfig.cpp /usr/local/lib/libimp.so -O2

libimp:
	g++ -o bin/libimp.so -shared -fPIC Imp/*.cpp -O2

clean:
	rm bin/*

install-libimp:
	install -m 644 bin/libimp.so /usr/local/lib

install:
	install -d /usr/local/etc/imp
	install -m 755 bin/impconfig /usr/local/bin
	install -m 755 bin/impauth /usr/local/bin
	install -m 755 bin/impworld /usr/local/bin
