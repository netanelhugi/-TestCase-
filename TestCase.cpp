#include "TestCase.hpp"
using namespace std;

TestCase::TestCase(string s, ostream &os) : failed(0), passed(0), total(0), output(os)
{
    testType = s;
}

ostream &TestCase::print()
{
    output << this->testType << ": " << failed << " failed, " << passed << " passed, " << total << " total." << endl;

    return output;
}
