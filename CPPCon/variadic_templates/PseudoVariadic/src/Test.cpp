#include "println.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"


using namespace std::string_literals;


void testPrintLnNoArgs() {
	std::ostringstream out{};
	printLn(out);
	ASSERT_EQUAL("\n"s,out.str());
}
void testPrintLnOnArg() {
	std::ostringstream out{};
    printLn(out,1);
	ASSERT_EQUAL("1\n"s,out.str());
	printLn(out,"two");
	ASSERT_EQUAL("1\ntwo\n", out.str());
}
void testPrintLnTwoArgs(){
	std::ostringstream out{};
    printLn(out,1,2.3);
	ASSERT_EQUAL("12.3\n"s,out.str());
}
void testPrintLnThreeArgs(){
	std::ostringstream out{};
    printLn(out,1,2.3,"three");
	ASSERT_EQUAL("12.3three\n"s,out.str());
}



void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(testPrintLnNoArgs));
	s.push_back(CUTE(testPrintLnOnArg));
	s.push_back(CUTE(testPrintLnTwoArgs));
	s.push_back(CUTE(testPrintLnThreeArgs));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



