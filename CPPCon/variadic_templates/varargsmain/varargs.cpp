#include "printListOfInts.h"
#include <iostream>
#include <cstdarg>


int main(){
	printListOfInts(std::cout,5u, 1,2,3,4,5);
	printListOfInts(std::cout,3u, 1,2,3,4,5);
	printListOfInts(std::cout,5u, 1,2,3); // UB!
	printListOfInts(std::cout,3u, 1,2.5,4); // UB!

}

