#include <bits/stdc++.h>
using namespace std;
vector<int> LPS(string patt)
{
  int n = patt.length();

  int length = 0;
  int i = 1;
  vector<int> lps(n);
  if (n == 0)
    return lps;
  lps[0] = 0;
  while (i < n)
  {
    if (patt[i] == patt[length])
    {
      length++;
      lps[i] = length;
      i++;
    }
    else
    {
      if (length != 0)
        length = lps[length - 1];
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}
vector<int> KMP(string patt, string str)
{
  int m = patt.length();
  int n = str.length();

  vector<int> answer;
  vector<int> lps = LPS(patt);
  int i, j;
  i = j = 0;
  while (i < n)
  {
    if (patt[j] == str[i])
    {
      i++;
      j++;
    }
    if (j == m)
    {
      answer.push_back(i - j);
      j = lps[j - 1];
    }
    else if (i < n && patt[j] != str[i])
    {
      if (j != 0)
      {
        j = lps[j - 1];
      }
      else
      {
        i++;
      }
    }
  }
  return answer;
}
int main()
{
  string str, patt;
  cout << "Enter main text and pattern" << endl;
  cout << "Main text: ";
  cin >> str;
  cout << "Pattern: ";
  cin >> patt;
  if (str.empty() || patt.empty())
  {
    cout << "Input is empty";
    return 1;
  }
  vector<int> answer = KMP(patt, str);
  if (answer.empty())
    cout << "No pattern match" << endl;
  for (auto k : answer)
  {
    cout << "Pattern match at index: " << k << endl;
  }
  return 0;
}