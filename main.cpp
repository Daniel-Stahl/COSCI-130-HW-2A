// Daniel Stahl
// COSCI 130
// Homework 2A

#include <string>
#include <iostream>
#include <cmath>

using namespace std;

string add(string a, string b, int & flags);

int main() {
    int num = 0;
    
    cout << add("1001", "1011", num) << endl;
}

string add(string a, string b, int & flags) {
    int signedNumA = 0;
    int signedNumB = 0;
    int N = 0;
    int Z = 0;
    int C = 0;
    int V = 0;
    int val = 0;
    string total = "0000";
    int totalNum = 0;
    string flagNum;
    
    // check for carry over
    for (int x = 3; x >= 0; x--) {
        int num = a[x] - '0' + b[x] - '0';
        num += C;
        
        if (num == 1) {
            C = 0;
            total[x] = '1';
            
        } else if(num == 2) {
            C = 1;
            total[x] = '0';
            
        } else if(num == 3) {
            C = 1;
            total[x] = '1';
        } else {
            C = 0;
        }
    }
    
    // Get signed nums
    for (int x = 3; x >= 1; x--) {
        if (a[x] == '1') {
            signedNumA += static_cast<int>(pow(2, val));
        }

        if (b[x] == '1') {
            signedNumB += static_cast<int>(pow(2, val));
        }

        if (total[x] == '1') {
            totalNum += static_cast<int>(pow(2, val));
        }
        
        val++;
    }
    
    // Checking for negative
    if (total[0] == '1') {
        totalNum = totalNum - pow(2, 3);
        N = 1;
    }
    
    if (a[0] == '1') {
        signedNumA = signedNumA - pow(2, 3);
    }
    
    if (b[0] == '1') {
        signedNumB = signedNumB - pow(2, 3);
    }

    // check signed nums for over flow
    if (signedNumA + signedNumB == totalNum) {
        V = 0;
    } else {
        V = 1;
    }
    
    if (total == "0000") {
        Z = 1;
    }
    
    flagNum = to_string(N) + to_string(Z) + to_string(V) + to_string(C);
    val = 0;
    for (int x = 3; x >= 1; x--) {
        if (flagNum[x] == '1') {
            flags += static_cast<int>(pow(2, val));
        }
        
        val++;
    }
    
    if (flagNum[0] == '1') {
        flags = flags - pow(2, 3);
    }
    
    return to_string(flags);
}
