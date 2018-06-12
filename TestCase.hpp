#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class TestCase
{
    string testType;//test name
    int failed, passed, total;//test's numbers
    ostream &output;//stream for printing the results

  public:
    TestCase(string s, ostream &os);//constructor, get name and stream
    ostream &print();//print method

    //test 1: 
    //check if a==b
    template <typename T>
    TestCase &check_equal(T a, T b)
    {
        total++;

        if (a == b)
        {
            passed++;
        }
        else
        {
            failed++;
            output << this->testType << ": Failure in test #" << to_string(total) << ": " << a << " should equal " << b << "!" << endl;
        }
        return *this;
    }

    //test2:
    //check if a!=b
    template <typename T>
    TestCase &check_different(T a, T b)
    {
        total++;

        if (a != b)
        {
            passed++;
        }
        else
        {
            failed++;
            output << testType;

            output << this->testType << ": Failure in test #" << to_string(total) << ": " << a << " equal to " << b << "!" << endl;
        }
        return *this;
    }

    //test 3:
    //check if f(a)==b
    template <typename F, typename T>
    TestCase &check_function(F fun, T a, int b)
    {
        total++;

        if (fun(a) == b)
        {
            passed++;
        }
        else
        {
            failed++;
            output << this->testType << ": Failure in test #" << to_string(total) << ": Function should return " << b << " but returned " << fun(a) << "!" << endl;
        }
        return *this;
    }


    //test 4:
    //check if "a"==s
    template <typename T>
    TestCase &check_output(T a, string s)
    {
        total++;

        stringstream ss;
        ss << a;

        if (ss.str() == s)
        {
            passed++;
        }
        else
        {
            failed++;
            output << this->testType << ": Failure in test #" << to_string(total) << ": " << " string value should be " << a << " but is " << s << "!" << endl;
        }
        return *this;
    }
};