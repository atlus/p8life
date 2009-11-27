// ------------------------
// projects/life/TestLife.h
// Copyright (C) 2009
// Glenn P. Downing
// ------------------------

#ifndef TestLife_h
#define TestLife_h

// --------
// includes
// --------

#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END

// ----------
// namespaces
// ----------

namespace cs {
// --------
// TestLife
// --------

struct TestLife : CppUnit::TestFixture {
    // -----
    // tests
    // -----

   void testFredAlive(){
        FredkinCell fred('0');
        CPPUNIT_ASSERT(fred.symbol() == '0');
    }
   void testFredDead(){
        FredkinCell fred('-');
        CPPUNIT_ASSERT(fred.symbol() == '-');
    }
    void testConAlive(){
        ConwayCell con('*'); 
        //std::cout << con.symbol() << std::endl;
        CPPUNIT_ASSERT(con.symbol() == '*');
    }
    void testConDead(){
        ConwayCell con('.'); 
        
        CPPUNIT_ASSERT(con.symbol() == '.');
    }
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(testFredAlive);
    CPPUNIT_TEST(testFredDead);
    CPPUNIT_TEST(testConAlive);
    CPPUNIT_TEST(testConDead);
    CPPUNIT_TEST_SUITE_END();};

} // cs

#endif // TestLife_h

 
