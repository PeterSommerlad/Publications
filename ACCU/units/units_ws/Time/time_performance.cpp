//
// time-performance.cpp - performance measurement for quantity library
//
// Copyright (c) 2001 by Michael S. Kenniston.  The most recent
// version will be available at www.xnet.com/~msk/quantity.  Permission is granted
// to use this code without restriction so long as this copyright
// notice appears in all source files.
//
// This code is provided as-is, with no warrantee of correctness.

// This program tests the quantity library to verify that the
// performance of quantity computations is the same as that of
// the underlying double operations.

#include "phys/units/quantity.hpp"
#include "phys/units/quantity_io.hpp"

#include <iomanip>
#include <iostream>
//#include <time.h>
#include <chrono>
using namespace phys::units;
using namespace phys::units::io;
using namespace std;

const int meg = 1000000;
const int k = 60; // scale factor - make it bigger for faster machines

template< typename T1, typename T2, typename T3 >
T1 do_work( T1 v1, T2 v2, T3 v3 )
{
    // Do a bunch of work.  We don't really care about the answer;
    // this is just to exercise addition, subtraction, multiplication, and division.
    T1 x1 = v1;
    T2 x2 = v2;
    T3 x3 = v3;
    for( int i = 0; i < meg; i++ )
    {
        for( int j = 0; j < k; j++ )
        {
            x2 = -x2 - v2;
            x3 *= 1.00002;
            x1 += x2 / x3;
        }
    }
    return x1;
}


const quantity< electric_resistance_d > biga( 2 * ohm );
const quantity< electric_conductance_d > bigb( siemens / 2 );

quantity< speed_d > do_more_work(
            quantity< speed_d > v1,
            quantity< length_d > v2,
            quantity< time_interval_d > v3 )
{
    // Do a bunch of work.  We don't really care about the answer;
    // this is just to exercise addition, subtraction, multiplication, and division.
    quantity< speed_d > x1 = v1;
    quantity< length_d > x2 = v2;
    quantity< time_interval_d > x3 = v3;
    for( int i = 0; i < meg; i++ )
    {
        for( int j = 0; j < k; j++ )
        {
            x2 = -x2 - v2;
            x3 *= biga * 1.00002 * bigb;
            x1 += x2 / x3;
        }
    }
    return x1;
}

template< typename T >
T use( T const & x ) { return x; }

int main( int argc, char * argv[] )
{
	auto input = 10+argc;
    use( argc );
    cout << argv[0] << ": Performance test of quantity library." << endl;
    using namespace std::chrono;
    high_resolution_clock clock{};
    auto const t0 = clock.now();

    // do some work with doubles
    //volatile double d = do_work( 0.1, 0.2, 0.3 );
    volatile double d{};
    for (int i=1; i < input; ++i)
    	 d += do_work( i*0.1, 0.2, 0.3 );
    auto const t1 = clock.now();

    // do exact same work with quantity
    //quantity< speed_d > s = do_work( 0.1*meter/second, 0.2*meter, 0.3*second );
    quantity< speed_d > s{};
    for (int i=1; i < input; ++i)
    	s+= do_work( i*0.1*meter/second, 0.2*meter, 0.3*second );

    auto const t2 = clock.now();

    quantity< speed_d > s2 = do_more_work( 0.1*meter/second, 0.2*meter, 0.3*second );

    auto const t3 = clock.now();


    auto const tdb = duration_cast<microseconds>(t1-t0);
    auto const tq1 = duration_cast<microseconds>(t2-t1);
    auto const tq2 = duration_cast<microseconds>(t3-t2);


    cout << std::setprecision( 3 );
    cout << "one double work loop     = " << tdb.count() << " usec  (1)" << endl;
    cout << "one quantity work loop   = " << tq1.count() << " usec  ("   << 1.0*tq1.count()/tdb.count() << ")" <<  endl;
    cout << "one quantity++ work loop = " << tq2.count() << " usec  ("   << 1.0*tq2.count()/tdb.count() << ")" << endl;

    cout << std::setprecision( 5 );
    cout << "d = " << d << endl;
    cout << "s = " << s << endl << std::endl;
    cout << "s2 = " << s2 << endl<< std::endl;

    return 0;
}
