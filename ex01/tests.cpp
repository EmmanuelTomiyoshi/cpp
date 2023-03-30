#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

int main() {
    cout << "Enter password: ";
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    string password;
    getline(cin, password);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    cout << "\nPassword entered: " << password << endl;
    return 0;
}