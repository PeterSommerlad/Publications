#include <tuple>
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

using namespace std;

void tupledemo() {
	std::tuple<> empty;
	auto atuple= make_tuple(1,2.0,"three"s);
	int a;
	double b;
	string s;
	tie(a,b,s)=atuple;
	ASSERT_EQUAL(1,a);
	ASSERT_EQUAL(2.0,b);
	ASSERT_EQUAL("three"s,s);

}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(tupledemo));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



