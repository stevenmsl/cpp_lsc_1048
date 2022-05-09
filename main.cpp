#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1048;

/*
Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
*/

tuple<vector<string>, int>
testFixture1()
{
  auto words = vector<string>{"a", "b", "ba", "bca", "bda", "bdca"};
  return make_tuple(words, 4);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.findLongest(get<0>(f)) << endl;
}

main()
{
  test1();
  return 0;
}