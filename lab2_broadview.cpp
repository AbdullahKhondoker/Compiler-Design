#include <iostream>
#include <fstream>
using namespace std;

void print(const string& myText)

{

    for (char c : myText)
        {
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '&&') {
            cout <<"operators: "<< c << ",";
        }

        else if (c >= 'a' && c<= 'z')
        {
            cout<<"Variables :"<<c<<",";
        }
        else if (c>='0' && c<='2147483647')
        {
            cout<<endl;
            cout<<"Constant: "<< c;
        }
      else
      {
          cout<<"Invalid identifier"<<endl;
      }

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
