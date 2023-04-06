#include "User.h"
using namespace std;


User::User(string username, string password) {
    this->username = username;
    this->password = password;
}



bool User::checkCredentials(string username, string password) {
    return this->username == username && this->password == password;
}