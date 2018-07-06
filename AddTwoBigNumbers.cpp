#include <iostream>

using namespace std;

int sumOf2Str(string s1, string s2)
{
    cout << s1 << endl;
    cout << s2 << endl;
    
    string sum="";
    int len1 = s1.length();
    int len2 = s2.length();
    int carry = 0;
    int i;
    for (i=0; i<s1.length() && i<s2.length(); i++)
    {
        cout << s1[len1-1] << " and " << s2[len2-1] << endl;
        int add = (s1[len1-1]-'0')+(s2[len2-1]-'0') + carry;
     
        sum = sum + std::to_string(add%10); // in C++11
        cout << "Sum: " << sum << endl;
        carry = add/10;
        len1--;
        len2--;
        cout << "carry: "<< carry << endl;
        cout << "len1 :" << len1 << endl;
        cout << "len2 :" << len2 << endl;
    
    }
    
    if(len2 > 0){
        int add = (s2[len2-1]-'0') + carry;
        cout << add << endl;
        sum = sum + std::to_string(add%10); // in C++11
        cout << sum << endl;
        len2--;
        while(s2.length()>++i){
            sum = sum + s2[len2--];
            cout << "Sum: " << sum << endl;
        }
    }
    
    if(len1 > 0){
        int add = (s2[len1-1]-'0') + carry;
        cout << add << endl;
        sum = sum + std::to_string(add%10); // in C++11
        cout << sum << endl;
        len1--;
        while(s1.length()>++i){
            sum = sum + s1[len1--];
            cout << "Sum: " << sum << endl;
        }
    }
    
    // Now reverse the sum
    
    
    cout << "Sum: " << sum << endl;
}

int main()
{
    string s1="8324";
    string s2="983574";
    
    sumOf2Str(s1,s2);
    
    return 0;
}