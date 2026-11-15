// *Purose of the code is to search a given pattern
#include <bits/stdc++.h>
using namespace std;
void pattern_check(string txt, string ptn)
{
  int M = txt.length();
  int N = ptn.length();
  int flag= 0;
  for (int i = 0; i < M - N + 1; i++)
  {
    int j;
    for (j = 0; j < N; j++)
    {
      if (ptn[j] != txt[j + i])
      {
        break;
      }
    }
    if(j==N){
    cout<< "Pattern match at index: "<< i<< endl;
    flag= 1;
  }
}
if(!flag)cout<<"Pattern not found"<<endl;
}
int main()
{
  string txt, ptn;
  cin>> txt>> ptn;
  pattern_check(txt, ptn);
  return 0;
}