// *Purose of the code is to search a given pattern
#include <bits/stdc++.h>
using namespace std;

//* Pattern check function
void pattern_check(string txt, string ptn)
{
  int M = txt.length();
  int N = ptn.length();
  int flag= 0;
  //! (M-N+1) should be strickly maintained otherwise cause outof range
  for (int i = 0; i < M - N + 1; i++)
  {
    int j;
    //todo: loop upto length of pattern string
    for (j = 0; j < N; j++)
    {
      //todo: check character of text string and pattern string are same or not 
      if (ptn[j] != txt[j + i])
      {
        //*if condition doesn't match abandon loop
        break;
      }
    }
    //todo: check if length of pattern string and index number are equal
    //* equal when whole pattern matches
    //* not equal when portion of pattern matches or doesn't match anything
    if(j==N){
    cout<< "Pattern match at index: "<< i<< endl;
    //todo: when pattern found set flag to 1 for not to print "pattern not found" messege 
    flag= 1;
  }
}
if(!flag)cout<<"Pattern not found"<<endl;
}
int main()
{
  string txt, ptn;
  //todo: take input from users in two string variable
  cin>> txt>> ptn;
  //todo: call function
  pattern_check(txt, ptn);
  return 0;
}