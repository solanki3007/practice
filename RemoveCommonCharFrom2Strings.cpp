#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string concatS1S2(string s1, string s2) {
    
   string result="";
 
   // Creat a map for the string 1
   unordered_map <char, int> m;
   
   // populate the map with string S2 and set value as 1 for all elements
   int i;
   for (i=0; i<s2.size(); i++){
       m[s2[i]] = 1;
     
   }
   
   // Serach S1 char one by one in map
   int j;
   for (j=0; j<s1.size(); j++){
      if(m.find(s1[j]) == m.end()){
         result += s1[j];
         //cout << result << endl;
      }
      else
         m[s1[j]] = 2; // or we can remove this from map
   }
   
   // Now skip the common from second string
    for (j=0; j<s2.size(); j++){
      if(m[s2[j]] == 1){
         result += s2[j];
         //cout << result << endl;
      }
     }
     
   if(result.size()==0)
      result += "-1";
   return result;
}

int main() {
	//code
	string s1="aabcdpttbc";
	string s2="tbcpabd";
	
	string s3 = concatS1S2(s1,s2);
	cout << s3 << endl;
	
	s1="aacdb";
	s2="gafd";
	
	s3 = concatS1S2(s1,s2);
	cout << s3 << endl;

	s1="abcs";
	s2="cxzca";
	
	s3 = concatS1S2(s1,s2);
	cout << s3 << endl;
	
	return 0;
}