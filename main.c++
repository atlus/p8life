// ----------------------
// projects/life/main.c++
// Copyright (C) 2009
// Glenn P. Downing
// ----------------------

/*
To run the tests:
    % g++ -ansi -pedantic -lcppunit -ldl -Wall -DTEST main.c++ -o main.app
    % valgrind main.app

To run the program:
    % g++ -ansi -pedantic -Wall main.c++ -o main.app
    % valgrind main.app

To configure Doxygen:
    doxygen -g
That creates the file Doxyfile.
Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range

#include "Life.h"

#ifdef TEST
    #include "cppunit/TestSuite.h"      // TestSuite
    #include "cppunit/TextTestRunner.h" // TestRunner

    #include "TestLife.h"
#endif // TEST

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    #ifdef TEST
        // ----------
        // unit tests
        // ----------

        CppUnit::TextTestRunner tr;
        tr.addTest(TestLife::suite());
        tr.run();
    #else
        // -------
        // program
        // -------

        // -----------------------
        // life conway cell 109x69
        // -----------------------

        try {
            cout << "*** Life<ConwayCell> 109x69 ***" << endl << endl;
            /*
            read LifeConwayCell.in
            Print grid.
            Simulate 283 moves.
            Print grid.
            Simulate 40 moves.
            Print grid.
            Simulate 2500 moves.
            Print grid.
            */
			Life<ConwayCell> L;
			L.read("LifeConwayCell.in");
			L.print();
			L.simulate(283);
			L.print();
			L.simulate(40);
			L.print();
			L.simulate(2500);
			L.print();
        }
        catch (const invalid_argument&) {
            assert(false);}
        catch (const out_of_range&) {
            assert(false);}

        // -----------------------
        // life fredkin cell 20x20
        // -----------------------

        try {
            cout << "*** Life<FredkinCell> 20x20 ***" << endl << endl;
            /*
            read LifeFredkinCell.in
            Print grid.
            Simulate 2 moves.
            Print every grid.
            */
			Life<FredkinCell> L;
			L.read("LifeFredkinCell.in");
			L.print();
			L.simulate(1);
			L.print();
			L.simulate(1);
			L.print();
        }
        catch (const invalid_argument&) {
            assert(false);}
        catch (const out_of_range&) {
            assert(false);}

        // ---------------
        // life cell 20x20
        // ---------------

        try {
            cout << "*** Life<Cell> 20x20 ***" << endl << endl;
            /*
            read LifeCell.in
            Print grid.
            Simulate 5 moves.
            Print every grid.
            */
			Life<Cell> L;
			L.read("LifeCell.in");
			L.print();
			for (int i = 0; i < 5; ++i)
			{
				L.simulate(1);
				L.print();
			}
        }
        catch (const invalid_argument&) {
            assert(false);}
        catch (const out_of_range&) {
            assert(false);}
    #endif // NDEBUG

    return 0;}
