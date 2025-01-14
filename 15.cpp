#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        int n_nums = nums.size();
        for(int i = 0; i < n_nums; i++){
            // jump same first element
            if(i != 0 && nums[i-1] == nums[i]){
                continue;
            }
            int mv_right = i + 1, mv_left = n_nums - 1;
            while(mv_right < mv_left){
                //cout << i << "," << mv_right << "," << mv_left << "," << endl;
                int sum = nums[i] + nums[mv_left] + nums[mv_right];
                if(sum == 0){
                    output.push_back({nums[i], nums[mv_left], nums[mv_right]});
                    mv_right += 1;
                    mv_left -= 1;
                    while((mv_right < n_nums) && (nums[mv_right] == nums[mv_right-1])){
                        mv_right += 1;
                    }
                    while((mv_left > i) && (nums[mv_left] == nums[mv_left+1])){
                        mv_left -= 1;
                    }
                }else if(sum < 0){
                    mv_right += 1;
                }else{
                    mv_left -= 1;
                }
            }
        }

        return output;
    }
};
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // output sorted threesum vector
        sort(nums.begin(), nums.end());
        vector<string> sorted_threesum_vec;
        int n_nums = nums.size();
        for(int i = 0; i < n_nums; i++){
            for(int j = i + 1; j < n_nums; j++){
                for(int k = j + 1; k < n_nums; k++){
                    if((nums[i] + nums[j] + nums[k]) == 0){
                        string tmp = to_string(nums[i]) + "," + to_string(nums[j]) + "," + to_string(nums[k]);
                        sorted_threesum_vec.push_back(tmp);
                    }
                }
            }
        }

        // delete duplicate elements
        unordered_set<string> output_set;
        for(string o : sorted_threesum_vec){
            output_set.insert(o);
        }

        vector<string> output_str(output_set.begin(), output_set.end());

        vector<vector<int>> output;
        for(string o_str : output_str){
            vector<int> tmp;
            stringstream ss(o_str);
            string tmp_str;
            while(getline(ss, tmp_str, ',')){
                tmp.push_back(stoi(tmp_str));
            }
            output.push_back(tmp);
        }

        return output;
    }
};
*/

int main() {
    Solution solution;
    //vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> nums = {0, 0, 0, 0};
    vector<vector<int>> result = solution.threeSum(nums);

    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}