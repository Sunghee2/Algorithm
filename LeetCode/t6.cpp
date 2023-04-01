#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
    int h, num;
} Number;

int t, max_height = 0, h;
string s, num;
vector<Number> v;

void printOne(int line) {
    string spot = ".";
    for(int i = 0; i < v[j].h - 1; i++) spot += ".";
    cout << spot << "#";
}

void printTwo(int line) {
    string spot = ".";
    string font = "#";
    if(line == 0 || line == ((max_height * 2) - 2) / 2 || line == (max_height * 2) - 2) {
        for(int i = 0; i < v[j].h; i++) font += "#";
        cout << font;
    } else if(line < ((max_height * 2) - 2) / 2) {
        for(int i = 0; i < v[j].h - 1; i++) spot += ".";
        cout << spot << "#";
    } else {
        for(int i = 0; i < v[j].h - 1; i++) spot += ".";
        cout << "#" << spot;        
    }
}

void printThree(int line) {
    string spot = ".";
    string font = "#";
    if(line == 0 || line == ((max_height * 2) - 2) / 2 || line == (max_height * 2) - 2) {
        for(int i = 0; i < v[j].h; i++) font += "#";
        cout << font;
    } else {
        for(int i = 0; i < v[j].h - 1; i++) spot += ".";
        cout << spot << "#";
    }
}

void printFour(int line) {
    string spot = ".";
    string font = "#";
    if(line == ((max_height * 2) - 2) / 2) {
        for(int i = 0; i < v[j].h; i++) font += "#";
        cout << font;
    } else if(line < ((max_height * 2) - 2) / 2) {
        for(int i = 0; i < v[j].h - 2; i++) spot += ".";
        cout << "#" << spot << "#";
    } else {
        for(int i = 0; i < v[j].h - 1; i++) spot += ".";
        cout << spot << "#";
    }
}

void printFive(int line) {
    string spot = ".";
    string font = "#";
    if(line == 0 || line == ((max_height * 2) - 2) / 2 || line == (max_height * 2) - 2) {
        for(int i = 0; i < v[j].h; i++) font += "#";
        cout << font;
    } else if(line < ((max_height * 2) - 2) / 2) {
        for(int i = 0; i < v[j].h - 1; i++) spot += ".";
        cout << "#" << spot; 
    } else {
        for(int i = 0; i < v[j].h - 1; i++) spot += ".";
        cout << spot << "#";
    }
}

void printSix(int line) {
    string spot = ".";
    string font = "#";
    if(line == ((max_height * 2) - 2) / 2 || line == (max_height * 2) - 2) {
        for(int i = 0; i < max_height; i++) font += "#";
        cout << font;
    } else if(line < ((max_height * 2) - 2) / 2) {
        for(int i = 0; i < max_height - 1; i++) spot += ".";
        cout << "#" << spot;
    } else {
        for(int i = 0; i < max_height - 2; i++) spot += ".";
        cout << "#" << spot << "#";        
    }
}

void printSeven(int line) {
    string spot = ".";
    string font = "#";
    if(line == 0) {
        for(int i = 0; i < max_height; i++) font += "#";
        cout << font;
    } else {
        for(int i = 0; i < max_height - 1; i++) spot += ".";
        cout << spot << "#";        
    }
}

void printEight(int line) {
    string spot = ".";
    string font = "#";
    if(line == 0 || line == ((max_height * 2) - 2) / 2 || line == (max_height * 2) - 2) {
        for(int i = 0; i < max_height; i++) font += "#";
        cout << font;
    } else {
        for(int i = 0; i < max_height - 2; i++) spot += ".";
        cout << "#" << spot << "#";        
    }
}

void printNine(int line) {
    string spot = ".";
    string font = "#";
    if(line == 0 || line == ((max_height * 2) - 2) / 2 ) {
        for(int i = 0; i < max_height; i++) font += "#";
        cout << font;
    } else if(line < ((max_height * 2) - 2) / 2){
        for(int i = 0; i < max_height - 2; i++) spot += ".";
        cout << "#" << spot << "#";        
    } else {
        for(int i = 0; i < max_height - 1; i++) spot += ".";
        cout << spot << "#";          
    }
}


void printZero(int line) {
    string spot = ".";
    string font = "#";
    if(line == 0 || line == ((max_height * 2) - 2)) {
        for(int i = 0; i < max_height; i++) font += "#";
        cout << font;
    } else {
        for(int i = 0; i < max_height - 2; i++) spot += ".";
        cout << "#" << spot << "#";          
    }
}



int main(void) {
    cin >> t >> s;
    for(int i = 0; i < t; i++) {
        cin >> h >> num;
        if(max_height < h) max_height = h;
        for(int j = 0; j < num.size(); j++) {
            Number n = {h, num.at(j) - '0'};
            v.push_back(n);
        }
    }
    
    for(int i = 0; i < (max_height * 2) - 1; i++) {
        for(int j = 0; j < v.size(); j++) {
            if(v[j].num == 0) printZero(v[j].h, i);
            else if(v[j].num == 1) printOne(v[j].h, i);
            else if(v[j].num == 2) printTwo(v[j].h, i);
            else if(v[j].num == 3) printThree(v[j].h, i);
            else if(v[j].num == 4) printFour(v[j].h, i);
            else if(v[j].num == 5) printFive(v[j].h, i);
            else if(v[j].num == 6) printSix(v[j].h, i);
            else if(v[j].num == 7) printSeven(v[j].h, i);
            else if(v[j].num == 8) printEight(v[j].h, i);
            else if(v[j].num == 9) printNine(v[j].h, i);
            cout << " ";
        }
        cout << endl;
    }
}