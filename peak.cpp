/**
 * @file peak.cpp
 * VICI Holding Interview question.
 *
 * @author Xiang-Guan Deng (Danny Deng)
 * xiangguand@gmail.com
 **/

#include <deque>
#include <string>
#include <vector>
#include "peak.h"
#include <assert.h>

/*
Please write a fast program that can find the shortest continuous subsequences
with the summation which is equal or greater than specific number.
• Language: C++ 20
• Platform: Linux
• Architecture: x86-64
*/
vector<vector<int>> peak(vector<int>& nums, int k)
{
  vector<vector<int>> res;
  int n = nums.size();

  deque<int> dq;
  vector<int> presum(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    assert(nums[i - 1] >= 0);
    presum[i] = presum[i - 1] + nums[i - 1];
  }

  // O(n), find the shortest numbers
  int shortest = INT32_MAX;
  for (int i = 0; i <= n; i++)
  {
    while (!dq.empty() && ((presum[dq.front()] + k) <= presum[i]))
    {
      shortest = min(shortest, i - dq.front());
      dq.pop_front();
    }

    dq.push_back(i);
  }

  // cout << "shortest: " << shortest << endl;
  if (INT32_MAX == shortest)
    return res;

  int rolling = 0;
  for (int i = 0; i < shortest; i++)
  {
    rolling += nums[i];
  }
  if (rolling >= k)
  {
    res.push_back(vector<int>(nums.begin(), nums.begin() + shortest));
  }

  for (int i = shortest; i < n; i++)
  {
    rolling -= nums[i - shortest];
    rolling += nums[i];
    if (rolling >= k)
    {
      res.push_back(vector<int>(nums.begin() + (i - shortest + 1), nums.begin() + i + 1));
    }
  }

  return res;
}
