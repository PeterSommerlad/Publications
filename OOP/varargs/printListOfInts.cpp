#include <ostream>
#include <cstdarg>
#include "printListOfInts.h"

void printListOfInts(std::ostream& out, size_t n, ...) {
	va_list args;
	va_start(args, n);
	while (n--) {
		out << va_arg(args, int) << ", ";
	}
	va_end(args);
	out << '\n';
}
