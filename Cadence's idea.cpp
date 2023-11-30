#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int start; 
    string password;
    string confirm;
    string rPass;
    const int rLen = 8;
    bool pass = false;
    bool number = false;
    bool cap = false;
    bool ateChar = false;
    bool lower = false;

    cout << "1 to create a password or 2 to generate a passowrd? " << endl;
    cin >> start;

    if (start == 1){
    cout << "Password must have a number, a capital letter, a lower case letter, and eight character." << endl;
    cout << "Enter Password: " << endl;
    cin >> password;
    while (pass != true){
        if (password.size() >= 8){
            ateChar = true;
        }
        for (int i = 0; i < password.size(); i++){
            if (isdigit(password[i])){
                number = true;
            }
            if (isupper(password[i])){
                cap = true;
            }
            if (islower(password[i])){
                lower = true;
            }
        }

        if (number == false){
            cout << "need at least one digit" << endl;
        }
        if (cap == false){
            cout << "need at least one capital letter" << endl;
        }
        if (ateChar == false){
            cout << "need at least eight characters" << endl;
        }
        if (lower == false){
            cout << "need at least one lowercase letter" << endl;;
        }

        if (number == true && cap == true && ateChar == true && lower == true){
            pass = true;
        }
        else {
            cin >> password;
        }
        }    

    if (pass == true){
        cout << "Good Password!" << endl;
    }
    }
    else if (start == 2){
    srand(static_cast<unsigned int>(time(nullptr)));

    const int length = 8;

    const char ch[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

    const int chLen = strlen(ch);

    char rPass[length];

    for (int i = 0; i < length; i++) {
        int rIn = rand() % chLen;

        rPass[i] = ch[rIn];
    }

    cout << "Your password is: " << rPass << endl;
    }

    return 0;
}