#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class TestCase
{
    string testType;
    int failed, passed, total;
    ostream &output;

  public:
    TestCase(string s, ostream &os);
    ostream &print();

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
            output << this->testType << ": Failure in test #" << to_string(total) << ": " << a << " not equal to " << b << "!" << endl;
        }
        return *this;
    }

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
            output << this->testType << ": Failure in test #" << to_string(total) << ": " << a << " not equal to " << s << "!" << endl;
        }
        return *this;
    }
};