#include <iostream>
#include "boost/units/quantity.hpp"
#include "boost/units/systems/si.hpp"
#include "boost/units/systems/si/prefixes.hpp"
#include "boost/units/io.hpp"

int main(){
	// there are kilo/milli etc also in namespace std! <ratio>
	using namespace boost::units;
	using namespace boost::units::si;
	std::cout << "Enter km driven:" << std::endl;
	double y;
	std::cin >> y;
	quantity<length> dist{ y * si::kilo * meters };
	std::cout << "you drove " << engineering_prefix << dist;
	std::cout << "\nEnter liters:" << std::endl;
	double x;
	std::cin >> x;
	quantity<volume> const liter { 1 * si::milli * cubic_meter};
	// could define unit liter instead
	quantity<volume> vol= x * liter;
	std::cout << "You used " << 100 * x / y << " l/100km\n";
	std::cout << "You used " << 1e2 * vol / dist << "\n";
}
