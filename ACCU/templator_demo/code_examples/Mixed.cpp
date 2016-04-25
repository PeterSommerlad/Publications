#include <vector>
#include <initializer_list>
#include <deque>

template<typename T>
class Stack {
	std::vector<T> elems;
public:
	Stack(std::initializer_list<T> elemList) :
			elems { elemList } {}
	void add(T elem) {
		elems.push_back(elem);
	}
};

template<>
class Stack<double> {
	std::deque<double> elems;
public:
	Stack(std::initializer_list<double> values) :
			elems { values } {}
	void add(double elem) {
		elems.push_front(elem);
	}
};

template<typename F>
Stack<F> makeStack(std::initializer_list<F> elemList) {
	return Stack<F> { elemList };
}

int main() {
	// does not work with auto yet
	Stack<int> intVec = makeStack( { 4, 8, 15, 16, 23, 42 });
	intVec.add(108);
	Stack<bool> boolVec = makeStack( { true, false, true }); // bspsw. den enthaltenen vector<bool> innerhalb oeffnen und mit Ctrl(Cmd?)+F nach "flip" suchen
	Stack<double> deck = makeStack( { 2.71, 3.14 });
	deck.add(4.3);
}
