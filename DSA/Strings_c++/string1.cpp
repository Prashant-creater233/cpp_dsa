#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

// caharacter strings

// int main(){
//     // char str[]={'a','b','c','\0'};
//     // cout << str << endl; //constant pointer
//     // cout << strlen(str) << endl; // length 3 hi ayegi null character ki length add nhi hogi

//     char str[]= "college";

//     cout << str[2] << endl;

//     return 0;
// }

// int main(){
//     char str[15];

//     cout << "enter char array: ";
//     // cin >> str;
//     cin.getline(str, 15); // space ke bad bhi value dega ignore nhi  kraga
//     // cin.getline(str, 100, '$'); // $ lgana ke baad sara ignore kraga

//     // cout << "output : " << str << endl;
//     for(char ch : str){
//         cout << ch << "";
//     }
//     cout << endl;
//     return 0;
// }

// int main(){
//     char str[]="prashant kanwal";
//     int len = 0;

//     for(int i=0; i<str[i] != '\0'; i++){
//         len++;
//     }

//     cout << "length of string: " << len << endl;

//     return 0;
// }

// strings

// int main(){
//     string str = "prashant kanwal";
//     cout << str << endl;

//     str = "hello";
//     cout << str << endl;
//     return 0;
// }

// int main(){
//     string str1 = "prashant";
//     string str2 = "kanwal";

//     string str3 = str1 + str2; // concatenation
//     cout << str3 << endl;

//     cout << (str1 == str2) << endl;
//     cout << (str1 < str2) << endl; // check alphabeticall (lexicographically distionary wise) acc to first character of string
//     cout << (str1 > str2) << endl; // check alphabeticall acc to first character of string
//     cout << str1.length() << endl;

//     return 0;
// }

// int main(){
//     string str;

//     // cin >> str; // same stop get input after space

//     getline(cin, str);

//     cout << "output : " << str << endl;
//     return 0;
// }

// int main(){
//     string str="prashant kanwal";

//     // for(int i=0; i<str.length(); i++){
//     //     cout << str[i] << " ";
//     // }

//     for(char ch : str){  // for each loop
//         cout << ch << " ";
//     }
//     cout << endl;
//     return 0;
// }

// reverse of cahracter array

// int main(){
//     string str = "prashant kanwal";

//     reverse(str.begin(), str.end()); //iterators
//     cout << str << endl;
//     return 0;
// }


// Find if string is palindrome or not

// bool isPalindrome(string str){
//     int st=0, end=str.size()-1;

//     while(st < end) {
//         if(str[st] == str[end]){
//             st++;
//             end--;
//         } else {
//             return false;
//         }
//     }
//     return true;
// }

// int main(){
//     string str = "racecar";

//     cout << isPalindrome(str);

//     return 0;
// }


// exact code 
class Solution {
public:
    bool isAlphaNum(char ch) {
        if((ch >= '0' && ch <= '9') || 
        (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int st=0, end= s.length()-1;

        while(st < end){
            if(!isAlphaNum(s[st])) {
                st++; continue;
            }
            if(!isAlphaNum(s[end])) {
                end--; continue;
            }
            
            if(tolower(s[st]) != tolower(s[end])){
                return false;
            }

            st++; end--;
        }
        return true;
    }
};