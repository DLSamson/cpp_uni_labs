#include <iostream>
#include <sstream>
#include <string> 
using namespace std;
 
int main()
{
    string s;
    cin >> s;
    
    int n=s.size();
 
    ostringstream s1;         
    s1<<n;
    s+=s1.str();
 
    cout <<s<<"\n";
return 0;
}