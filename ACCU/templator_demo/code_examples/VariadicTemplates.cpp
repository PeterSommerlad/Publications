#include <iostream>
void println(std::ostream const &out);

template<typename Head, typename... Tail>
void println(std::ostream &out, Head const& head, Tail const& ...tail) {
	out << head;
	if (sizeof...(tail)) {
		out << ", ";
		println(out,tail...);
	} else {
		out<< '\n';
	}
}

		void println(std::ostream const &out) {
	throw "never called";
}

int main(){
	println(std::cout, "one", 2, 3.0);
}
