#include <iostream>

void println(std::ostream &out) ;

template<typename Head, typename... Tail>
void println(std::ostream &out, Head const& head, Tail const& ...tail) {
	out << head;
	if (sizeof...(tail)) {
		out << ", ";
	}
	println(out,tail...); //recurse on tail
}

void println(std::ostream &out) {
	out << "\n";
}



int main(){
	println(std::cout, "one", 2, 3.0);
}
