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
	cout << "Enter Voltage (3.3 or 5):"<< endl;
	double voltage { };
	cin >> voltage;
	auto u = voltage * volt;
	auto i = 20_mA;// * milli * ampere; is actually 0 Ampere because of ull type, that seems a bug in suffixes
	auto r = (u - 2_V)/i;
	cout << "resistor for " << i << " red LED should be "<< r << endl;
}
