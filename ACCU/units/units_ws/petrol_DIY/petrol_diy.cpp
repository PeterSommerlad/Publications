#include <iostream>
#include <boost/operators.hpp>
namespace units{
struct distance
		:private boost::multiplicative<distance,double>
		,boost::addable<distance>{
	explicit constexpr distance(double km=0):in_km{km}{};
	constexpr distance operator *=(double km){
		in_km*=km;
		return *this;
	}
	constexpr distance operator/=(double d){
		return *this *= 1/d;
	}
	constexpr distance operator +=(distance const &other){
		in_km+=other.in_km;
		return *this;
	}
	constexpr distance operator -=(distance const &other){
		return *this += distance{-other.in_km};
	}
	friend std::ostream & operator<<(std::ostream &out,distance const &v){
		out << v.in_km << " km ";
		return out;
	}
	friend std::istream & operator>>(std::istream &in,distance  &v){
		in >> v.in_km ;
		return in;
	}
	double in_km;
};
namespace literals{
constexpr auto operator"" _km(unsigned long long d){
	return distance(d);
}
constexpr auto operator"" _km(long double d){
	return distance(d);
}
}
struct usage{
	explicit constexpr usage(double l_100km=0):liters_100km{l_100km}{};
	friend std::ostream & operator<<(std::ostream &out,usage const &v){
		out << v.liters_100km << " l/100km ";
		return out;
	}
private:
	double liters_100km;
};
// boost operators can't do constexpr (yet?)
//static_assert(5==(distance{2}+distance{3}).in_km,"adding constepxr with boost works");

struct volume
	:private boost::multiplicative<volume,double>
	,boost::addable<volume>
	{
	explicit constexpr volume(double liters=0):in_liters{liters}{};
	volume operator *=(double d){
		in_liters*=d;
		return *this;
	}
	volume operator/=(double d){
		return *this *= 1/d;
	}

	volume operator +=(volume other){
		in_liters+=other.in_liters;
		return *this;
	}
	volume operator -=(volume other){
		return *this += volume{-other.in_liters};
	}
	friend std::ostream & operator<<(std::ostream &out,volume const &v){
		out << v.in_liters << " l ";
		return out;
	}
	friend std::istream & operator>>(std::istream &in,volume  &v){
		in >> v.in_liters ;
		return in;
	}
	double in_liters;
};
usage operator/(volume const &v,distance const &d)  {
		return usage{100*v.in_liters/d.in_km};
}
namespace literals{
constexpr auto operator"" _l(unsigned long long d){
	return volume(d);
}
constexpr auto operator"" _l(long double d){
	return volume(d);
}

}

}
int main(){
	using namespace std;
	using namespace units::literals;
	cout << "This program will show your petrol usage\n"
		 << "For example, if you enter " << 500_km << endl
		 << "and " << 40_l << endl
		 << "you should receive " << (40_l/500_km) << endl;
	cout << "Enter km driven:"<< endl;
	units::volume x{};
	units::distance y{};
	cin >> y;
	cout << "Enter liters:" << endl;
	cin >> x;
	cout << "You used " << x/y << "\n";// show compile error
	//cout << "You used " << y/x << "\n";
}



