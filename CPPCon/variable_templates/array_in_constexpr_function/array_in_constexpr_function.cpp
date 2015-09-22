#include <array>

template <typename T, size_t n>
struct ar{
	constexpr ar():a{{}}{}
	constexpr T const & operator[](size_t i) const { return a[i];}
	constexpr T  & operator[](size_t i)  { return a[i];}
private:
	T a[n];
};

template <size_t n>
using arr=ar<size_t,n>;//std::array<size_t,n>;

template <size_t n>
constexpr auto make_tab(){
	arr<n> result { };
	for(size_t i=0; i < n; ++i)
		result[i] = (i+1)*(i+1);
	return result;
}


template <size_t n>
constexpr auto squares=make_tab<n>();

int dummy[squares<5>[3]]{};


int main(){
}
// the following won't compile:
/*
constexpr auto make_tab(size_t n){
	arr<n> result { };
	for(size_t i=0; i < n; ++i)
		result[i] = (i+1)*(i+1);
	return result;
}


template <size_t n>
constexpr auto squares1=make_tab(n);

int dummy1[squares1<5>[3]]{};
*/
