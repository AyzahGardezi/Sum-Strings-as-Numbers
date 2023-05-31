#include <string>
using namespace std;

std::string sum_strings(const std::string& a, const std::string& b) {
  int lengtha = a.length();
  int lengthb = b.length();
  int lengths = std::max(lengtha, lengthb) + 1;
  int *s = new int[lengths];
  int ia = lengtha - 1;
  int ib = lengthb - 1;
  int is = lengths - 1;
  int carry = 0;
  
  cout << "a:" << a << " b: " << b;
  
  for (; ia >= 0 && ib >=0; ia--, ib--, is--)
    {
    int aval = a[ia] - '0';
    int bval = b[ib] - '0';
    int sum = aval + bval + carry;
    s[is] = sum%10;
    if (sum > 9)
      carry = 1;
    else
      carry = 0;
  }
  
  if (lengtha > lengthb)
    while (ia >= 0)
      {
      int aval = a[ia--] - '0';
      int sum = aval + carry;
      carry = (sum > 9) ? 1 : 0;
      s[is--] = sum%10;
    }
  else
    while (ib >= 0)
      {
      int bval = b[ib--] - '0';
      int sum = bval + carry;
      carry = (sum > 9) ? 1 : 0;
      s[is--] = sum%10;
    }
  
  string result = "";
  
  if (carry == 1)
    {
    s[0] = 1;
    for (int i = 0; i < lengths; i++)
      result += to_string(s[i]);
  return result;
  }
  
  for (int i = 1; i < lengths; i++)
      result += to_string(s[i]);
  
  cout << " result: " << result;
  
  return result;
}
