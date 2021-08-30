all: velha.o testa_velha.cpp
	g++ -std=c++11 -Wall -ftest-coverage -Ilib/ -fprofile-arcs velha.o testa_velha.cpp -o testa_velha.exe

velha.o : velha.cpp velha.hpp
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs -c velha.cpp

test: all check cpplint
	./testa_velha.exe
	gcov velha.cpp

check:
	cppcheck --enable=warning --suppress=catch.hpp .

cpplint:
	cpplint testa_velha.cpp
	cpplint velha.cpp

doxygen:
	doxygen

gcov:
	gcov velha.cpp

valgrind:
	valgrind --leak-check=full ./testa_velha.exe

cleangcov:
	rm -rf *.gc*

clean: cleangcov
	rm -rf *.o *.exe
