#include <iostream>
#include <utility>

void y(int&) { std::cout << '1'; }
void y(int&&) { std::cout << '2'; }

template <typename T>
void f(T && x) { y(x); }
template <typename T>
void g(T && x) { y(std::move(x)); }
template <typename T>
void h(T && x) { y(std::forward<T>(x)); }

int main() {
	int i=42;
	y(i);
	y(42);
	f(i);
	f(42);
	g(i);
	g(42);
	h(i);
	h(42);
}
