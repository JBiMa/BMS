#pragma once
#include <string>
using namespace std;


class User
{
protected:
    string username;
    string password;

public:
    User(string username, string password);
    
    bool checkCredentials(string username, string password);
};

