#include <bits/stdc++.h>
using namespace std;
vector<int> LPS(string patt)
{
  int n = patt.length(); //* length of "Pattern"

  int length = 0;
  int i = 1;

  vector<int> lps(n); //* Initialize "lps" vector

  //! if pattern size is zero then return the "lps" vector
  if (n == 0)
    return lps;
  //! ------------

  lps[0] = 0; // Todo: Set first element of "lps" vector to zero

  //* Loop will continued until "size of text" and index of "i" are same
  while (i < n)
  {
    if (patt[i] == patt[length]) // Todo: Check character from "text" and "pattern"
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
  return lps; // todo: Return whole "lps" vector
}
vector<int> KMP(string patt, string str) //* take "Pattern" & "Main Text" as argument
{
  int m = patt.length(); //* length of "Pattern"
  int n = str.length();  //* lenght of "Main text"

  vector<int> answer;          // todo: declare "answer" vector for storing final answer
  vector<int> lps = LPS(patt); // todo: declare "lps" vector for storing lps value

  int i, j; // todo: Initialize i and j as index count
  i = j = 0;
  while (i < n) //* loop exicutes untill "index" and "main text" length
  {
    if (patt[j] == str[i])
    {
      i++;
      j++;
    }
    if (j == m)
    {
      answer.push_back(i - j); // todo: Push pattern matching index to "answer" vector
      j = lps[j - 1];          // todo: Set "j" index with lps[j-1] element
    }
    else if (i < n && patt[j] != str[i])
    {
      if (j != 0)
      {
        j = lps[j - 1]; // todo: Set "j" index with lps[j-1] element
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
  if (str.empty() || patt.empty()) // todo: Check wether inputs are empty or not
  {
    cout << "Input is empty";
    return 1;
  }
  //* Declare "answer" vector for storing "matching index" 
  vector<int> answer = KMP(patt, str); //* use KMP function for getting "matching index"
  //todo: Check wether "answer" vector is empty (no matching index found)
  if (answer.empty())
    cout << "No pattern match" << endl;
  else
  {
    for (auto k : answer)
    {
      cout << "Pattern match at index: " << k << "\n";
    }
  }
  return 0;
}