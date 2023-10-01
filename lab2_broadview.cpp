#include <iostream>
#include <fstream>
using namespace std;

void print(const string& myText)

{
   // cout << "Arithmetic operators: ";
    for (char c : myText) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            cout <<"operators: "<< c << " ";
        }
        /*else if (c >= 'A' && c<= 'Z')
        {
            cout<<"Variables :"<<c<<" "<<endl;
        }*/
        else if (c >= 'a' && c<= 'z')
        {
            cout<<"Variables :"<<c<<" ";
        }
        /*else
        {
            cout<<"Invalid Operator Existing "<<endl;
        }*/
    }
    cout << endl;
}
int main()
{
    string myText;
    ifstream MyReadFile("lab2.txt");
    while (getline (MyReadFile, myText)) {

  cout << myText<<endl;
}
 print(myText);


return 0;
}
