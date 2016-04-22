#include <iostream>
#include <phys/units/quantity.hpp>
#include <phys/units/io.hpp>
int main(){
	using std::cout;
	using std::endl;
	using std::cin;
	using namespace phys::units; // types
	using namespace phys::units::literals; // UDL
	using namespace phys::units::io; // operator <<(ostream&,...)
	cout << "Enter km driven:"<< endl;

	double x{};
	cin >> x;
	quantity<length_d> dist = x * kilo * meter;
	cout << "Enter liters:" << endl;
	double y{};
	cin >> y;
	quantity<volume_d> vol = y * liter;
	cout << "You used " << 100*y/x << " liters per 100 km\n";
	auto res = vol*hecto*kilo*meter/dist;
	cout << "You used " << res << "\n"; // 8 micro cubic meters
}

