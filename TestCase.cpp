#include "TestCase.hpp"
using namespace std;

//constructor
//get test name(s), and ostream(os)
//init them and the test numbers
TestCase::TestCase(string s, ostream &os) : failed(0), passed(0), total(0), output(os)
{
    testType = s;
}

//print function
//return ostream from class
//and add to it the test numbers
ostream &TestCase::print()
{
    output << this->testType << ": " << failed << " failed, " << passed << " passed, " << total << " total." << endl;

    return output;
}
