#include <iostream>
#include <cstring>
using namespace std;

int tc, n;
char cube_top[3][3], cube_back[3][3], cube_left[3][3];
char cube_right[3][3], cube_bottom[3][3], cube_front[3][3];

void init() {
    memset(cube_top, 'w', sizeof(cube_top));
    memset(cube_back, 'o', sizeof(cube_back));
    memset(cube_left, 'g', sizeof(cube_left));
    memset(cube_right, 'b', sizeof(cube_right));
    memset(cube_bottom, 'y', sizeof(cube_bottom));
    memset(cube_front, 'r', sizeof(cube_front));
}

void turnCube(char side, char direction) {
    char tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;

    if(side == 'U') {
        if(direction == '+') {
            tmp1 = cube_right[0][0];
            tmp2 = cube_right[1][0];
            tmp3 = cube_right[2][0];
            cube_right[0][0] = cube_back[2][0];
            cube_right[1][0] = cube_back[2][1];
            cube_right[2][0] = cube_back[2][2];
            tmp4 = cube_front[0][0];
            tmp5 = cube_front[0][1];
            tmp6 = cube_front[0][2];
            cube_front[0][0] = tmp3;
            cube_front[0][1] = tmp2;
            cube_front[0][2] = tmp1;    
            tmp1 = cube_left[0][2];
            tmp2 = cube_left[1][2];
            tmp3 = cube_left[2][2];
            cube_left[0][2] = tmp4;
            cube_left[1][2] = tmp5;
            cube_left[2][2] = tmp6;  
            cube_back[2][0] = tmp3;
            cube_back[2][1] = tmp2;
            cube_back[2][2] = tmp1; 

            tmp1 = cube_top[0][2];
            tmp2 = cube_top[1][2];
            tmp3 = cube_top[2][2];
            cube_top[0][2] = cube_top[0][0];
            cube_top[1][2] = cube_top[0][1];
            cube_top[2][2] = cube_top[0][2];
            tmp4 = cube_top[2][0];
            tmp5 = cube_top[2][1];
            cube_top[2][0] = tmp3;
            cube_top[2][1] = tmp2;
            cube_top[2][2] = tmp1;
            tmp1 = cube_top[0][0];
            tmp2 = cube_top[1][0];
            cube_top[0][0] = tmp4;
            cube_top[1][0] = tmp5;
            cube_top[0][1] = tmp2;                      
        } else if(direction == '-') {
            tmp1 = cube_left[0][2];
            tmp2 = cube_left[1][2];
            tmp3 = cube_left[2][2];
            cube_left[0][2] = cube_back[2][2];
            cube_left[1][2] = cube_back[2][1];
            cube_left[2][2] = cube_back[2][0];
            tmp4 = cube_front[0][0];
            tmp5 = cube_front[0][1];
            tmp6 = cube_front[0][2];
            cube_front[0][0] = tmp1;
            cube_front[0][1] = tmp2;
            cube_front[0][2] = tmp3;
            tmp1 = cube_right[0][0];
            tmp2 = cube_right[1][0];
            tmp3 = cube_right[2][0];
            cube_right[0][0] = tmp6;
            cube_right[1][0] = tmp5;
            cube_right[2][0] = tmp4;
            cube_back[2][0] = tmp1;
            cube_back[2][1] = tmp2;
            cube_back[2][2] = tmp3;

            tmp1 = cube_top[0][0];
            tmp2 = cube_top[1][0];
            tmp3 = cube_top[2][0];
            cube_top[0][0] = cube_top[0][0];
            cube_top[1][0] = cube_top[0][1];
            cube_top[2][0] = cube_top[0][2]; 
            tmp5 = cube_top[2][1];
            tmp6 = cube_top[2][2];
            cube_top[2][0] = tmp1;
            cube_top[2][1] = tmp2;
            cube_top[2][2] = tmp3;
            tmp1 = cube_top[0][2];
            tmp2 = cube_top[1][2];
            cube_top[0][2] = tmp3;
            cube_top[1][2] = tmp5;
            cube_top[0][0] = tmp1;
            cube_top[0][1] = tmp2;
            cube_top[0][2] = tmp6;           
        }
    } else if(side == 'D') {
        if(direction == '+') {
            tmp1 = cube_right[0][2];
            tmp2 = cube_right[1][2];
            tmp3 = cube_right[2][2];
            cube_right[0][2] = cube_front[2][2];
            cube_right[1][2] = cube_front[2][1];
            cube_right[2][2] = cube_front[2][0];
            tmp4 = cube_back[0][0];
            tmp5 = cube_back[0][1];
            tmp6 = cube_back[0][2];
            cube_back[0][0] = tmp1;
            cube_back[0][1] = tmp2;
            cube_back[0][2] = tmp3;
            tmp1 = cube_left[0][0];
            tmp2 = cube_left[1][0];
            tmp3 = cube_left[2][0]; 
            cube_left[0][0] = tmp6;
            cube_left[1][0] = tmp5;
            cube_left[2][0] = tmp4;
            cube_front[2][0] = tmp1;
            cube_front[2][1] = tmp2;
            cube_front[2][2] = tmp3; 

            tmp1 = cube_bottom[0][2];
            tmp2 = cube_bottom[1][2];
            tmp3 = cube_bottom[2][2];
            cube_bottom[0][2] = cube_bottom[0][0];
            cube_bottom[1][2] = cube_bottom[0][1];
            cube_bottom[2][2] = cube_bottom[0][2];
            tmp4 = cube_bottom[2][0];
            tmp5 = cube_bottom[2][1];
            cube_bottom[2][0] = tmp3;
            cube_bottom[2][1] = tmp2;
            cube_bottom[2][2] = tmp1;
            tmp1 = cube_bottom[0][0];
            tmp2 = cube_bottom[1][0];
            cube_bottom[0][0] = tmp4;
            cube_bottom[1][0] = tmp5;
            cube_bottom[0][1] = tmp2;                             
        } else if(direction == '-') {
            tmp1 = cube_left[0][0];
            tmp2 = cube_left[1][0];
            tmp3 = cube_left[2][0];     
            cube_left[0][0] = cube_front[2][0];
            cube_left[1][0] = cube_front[2][1];
            cube_left[2][0] = cube_front[2][2];   
            tmp4 = cube_back[0][0];
            tmp5 = cube_back[0][1];
            tmp6 = cube_back[0][2];    
            cube_back[0][0] = tmp3;
            cube_back[0][1] = tmp2;
            cube_back[0][2] = tmp1;
            tmp1 = cube_right[0][2];
            tmp2 = cube_right[1][2];
            tmp3 = cube_right[2][2];
            cube_right[0][2] = tmp4;
            cube_right[1][2] = tmp5;
            cube_right[2][2] = tmp6;
            cube_front[2][0] = tmp3;
            cube_front[2][1] = tmp2;
            cube_front[2][2] = tmp1; 

            tmp1 = cube_bottom[0][0];
            tmp2 = cube_bottom[1][0];
            tmp3 = cube_bottom[2][0];
            cube_bottom[0][0] = cube_bottom[0][0];
            cube_bottom[1][0] = cube_bottom[0][1];
            cube_bottom[2][0] = cube_bottom[0][2]; 
            tmp5 = cube_bottom[2][1];
            tmp6 = cube_bottom[2][2];
            cube_bottom[2][0] = tmp1;
            cube_bottom[2][1] = tmp2;
            cube_bottom[2][2] = tmp3;
            tmp1 = cube_bottom[0][2];
            tmp2 = cube_bottom[1][2];
            cube_bottom[0][2] = tmp3;
            cube_bottom[1][2] = tmp5;
            cube_bottom[0][0] = tmp1;
            cube_bottom[0][1] = tmp2;
            cube_bottom[0][2] = tmp6;                         
        }
    } else if(side == 'F') {
        if(direction == '+') {
            tmp1 = cube_right[2][0];
            tmp2 = cube_right[2][1];
            tmp3 = cube_right[2][2];
            cube_right[2][0] = cube_top[2][0];
            cube_right[2][1] = cube_top[2][1];
            cube_right[2][2] = cube_top[2][2];
            tmp4 = cube_bottom[0][0];
            tmp5 = cube_bottom[0][1];
            tmp6 = cube_bottom[0][2];
            cube_bottom[0][0] = tmp3;
            cube_bottom[0][1] = tmp2;
            cube_bottom[0][2] = tmp1;
            tmp1 = cube_left[2][0];
            tmp2 = cube_left[2][1];
            tmp3 = cube_left[2][2];     
            cube_left[0][0] = tmp6;
            cube_left[1][0] = tmp5;
            cube_left[2][0] = tmp4;      
            cube_top[2][0] = tmp1;
            cube_top[2][1] = tmp2;
            cube_top[2][2] = tmp3; 

            tmp1 = cube_front[0][2];
            tmp2 = cube_front[1][2];
            tmp3 = cube_front[2][2];
            cube_front[0][2] = cube_front[0][0];
            cube_front[1][2] = cube_front[0][1];
            cube_front[2][2] = cube_front[0][2];
            tmp4 = cube_front[2][0];
            tmp5 = cube_front[2][1];
            cube_front[2][0] = tmp3;
            cube_front[2][1] = tmp2;
            cube_front[2][2] = tmp1;
            tmp1 = cube_front[0][0];
            tmp2 = cube_front[1][0];
            cube_front[0][0] = tmp4;
            cube_front[1][0] = tmp5;
            cube_front[0][1] = tmp2;   
        } else if(direction == '-') {
            tmp1 = cube_left[2][0];
            tmp2 = cube_left[2][1];
            tmp3 = cube_left[2][2];     
            cube_left[2][0] = cube_top[2][0];
            cube_left[2][1] = cube_top[2][1];
            cube_left[2][2] = cube_top[2][2];   
            tmp4 = cube_bottom[0][0];
            tmp5 = cube_bottom[0][1];
            tmp6 = cube_bottom[0][2];
            cube_bottom[0][0] = tmp3;
            cube_bottom[0][1] = tmp2;
            cube_bottom[0][2] = tmp1; 
            tmp1 = cube_right[2][0];
            tmp2 = cube_right[2][1];
            tmp3 = cube_right[2][2];
            cube_right[2][0] = tmp6;
            cube_right[2][1] = tmp5;
            cube_right[2][2] = tmp4;  
            cube_top[2][0] = tmp1;
            cube_top[2][1] = tmp2;
            cube_top[2][2] = tmp3; 

            tmp1 = cube_front[0][0];
            tmp2 = cube_front[1][0];
            tmp3 = cube_front[2][0];
            cube_front[0][0] = cube_front[0][0];
            cube_front[1][0] = cube_front[0][1];
            cube_front[2][0] = cube_front[0][2]; 
            tmp5 = cube_front[2][1];
            tmp6 = cube_front[2][2];
            cube_front[2][0] = tmp1;
            cube_front[2][1] = tmp2;
            cube_front[2][2] = tmp3;
            tmp1 = cube_front[0][2];
            tmp2 = cube_front[1][2];
            cube_front[0][2] = tmp3;
            cube_front[1][2] = tmp5;
            cube_front[0][0] = tmp1;
            cube_front[0][1] = tmp2;
            cube_front[0][2] = tmp6;         
        }
    } else if(side == 'B') {
        if(direction == '+') {
            tmp1 = cube_right[0][0];
            tmp2 = cube_right[0][1];
            tmp3 = cube_right[0][2];
            cube_right[0][0] = cube_bottom[2][2];
            cube_right[0][1] = cube_bottom[2][1];
            cube_right[0][2] = cube_bottom[2][0];
            tmp4 = cube_top[0][0];
            tmp5 = cube_top[0][1];
            tmp6 = cube_top[0][2];   
            cube_top[0][0] = tmp1;
            cube_top[0][1] = tmp2;
            cube_top[0][2] = tmp3;  
            tmp1 = cube_left[0][0];
            tmp2 = cube_left[0][1];
            tmp3 = cube_left[0][2];     
            cube_left[0][0] = tmp4;
            cube_left[0][1] = tmp5;
            cube_left[0][2] = tmp6;  
            cube_bottom[2][0] = tmp3;
            cube_bottom[2][1] = tmp2;
            cube_bottom[2][2] = tmp1; 

            tmp1 = cube_back[0][2];
            tmp2 = cube_back[1][2];
            tmp3 = cube_back[2][2];
            cube_back[0][2] = cube_back[0][0];
            cube_back[1][2] = cube_back[0][1];
            cube_back[2][2] = cube_back[0][2];
            tmp4 = cube_back[2][0];
            tmp5 = cube_back[2][1];
            cube_back[2][0] = tmp3;
            cube_back[2][1] = tmp2;
            cube_back[2][2] = tmp1;
            tmp1 = cube_back[0][0];
            tmp2 = cube_back[1][0];
            cube_back[0][0] = tmp4;
            cube_back[1][0] = tmp5;
            cube_back[0][1] = tmp2;         
        } else if(direction == '-') {
            tmp1 = cube_left[0][0];
            tmp2 = cube_left[0][1];
            tmp3 = cube_left[0][2];     
            cube_left[0][0] = cube_bottom[2][2];
            cube_left[0][1] = cube_bottom[2][1];
            cube_left[0][2] = cube_bottom[2][0];  
            tmp4 = cube_top[0][0];
            tmp5 = cube_top[0][1];
            tmp6 = cube_top[0][2];   
            cube_top[0][0] = tmp1;
            cube_top[0][1] = tmp2;
            cube_top[0][2] = tmp3; 
            tmp1 = cube_right[0][0];
            tmp2 = cube_right[0][1];
            tmp3 = cube_right[0][2];
            cube_right[0][0] = tmp4;
            cube_right[0][1] = tmp5;
            cube_right[0][2] = tmp6;  
            cube_bottom[2][0] = tmp3;
            cube_bottom[2][1] = tmp2;
            cube_bottom[2][2] = tmp1;

            tmp1 = cube_back[0][0];
            tmp2 = cube_back[1][0];
            tmp3 = cube_back[2][0];
            cube_back[0][0] = cube_back[0][0];
            cube_back[1][0] = cube_back[0][1];
            cube_back[2][0] = cube_back[0][2]; 
            tmp5 = cube_back[2][1];
            tmp6 = cube_back[2][2];
            cube_back[2][0] = tmp1;
            cube_back[2][1] = tmp2;
            cube_back[2][2] = tmp3;
            tmp1 = cube_back[0][2];
            tmp2 = cube_back[1][2];
            cube_back[0][2] = tmp3;
            cube_back[1][2] = tmp5;
            cube_back[0][0] = tmp1;
            cube_back[0][1] = tmp2;
            cube_back[0][2] = tmp6;                    
        }
    } else if(side == 'L') {
        if(direction == '+') {
            tmp1 = cube_top[0][0];
            tmp2 = cube_top[1][0];
            tmp3 = cube_top[2][0];   
            cube_top[0][0] = cube_back[0][0];
            cube_top[1][0] = cube_back[1][0];
            cube_top[2][0] = cube_back[2][0];  
            tmp4 = cube_front[0][0];
            tmp5 = cube_front[1][0];
            tmp6 = cube_front[2][0];
            cube_front[0][0] = tmp1;
            cube_front[1][0] = tmp2;
            cube_front[2][0] = tmp3; 
            tmp1 = cube_bottom[0][0];
            tmp2 = cube_bottom[1][0];
            tmp3 = cube_bottom[2][0];
            cube_bottom[0][0] = tmp4;
            cube_bottom[1][0] = tmp5;
            cube_bottom[2][0] = tmp6;
            cube_back[0][0] = tmp1;
            cube_back[1][0] = tmp2;
            cube_back[2][0] = tmp3;

            tmp1 = cube_left[0][2];
            tmp2 = cube_left[1][2];
            tmp3 = cube_left[2][2];
            cube_left[0][2] = cube_left[0][0];
            cube_left[1][2] = cube_left[0][1];
            cube_left[2][2] = cube_left[0][2];
            tmp4 = cube_left[2][0];
            tmp5 = cube_left[2][1];
            cube_left[2][0] = tmp3;
            cube_left[2][1] = tmp2;
            cube_left[2][2] = tmp1;
            tmp1 = cube_left[0][0];
            tmp2 = cube_left[1][0];
            cube_left[0][0] = tmp4;
            cube_left[1][0] = tmp5;
            cube_left[0][1] = tmp2;                       
        } else if(direction == '-') {
            tmp1 = cube_bottom[0][0];
            tmp2 = cube_bottom[1][0];
            tmp3 = cube_bottom[2][0];
            cube_bottom[0][0] = cube_back[0][0];
            cube_bottom[1][0] = cube_back[1][0];
            cube_bottom[2][0] = cube_back[2][0];  
            tmp4 = cube_front[0][0];
            tmp5 = cube_front[1][0];
            tmp6 = cube_front[2][0];
            cube_front[0][0] = tmp1;
            cube_front[1][0] = tmp2;
            cube_front[2][0] = tmp3;  
            tmp1 = cube_top[0][0];
            tmp2 = cube_top[1][0];
            tmp3 = cube_top[2][0];   
            cube_top[0][0] = tmp4;
            cube_top[1][0] = tmp5;
            cube_top[2][0] = tmp6; 
            cube_back[0][0] = tmp1;
            cube_back[1][0] = tmp2;
            cube_back[2][0] = tmp3;  

            tmp1 = cube_left[0][0];
            tmp2 = cube_left[1][0];
            tmp3 = cube_left[2][0];
            cube_left[0][0] = cube_left[0][0];
            cube_left[1][0] = cube_left[0][1];
            cube_left[2][0] = cube_left[0][2]; 
            tmp5 = cube_left[2][1];
            tmp6 = cube_left[2][2];
            cube_left[2][0] = tmp1;
            cube_left[2][1] = tmp2;
            cube_left[2][2] = tmp3;
            tmp1 = cube_left[0][2];
            tmp2 = cube_left[1][2];
            cube_left[0][2] = tmp3;
            cube_left[1][2] = tmp5;
            cube_left[0][0] = tmp1;
            cube_left[0][1] = tmp2;
            cube_left[0][2] = tmp6;                      
        }
    } else if(side == 'R') {
        if(direction == '+') {
            tmp1 = cube_bottom[0][2];
            tmp2 = cube_bottom[1][2];
            tmp3 = cube_bottom[2][2];
            cube_bottom[0][2] = cube_back[0][2];
            cube_bottom[1][2] = cube_back[1][2];
            cube_bottom[2][2] = cube_back[2][2];  
            tmp4 = cube_front[0][2];
            tmp5 = cube_front[1][2];
            tmp6 = cube_front[2][2];
            cube_front[0][2] = tmp1;
            cube_front[1][2] = tmp2;
            cube_front[2][2] = tmp3;  
            tmp1 = cube_top[0][2];
            tmp2 = cube_top[1][2];
            tmp3 = cube_top[2][2];   
            cube_top[0][2] = tmp4;
            cube_top[1][2] = tmp5;
            cube_top[2][2] = tmp6; 
            cube_back[0][2] = tmp1;
            cube_back[1][2] = tmp2;
            cube_back[2][2] = tmp3; 

            tmp1 = cube_right[0][2];
            tmp2 = cube_right[1][2];
            tmp3 = cube_right[2][2];
            cube_right[0][2] = cube_right[0][0];
            cube_right[1][2] = cube_right[0][1];
            cube_right[2][2] = cube_right[0][2];
            tmp4 = cube_right[2][0];
            tmp5 = cube_right[2][1];
            cube_right[2][0] = tmp3;
            cube_right[2][1] = tmp2;
            cube_right[2][2] = tmp1;
            tmp1 = cube_right[0][0];
            tmp2 = cube_right[1][0];
            cube_right[0][0] = tmp4;
            cube_right[1][0] = tmp5;
            cube_right[0][1] = tmp2;           
        } else if(direction == '-') {
            tmp1 = cube_top[0][2];
            tmp2 = cube_top[1][2];
            tmp3 = cube_top[2][2];   
            cube_top[0][2] = cube_back[0][2];
            cube_top[1][2] = cube_back[1][2];
            cube_top[2][2] = cube_back[2][2];  
            tmp4 = cube_front[0][2];
            tmp5 = cube_front[1][2];
            tmp6 = cube_front[2][2];
            cube_front[0][2] = tmp1;
            cube_front[1][2] = tmp2;
            cube_front[2][2] = tmp3; 
            tmp1 = cube_bottom[0][2];
            tmp2 = cube_bottom[1][2];
            tmp3 = cube_bottom[2][2];
            cube_bottom[0][2] = tmp4;
            cube_bottom[1][2] = tmp5;
            cube_bottom[2][2] = tmp6;
            cube_back[0][2] = tmp1;
            cube_back[1][2] = tmp2;
            cube_back[2][2] = tmp3;  

            tmp1 = cube_right[0][0];
            tmp2 = cube_right[1][0];
            tmp3 = cube_right[2][0];
            cube_right[0][0] = cube_right[0][0];
            cube_right[1][0] = cube_right[0][1];
            cube_right[2][0] = cube_right[0][2]; 
            tmp5 = cube_right[2][1];
            tmp6 = cube_right[2][2];
            cube_right[2][0] = tmp1;
            cube_right[2][1] = tmp2;
            cube_right[2][2] = tmp3;
            tmp1 = cube_right[0][2];
            tmp2 = cube_right[1][2];
            cube_right[0][2] = tmp3;
            cube_right[1][2] = tmp5;
            cube_right[0][0] = tmp1;
            cube_right[0][1] = tmp2;
            cube_right[0][2] = tmp6;           
        }
    }
}

void printCubeTop() {
    cout << "======top=====" <<endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << cube_top[i][j];
        }
        cout << endl;
    }
    cout << "======left=====" <<endl;
        for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << cube_left[i][j];
        }
        cout << endl;
    }
        cout << "======right=====" <<endl;
        for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << cube_right[i][j];
        }
        cout << endl;
    }
            cout << "======back=====" <<endl;
        for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << cube_back[i][j];
        }
        cout << endl;
    }
                    cout << "======front=====" <<endl;
        for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << cube_front[i][j];
        }
        cout << endl;
    }
                cout << "======bottom=====" <<endl;
        for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << cube_bottom[i][j];
        }
        cout << endl;
    }
}

int main() {
    char input[2];
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        cin >> n;

        init();

        for(int i = 0; i < n; i++) {
            cin >> input;
            turnCube(input[0], input[1]);
            printCubeTop();
        }

        printCubeTop();
    }
}