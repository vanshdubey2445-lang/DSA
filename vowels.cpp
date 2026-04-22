#include<iostream>
using namespace std;

int main()
{
    char c;
    cout<<"Enter the character: "<<endl;
    cin>>c;
    
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    cout<<"Yes, it is a vowel"<<endl;
    else if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
    cout<<"Yes it is a vowel"<<endl;
    else
    cout<<"No it is a consonent"<<endl;
}