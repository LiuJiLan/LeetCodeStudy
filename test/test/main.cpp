//
//  main.cpp
//  test
//
//  Created by 刘冬辰 on 2021/1/26.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable = unordered_map<int, int>();
        vector<int> ans = vector<int>();
        
        for (int i = 0; i < nums.size(); i++) {
            if (hashTable.count(target - nums[i]) != 0) {
                ans.push_back(hashTable.at(target - nums[i]));
                ans.push_back(i);
                return ans;
            }
            hashTable[nums[i]] = i;
        }
        
        return ans;
    }
};







int main(int argc, const char * argv[]) {
    
    
    std::cout << "Hello, World!\n";
    
    return 0;
}
