#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

char keyboard[47] = {'`','1','2','3','4','5','6','7','8','9','0','-','=','Q','W','E','R','T','Y','U','I','O','P','[',']','\\','A','S','D','F','G','H','J','K','L',';','\'','Z','X','C','V','B','N','M',',','.','/'};

void changeChar(char c) {
    if (c == ' ') {
        printf(" ");
    } else {
        for (int i = 0; i < 47; i++) {
            if (keyboard[i] == c) {
                printf("%c", keyboard[i - 1]);
                break;
            }
        }
    }
}

int main() {
    string str;
    while(1) {
        getline(cin, str);

        if(str == "") break;

        char arr[str.size() + 1];
        strcpy(arr, str.c_str());

        for(int i = 0; i < sizeof(arr); i++) {
            changeChar(arr[i]);
        }

        cout << endl;
    }
}