#include<iostream>
using namespace std;

int main()
{
string input;
cin>>input;
if (input>="A" && input<="Z")
{
    cout<<"Not Numeric";
}
 else if(input>="a" && input<="z")
{
    cout<<"Not numeric";
}
 else if(input>="*" && input>="+" && input>="-" && input>="/" && input>="%" && input>= "$" && input>= "#")
{
    cout << "Not Numeric";
}
else{
    cout<<"Numeric";
}

}
