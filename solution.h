
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol1048
{

  class Solution
  {
  private:
    bool predecessor(const string &w1, const string &w2);

  public:
    int findLongest(vector<string> &words);
  };
}
#endif