#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<stack>

using namespace std;

int eval=0;
int fval=0;
int tval=0;
int j=0;

int main()
{
string str;
cout<<"Enter the string  ";
cin>>str;

stack<char>st;
st.push('0');

int l=str.length();
int count=0;
int m;
int arr[100];


for( m=0;m<l;m++)
{   char v;
    if(str.at(m)=='j')
        count++;
}

cout<<"Enter values :";
for( m=0;m<count;m++)
{   cin>>arr[m];
}

char ch1,ch2,temp;
int i=0,k=0;
int flag=1;


cout<<"String is  "<<str<<endl;

int count1=0;

while(flag)
{
    ch1=str.at(i);
    ch2=st.top();
    int x=arr[k];
for( m=0;m<l;m++)
{   char v;
    if(str.at(m)=='j')
        count++;
}
    switch(ch2)
    {
        case '0': if(ch1=='+'||ch1=='*'||ch1=='$')
                   {
                    cout<<"Rejected";
                    flag=0;
                   }

                  else if(ch1=='j')
                   {
                    st.push('j');
                    st.push('4');
                    j=x;
                    k++;
                    i++;
                   }

        break;

case '1':       if(ch1=='*'||ch1=='j')
                  {
                     cout<<"Rejected";
                     flag=0;
                  }
                else if(ch1=='+')
                  {
                     st.push('+');
                     st.push('6');
                     i++;
                  }
                else if(ch1=='$')
                  {
                     st.push('$');
                     st.push('5');
                     i++;
                  }

                break;

case '2':
                 if(ch1=='j')
                     {
                      cout<<"Rejected";
                      flag=0;
                     }

                  else if(ch1=='*')
                  {
                      st.push('*');
                      st.push('7');
                      i++;

                  }
                 else if(ch1=='+' || ch1=='$')
                    {
                      st.pop();
                      st.pop();
                      temp=st.top();
                      st.push('E');
                      if(temp=='0')
                         st.push('1');
                      eval=tval;

                     }
                 break;

case '3': if(ch1=='j')
             {
                 cout<<"Rejected";
                 flag=0;
             }
             else if(ch1=='+'||ch1=='*'||ch1=='$')
             {
                st.pop();
                st.pop();
                temp=st.top();
                st.push('T');
                if(temp=='0')
                  st.push('2');
                else if(temp=='6')
                  st.push('8');
                tval=fval;


             }


           break;

case '4' :
             if(ch1=='j')
                   {
                    cout<<"Rejected";
                    flag=0;
                   }
             else
                {
                st.pop();
                st.pop();
                temp=st.top();
                st.push('F');
                if(temp=='0'|| temp=='6')
                  st.push('3');
                else if(temp=='7')
                  st.push('9');

                fval=j;
                }
             break;

case '5':  if(ch1=='+'||ch1=='*'||ch1=='j')
               {
                cout<<"Rejected";
                flag=0;

               }
            else if(ch1=='$')
                {
                cout<<"Accepted"<<endl;
                cout<<eval;
                flag=0;

                }

           break;

case '6':
             if(ch1=='+'||ch1=='*'||ch1=='$')
               {
                 cout<<"Rejected";
                 flag=0;

               }
             else if(ch1=='j')
               {
                st.push('j');
                st.push('4');
                j=x;
                k++;
                i++;
               }
               break;



case '7':
             if(ch1=='+'||ch1=='*'||ch1=='$')
               {
                 cout<<"Rejected";
                 flag=0;

               }
             else if(ch1=='j')
               {
                st.push('j');
                st.push('4');
                j=x;
                k++;
                i++;
               }


          break;

case '8' :
          if(ch1=='j')
            {
              cout<<"Rejected";
              flag=0;

            }
         else if(ch1=='*')
                {
                st.push('*');
                st.push('7');
                i++;
                }
         else if(ch1=='+' || ch1=='$')
                {
                st.pop();st.pop();st.pop();st.pop();st.pop();st.pop();
                temp=st.top();
                st.push('E');
                if(temp=='0')
                  st.push('1');

                 eval=eval+tval;

                }

       break;

case '9':
          if(ch1=='j')
             {for( m=0;m<l;m++)
{   char v;
    if(str.at(m)=='j')
        count++;
}
              cout<<"Rejected";
              flag=0;

             }
           else if(ch1=='+' || ch1=='*' || ch1=='$')
                {
                st.pop();st.pop();st.pop();st.pop();st.pop();st.pop();
                temp=st.top();
                st.push('T');
                if(temp=='0')
                  st.push('2');
                else if(temp=='6')
                    st.push('8');

                tval=tval*fval;
                }


           break;




    }
}

return 0;
}
