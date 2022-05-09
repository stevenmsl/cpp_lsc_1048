#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <bitset>
using namespace sol1048;
using namespace std;

/*takeways
  - use DP
  - example ["a","b","ba","bca","bda","bdca"]
    - sort the words by their size
    - look at "bdca"
      - dp[5] = 1, as "bdca" by itself can be a chain
      - dp[5] = dp[4] + 1 as "bda" is a predecessor of "bdca"
        - extend the chain by 1
      - dp[5] = dp[3] + 1 as "bca" is a predecessor of "bdca"
        - extend the chain by 1
      - so dp[5] = max(1,dp[4]+1, dp[3], +1)
    - dp[i] is defined as the length of the longest chain
      up to word[i]

*/

int Solution::findLongest(vector<string> &words)
{
  /* a word itself can be a chain so
     we start the result with 1
  */
  int n = words.size(), result = 1;
  /* sort by the length of the word */
  sort(begin(words), end(words), [](string &a, string &b)
       { return a.size() < b.size(); });

  auto dp = vector<int>(n, 1);

  for (auto i = 1; i < n; i++)
  {
    int w2Size = words[i].size();
    /* check everyone before me
       - start from larger size
         as we can only extend
         the chains with one word
         shorter in length
    */
    for (auto j = i - 1; j >= 0; j--)
    {
      int w1Size = words[j].size();
      /* the gap is to big
         - there will be predecessors for words[i] */
      if (w1Size + 1 < w2Size)
        break;
      /* same size; my peer */
      if (w1Size == w2Size)
        continue;
      if (predecessor(words[j], words[i]))
      {
        dp[i] = max(dp[i], dp[j] + 1);
        /* update the global max */
        result = max(result, dp[i]);
      }
    }
  }

  return result;
}

/* assume w2 is longer than w1 */
bool Solution::predecessor(const string &w1, const string &w2)
{
  /* w1 can only have one char different from w2
     - edit distance is one
   */
  int i = 0, m = w1.size(), n = w2.size();

  for (auto j = 0; j < n; j++)
    if (w2[j] == w1[i])
      /* find a match
         - advance the index on the predecessor by one
      */
      i++;

  /* you should be able to exhaust w1 using the chars in w2 */
  return i == m;
}
