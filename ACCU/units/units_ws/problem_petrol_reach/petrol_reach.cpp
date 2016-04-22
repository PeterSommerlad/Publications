#include <iostream>

int main(){
	using namespace std;
	cout << "Enter liters in gas tank:" << endl;
	double x{},y{};
	cin >> x;
	cout << "Enter average use in liters/ 100 km:" << endl;
	cin >> y;
	cout << "You can drive " << x / 100 * y << " km\n";
}



