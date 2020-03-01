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
    
    cout << add("1111", "1111", num);
}

string add(string a, string b, int & flags) {
    string ret;
    int signedNumA = 0;
    int signedNumB = 0;
    int N = 0;
    int Z = 0;
    int C = 0;
    int V = 0;
    int val = 0;
    string total = "0000";
    int totalNum = 0;
    
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
    
    if (total[0] == '1') {
        totalNum = totalNum - pow(2, 3);
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

    cout << "Total: " << total << endl;

    if (C == 1) {
        cout << "Carry over = 1" << endl;
    }

    

    cout << signedNumA << endl;
    cout << signedNumB << endl;
    cout << totalNum << endl;
    cout << total << endl;
    
   
    
    
    return to_string(V) + to_string(C);
}

/*

 Write a function with the following prototype:
 string add(string a, string b, int & flags);
 
 On entry:
 Awc  (Assume  without  checking)  each  string  param  has  size  exactly  4,  and  each  of  the  4  chars  in both strings is either '0' or '1' (e.g. "0110", "1010").Awc flags is UG (unpredictable garbage) on entry. One of add's jobs is to set this reference arg.add may not assume that flags has been initialized to something sensible on entry.
 
 add does no i/o (input/ouptut).
 
 add's job is to return the string corresponding to the 4-bit sum of a and b, and to set flags so that the  high-order  28  bits  are  0  and  the  the  low-order  4  bits  are  the  values  for  N,  Z,  V,  and  C, respectively:
 
 bit #28: N
 bit #29: Z
 bit #30: V
 bit #31: C
 
 For example, if a were "0110" and b were "1010":
 
  0110
 +1010
  0000
 N: 0, because the answer we got wasn't negative
 Z: 1, because the answer we got was 0
 V: 0, because with signed (2’s complement) interpretation, 6 + -6 == 0 isn’t wrong, and
 C: 1, because with unsigned interpretation, 6 + 10 == 0 is wrong
 
 So, the returned string is "0000" (the most significant bit being represented by the first char in the string), and flags is set to 5, because 5 in binary is
 
                                   NZVC
 00000000  00000000  00000000  00000101
 
 Write a main function that calls your add function. You decide the details of your main.
 
*/
