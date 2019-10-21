// leetcode 1073
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
    vector<int> arr3;
    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());
    int carry = 0;
    int base = 1;
    for (int i = 0; i < max(arr1.size(), arr2.size()) || carry != 0; i++) {
      int a1 = i < arr1.size()? arr1[i]: 0;
      int a2 = i < arr2.size()? arr2[i]: 0;
      int a3 = a1 + a2 + carry;
      carry = a3 / (-2);
      a3 %= -2;
      if (a3 < 0) carry++, a3 = -a3;
      arr3.push_back(a3);
    }
    while (arr3.size() > 1 && arr3.back() == 0) arr3.pop_back();
    reverse(arr3.begin(), arr3.end());
    return arr3;
  }
};

int main() {
    Solution  s;
    vector<int> arr1 = {1,1,1,1,1};
    vector<int> arr2 = {1,0,1};
    vector<int> res = s.addNegabinary(arr1, arr2);
    return 0;
}