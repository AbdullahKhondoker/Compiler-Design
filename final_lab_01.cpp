#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
int a = 0;// add
int c = 0;// sub
int h = 0;//func add
int f2 = 0; // func sub

bool isSeparator(char ch)
{
    string value = " ,;(){}[]";
    for(int i=0; i<value.length(); i++)
        if(ch==value[i])
        return true;
    return false;
}

bool isOperator(char ch)
{
    string value = "+-*/<>=!";
    for(int i=0; i<value.length(); i++)
        if(ch==value[i])
        return true;
    return false;
}
bool isKeyword(string s)
{
    string keyword[] = {"auto","break","case","char","const","continue","default",
                        "do","double","else","enum","extern","float","for","if",
                        "int","long","register","return","short","signed","sizeof",
                        "static","struct","switch","case","typeof","union","unsigned",
                        "void","while"};
    for(int i=0; i<(sizeof(keyword)/sizeof(string)); i++)
        if(s==keyword[i])
           return true;

    return false;

}
bool isIdentifier(string s)
{
    bool valid = true;

    if(isKeyword(s))
        valid = false;

    if(isKeyword(s))
        valid = false;

    if(valid)
        if((s[0] >= '0')&&(s[0] <= '9'))
            valid = false ;
    if (valid)
        for(int i =0 ; i<s.length(); i++)
          if(((s[i]>='a')&&(s[i]<='z'))||((s[i]>='A')&&(s[i]<='Z'))||((s[i]>='0')&&(s[i]<='9'))||(s[i]== '_'))
               continue;


    else
    {
        valid = false;
        break;
    }
 return valid;
}

bool isNumber(string s)
{
    bool valid = true;
    for(int i=0;i<s.length() ; i++)
        if((s[i]>='0')&&(s[i]<='9')||(s[i]=='.'))
             continue;
    else
    {
        valid = false;
        break;
    }
    return valid;
}

void parse (string s)
{
    vector <string> tokens;
    string token = "";

    for(int i=0; i<s.length(); i++)
    {
        if(isSeparator(s[i]))
        {
            if(token!="")
            {
                //token.push_back(s[i]);
                tokens.push_back(token);

            }
            token = "";


        }
    else if (isOperator(s[i]))
    {
        if (token!= "")
        {
            tokens.push_back(token);
            token = "";
        }
        token.push_back(s[i]);
        tokens.push_back(token);
        token = "";

    }
    else
        token.push_back(s[i]);
    }
    if(token != "")
    {
        tokens.push_back(token);
        token = "";
    }


    for(int i=0; i<tokens.size(); i++)
    {
        if(isKeyword(tokens[i]))
            cout<<"";
            //cout<<'\"'<<tokens[i]<<"\" is a keyword"<<endl;
        else if (isOperator(tokens[i][0]))
        {
            //cout<<'\"'<<tokens[i]<<"\" is a Operator"<<endl;



            if (tokens[i] == "+")
            {   a++;
                cout<<'\"'<<"Operation Addition"<<endl;}

            else if (tokens[i] == "-")
            {
                c++;
                cout<<'\"'<<"Operation Subtraction"<<endl;
            }
                else if (tokens[i] == "*")
                cout<<'\"'<<"Operation Multiplication"<<endl;
                else if (tokens[i] == "=")
                cout<<'\"'<<"Operation Assignment"<<endl;
        }
        else if(isIdentifier(tokens[i]))

        {
            //cout<<'\"'<<tokens[i]<<"\" is a Identifier"<<endl;
            if (tokens[i] == "add")
                {   h++;
                    cout<<"Function add"<<endl;}
            else if (tokens[i] == "sub")
                {   f2++;
                    cout<<"Function sub"<<endl;}

        }
        else if (isNumber(tokens[i]))
            cout<<""<<endl;
           // cout<<'\"'<<tokens[i]<<"\" is a Constant"<<endl;
        else
            cout<<""<<endl;
            //cout<<'\"'<<tokens[i]<<"\" is a Invalid Identifier"<<endl;

    }
}

int main()

{
    ifstream file;
    string line;

    file.open("program.c");
    while (file) {
        getline(file, line);
        parse(line);
    }
    file.close();
    cout<<"Addition no : "<<a<<endl;
    cout<<"Subtraction No:"<<c<<endl;
    cout<<"Function ADD count:"<<h<<endl;
    cout<<"Subtraction SUB Count:"<<f2<<endl;
    return 0;
}
