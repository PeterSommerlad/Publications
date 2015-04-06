#include <iostream>
using namespace std;


template <typename ... T>
void println(std::ostream & out, T const & ... t);

void println(std::ostream &out){
	out <<'\n';
}
template <typename HEAD, typename ... T>
void println(std::ostream & out,HEAD const &h, T const & ... t){
	out << h;
	if (sizeof...(t)){
		out <<", ";
	}
	println(out,t...);
}



int main() {
	println(std::cout, 1, 2.0, 3.14, 42, "hello", "hi",43);

}
