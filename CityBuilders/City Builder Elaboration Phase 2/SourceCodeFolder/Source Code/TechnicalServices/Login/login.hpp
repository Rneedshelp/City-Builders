#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;


//login stub interface.

//Technical Services from Package Diagram (logical view)     
class Login
{
    public:
    Login(){}
    ~Login(){}
    virtual bool signIn(string username, string password) = 0;

};

//instance of login stub interface- SimpleLogin
//Technical Services (Log In package)
class SimpleLogin: public Login
{
    public:
    SimpleLogin(){}
    ~SimpleLogin(){}
    bool signIn(string username, string password)
    {
        return true;
    }

};
