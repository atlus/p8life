run:
	clear
	g++ -ansi -pedantic -Wall main.c++ -o main.app
	valgrind main.app

rt:
	g++ -ansi -pedantic -lcppunit -ldl -Wall -DTEST main.c++ -o main.app
	valgrind main.app

gitcommit:
	git commit -a

