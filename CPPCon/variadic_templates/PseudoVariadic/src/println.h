#ifndef PRINTLN_H_
#define PRINTLN_H_

#include <ostream>
inline
void printLn(std::ostream& out) {
	out.put('\n');
}

template<typename T1>
void printLn(std::ostream& out, T1 const & v1) {
	out << v1;
	out.put('\n');
}
template<typename T1,typename T2>
void printLn(std::ostream& out, T1 const & v1,T2 const & v2) {
	out << v1 << v2;
	out.put('\n');
}
template<typename T1,typename T2,typename T3>
void printLn(std::ostream& out, T1 const & v1,T2 const & v2,T3 const &v3) {
	out << v1 << v2 << v3;
	out.put('\n');
}
//... And so on
#endif /* PRINTLN_H_ */
