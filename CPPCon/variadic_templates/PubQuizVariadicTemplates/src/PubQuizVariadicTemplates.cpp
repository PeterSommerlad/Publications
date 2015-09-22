#include <iostream>
template<typename T> void P(T x) {
	std::cout << x << ' ';
}
void foo(char a) {	P(3); P(a); }
template<typename ... A>
void foo(int a, A ... args) {
	foo(args...);
	P(a);
}
template<typename ... A>
void foo(char a, A ... args) {
	P(a);
	foo(args...);
}
int main() {
	foo('1', '2', 48, '4', '5');
}
