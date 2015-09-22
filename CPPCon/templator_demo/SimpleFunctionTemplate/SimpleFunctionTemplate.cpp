#include <iostream>

void printValue(bool value) {
	std::cout << std::boolalpha << value << '\n';
}

template<typename T>
void printValue(T value) {
	 std::cout << value << '\n';
}

template<typename T>
void print(T value) {
	std::cout << "Value: ";	printValue(value);
}

int main() {  // am einfachsten den Templator mit Cursor auf "main" oeffnen
	print(5); // dann muss er nicht zweimal geoeffnet werden
	print(true);
}
