#include <iostream>

int main(){
	using std::cout;
	using std::endl;
	using std::cin;
	cout << "Enter km driven:"<< endl;
	double x{},y{};
	cin >> x;
	cout << "Enter liters:" << endl;
	cin >> y;
	cout << "You used " << y/x << " liters per km\n";
}



