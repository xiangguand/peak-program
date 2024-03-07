/**
 * @file peak.cpp
 * VICI Holding Interview, only for peak program test file.
 *
 * @author Xiang-Guan Deng (Danny Deng)
 * xiangguand@gmail.com
 **/


#include "../peak.h"
#include <iostream>
#include <random>
#include <assert.h>

/* Contrain */
#define RANDOM_PATTERN_MIN (0)
#define RANDOM_PATTERN_MAX (1000)

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& arr)
{
  for (auto v : arr)
  {
    os << v << " ";
  }
  os << endl;
  return os;
}

ostream& operator<<(ostream& os, const vector<vector<int>>& arr)
{
  for (size_t i = 0; i < arr.size(); i++)
  {
    for (size_t j = 0; j < arr[i].size(); j++)
    {
      os << arr[i][j] << " ";
    }
    os << endl;
  }
  return os;
}

bool operator==(const vector<vector<int>> arr1, const vector<vector<int>> arr2)
{
  size_t m = arr1.size();
  if (arr2.size() != m)
    return false;
  for (size_t i = 0; i < m; i++)
  {
    if (arr1[i].size() != arr2[i].size())
      return false;
    for (size_t j = 0; j < arr1[i].size(); j++)
    {
      if (arr1[i][j] != arr2[i][j])
      {
        return false;
      }
    }
  }
  return true;
}

bool operator!=(const vector<vector<int>> arr1, const vector<vector<int>> arr2)
{
  return !(arr1 == arr2);
}

vector<vector<int>> bruceForcePeak(vector<int>& nums, int k)
{
  vector<vector<int>> res;
  int n = nums.size();

  vector<int> presum(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    assert(nums[i - 1] >= 0);
    presum[i] = presum[i - 1] + nums[i - 1];
  }

  vector<vector<int>> temp;
  int shortest = INT32_MAX;
  for (int i = 0; i <= n - 1; i++)
  {
    for (int j = i + 1; j <= n; j++)
    {
      if (presum[j] - presum[i] >= k)
      {
        temp.push_back(vector<int>(nums.begin() + i, nums.begin() + j));
        shortest = min(shortest, j - i);
      }
    }
  }

  if(INT32_MAX == shortest) {
    return res;
  }

  for (size_t i = 0; i < temp.size(); i++)
  {
    if (temp[i].size() == (size_t)shortest)
    {
      res.push_back(temp[i]);
    }
  }

  return res;
}
void Dassert(bool cmpLogic, string funcName, size_t number)
{
  cout << "Test case [" << funcName << "] ";
  if (cmpLogic)
  {
    cout << "PASS";
  }
  else
  {
    cout << "Fail at line " << number;
  }
  cout << endl;
}

/* Start defining test cases */
void test_pass()
{
  Dassert(1, __func__, __LINE__);
}

void test_fail()
{
  Dassert(0, __func__, __LINE__);
}

#define DASSERT(result) Dassert((result), __func__, __LINE__)

#define DASSERT_2DARR_EQ(arr1, arr2)                                                                                   \
  do                                                                                                                   \
  {                                                                                                                    \
    bool cmpLogic = (arr1) == (arr2);                                                                                  \
    DASSERT(cmpLogic);                                                                                                 \
    if (!(cmpLogic))                                                                                                   \
    {                                                                                                                  \
      cout << "Expect: \n" << (arr1) << "Real: \n" << (arr2) << endl;                                                  \
    }                                                                                                                  \
  } while (0)

int test_vector_operator_pass()
{
  vector<vector<int>> expect{ { 17, 42, 1, 26 }, { 26, 8, 0, 63 } };
  vector<vector<int>> dut{ { 17, 42, 1, 26 }, { 26, 8, 0, 63 } };
  if (expect != dut)
  {
    DASSERT(0);
    cout << "Expect: \n" << expect << "Real: \n" << dut << endl;
    return -1;
  }
  return 0;
}

int test_vector_operator_fail()
{
  vector<vector<int>> expect{ { 17, 42, 1, 26 }, { 26, 8, 0, 63 } };
  vector<vector<int>> dut{ { 17, 42, 1, 26 }, { 26, 2, 0 } };
  if (expect != dut)
  {
    DASSERT(0);
    cout << "Expect: \n" << expect << "Real: \n" << dut << endl;
    return -1;
  }
  return 0;
}

int test_peak_80()
{
  vector<int> testPattern{ 3, 17, 42, 1, 26, 8, 0, 63 };
  vector<vector<int>> expect{ { 17, 42, 1, 26 }, { 26, 8, 0, 63 } };
  vector<vector<int>> dut = peak(testPattern, 80);
  if (expect != dut)
  {
    DASSERT(0);
    cout << "Expect: \n" << expect << "Real: \n" << dut << endl;
    return -1;
  }
  return 0;
}
int test_peak_90()
{
  vector<int> testPattern{ 3, 17, 42, 1, 26, 8, 0, 63 };
  vector<vector<int>> expect{ { 26, 8, 0, 63 } };
  vector<vector<int>> dut = peak(testPattern, 90);
  if (expect != dut)
  {
    DASSERT(0);
    cout << "Expect: \n" << expect << "Real: \n" << dut << endl;
    return -1;
  }
  return 0;
}
int test_peak_64()
{
  vector<int> testPattern{ 3, 17, 42, 1, 26, 8, 0, 63 };
  vector<vector<int>> expect{ { 42, 1, 26 }, { 8, 0, 63 } };
  vector<vector<int>> dut = peak(testPattern, 64);
  if (expect != dut)
  {
    DASSERT(0);
    cout << "Expect: \n" << expect << "Real: \n" << dut << endl;
    return -1;
  }
  return 0;
}
int test_peak_20()
{
  vector<int> testPattern{ 3, 17, 42, 1, 26, 8, 0, 63 };
  vector<vector<int>> expect{ { 42 }, { 26 }, { 63 } };
  vector<vector<int>> dut = peak(testPattern, 20);
  if (expect != dut)
  {
    DASSERT(0);
    cout << "Expect: \n" << expect << "Real: \n" << dut << endl;
    return -1;
  }
  return 0;
}
int test_peak_0()
{
  vector<int> testPattern{ 3, 17, 42, 1, 26, 8, 0, 63 };
  vector<vector<int>> expect{ { 3 }, { 17 }, { 42 }, { 1 }, { 26 }, { 8 }, { 0 }, { 63 } };
  vector<vector<int>> dut = peak(testPattern, 0);
  if (expect != dut)
  {
    DASSERT(0);
    cout << "Expect: \n" << expect << "Real: \n" << dut << endl;
    return -1;
  }
  return 0;
}
int test_peak_11()
{
  vector<int> testPattern{ 5, 6, 7, 8, 9 };
  vector<vector<int>> expect{ { 5, 6 }, { 6, 7 }, { 7, 8 }, { 8, 9 } };
  vector<vector<int>> dut = peak(testPattern, 11);
  if (expect != dut)
  {
    DASSERT(0);
    cout << "Expect: \n" << expect << "Real: \n" << dut << endl;
    return -1;
  }
  return 0;
}
int test_peak_non()
{
  vector<int> testPattern{ 5, 6, 7, 8, 9 };
  vector<vector<int>> expect;
  vector<vector<int>> dut = peak(testPattern, 999);
  if (expect != dut)
  {
    DASSERT(0);
    cout << "Expect: \n" << expect << "Real: \n" << dut << endl;
    return -1;
  }
  return 0;
}
int test_peak_full()
{
  vector<int> testPattern{ 5, 6, 7, 8, 9 };
  vector<vector<int>> expect{ { 5, 6, 7, 8, 9 } };
  vector<vector<int>> dut = peak(testPattern, 35);
  if (expect != dut)
  {
    DASSERT(0);
    cout << "Expect: \n" << expect << "Real: \n" << dut << endl;
    return -1;
  }
  return 0;
}
int test_random_generate_pattern20_peak_should_match_bruceforcepeak()
{
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> distribution(RANDOM_PATTERN_MIN, RANDOM_PATTERN_MAX);
  for (int count = 0; count < 10000; count++)
  {
    vector<int> testPattern(20, 0);
    for (int j = 0; j < 20; j++)
    {
      testPattern[j] = distribution(gen);
    }
    int k = distribution(gen);
    vector<vector<int>> expect = bruceForcePeak(testPattern, k);
    vector<vector<int>> dut = peak(testPattern, k);
    if (expect != dut)
    {
      DASSERT(0);
      cout << "Expect: \n" << expect << "Real: \n" << dut << endl;
      return -1;
    }
  }

  return 0;
}

int test_random_generate_pattern2000_peak_should_match_bruceforcepeak()
{
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> distribution(RANDOM_PATTERN_MIN, RANDOM_PATTERN_MAX);
  for (int count = 0; count < 5; count++)
  {
    vector<int> testPattern(2000, 0);
    for (int j = 0; j < 2000; j++)
    {
      testPattern[j] = distribution(gen);
    }
    int k = distribution(gen);
    vector<vector<int>> expect = bruceForcePeak(testPattern, k);
    vector<vector<int>> dut = peak(testPattern, k);
    if (expect != dut)
    {
      DASSERT(0);
      cout << "Expect: \n" << expect << "Real: \n" << dut << endl;
      return -1;
    }
  }

  return 0;
}

int test_random_generate_pattern2000000_peak_should_have_answer_not_check()
{
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> distribution(RANDOM_PATTERN_MIN, RANDOM_PATTERN_MAX);
  vector<int> testPattern(2000000, 0);
  for (int j = 0; j < 2000000; j++)
  {
    testPattern[j] = distribution(gen);
  }
  int k = distribution(gen);
  /* Bruce force cannot handle million numbers of data */
  // vector<vector<int>> expect = bruceForcePeak(testPattern, k);
  vector<vector<int>> dut = peak(testPattern, k);

  return 0;
}

int g_count = 0;
int g_ok = 0;
int TEST_FUNC(int (*func)())
{
  g_count++;
  if (func() != 0)
    return -1;
  g_ok++;
  return 0;
}

int main()
{
  cout << "Start performing tests" << endl;

  // test_pass();
  // test_fail();
  // test_vector_operator_pass();
  // test_vector_operator_fail();
  g_count = 0;
  int fg = 0;
  fg |= TEST_FUNC(test_peak_80);
  fg |= TEST_FUNC(test_peak_90);
  fg |= TEST_FUNC(test_peak_64);
  fg |= TEST_FUNC(test_peak_20);
  fg |= TEST_FUNC(test_peak_0);
  fg |= TEST_FUNC(test_peak_11);
  fg |= TEST_FUNC(test_peak_non);
  fg |= TEST_FUNC(test_peak_full);

  fg |= TEST_FUNC(test_random_generate_pattern20_peak_should_match_bruceforcepeak);
  fg |= TEST_FUNC(test_random_generate_pattern2000_peak_should_match_bruceforcepeak);
  fg |= TEST_FUNC(test_random_generate_pattern2000000_peak_should_have_answer_not_check);

  cout << "End test" << endl;
  cout << "Execute " << g_count << " test cases, "
       << "PASS " << g_ok << endl;

  if (fg)
  {
    cout << "===== FAIL =====\n" << endl;
  }
  else
  {
    cout << "===== PASS =====\n" << endl;
  }

  return fg;
}
