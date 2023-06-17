#include <iostream>
#include <fstream>

using namespace std;

void sign_up() {
    string username;
    string password;
    string pin;

    cout << "Enter username: " << endl;
    cin >> username;
    
    cout << "Enter password: " << endl;
    cin >> password;

    while (password.length() < 7) {
        cout << "Enter password (over 7 characters): ";
        cin >> password;
    }

    cout << "Enter pin: " << endl;
    cin >> pin;

    while (pin.length() != 4) {
        cout << "Enter pin (4 characters): ";
        cin >> pin;
    }

    ofstream usernametxt("username.txt");
    if (usernametxt.is_open()) {
        usernametxt << username;
    }

    ofstream passwordtxt("password.txt");
    if (passwordtxt.is_open()) {
        passwordtxt << password;
    }

    ofstream pintxt("pin.txt");
    if (pintxt.is_open()) {
        pintxt << pin;
    }
}

void sign_in() {
    ifstream usernametxt("username.txt");
    ifstream passwordtxt("password.txt");
    ifstream pintxt("pin.txt");

    if (usernametxt.is_open()) {
        string usernamecontents;
        
        while (getline(usernametxt, usernamecontents)) {
            cout << usernamecontents;
        }
    }

    if (passwordtxt.is_open()) {
        string passwordcontents;
        
        while (getline(passwordtxt, passwordcontents)) {
            cout << passwordcontents;
        }
    }

    if (pintxt.is_open()) {
        string pincontents;
        
        while (getline(pintxt, pincontents)) {
            cout << pincontents;
        }
    }

}

int main() {
    int option_sign;

    cout << "TreeTrial\n------------------" << endl;
    cout << "1) Sign Up\n2) Log In" << endl;

    cin >> option_sign;

    if (option_sign == 1) {
        sign_up();
    } else {
        sign_in();
    }

    return 0;
}
