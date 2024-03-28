// THIS IS LEETCODE QUESTION 81
#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool search(vector<int>& n, int target) {
    set<int> s(n.begin(),n.end());
    vector<int> nums(s.begin(),s.end()); //it will have all unique elements
    s.clear();
    int start = 0;
    int end = nums.size() - 1;
    int pivot=-1;
    while(start <= end){
        int mid = start + (end-start)/2;

        if(mid == 0 || mid == nums.size()-1){
            pivot=mid;
            break;
        }
        if(nums[mid] > nums[mid+1]){
            pivot= mid;
            break;
        }
        else if(nums[mid] > nums[end]){
            // Highest Number is present in right subarray
            start = mid;
        }
        else if(nums[mid] < nums[end]){
            // Highest number is present in left subarray
            end = mid;
        }
    }
    
    if(target<=nums[pivot] && target>=nums[0]){
        start=0;
        end=pivot;
    }
    else{
        start=pivot+1;
        end=nums.size()-1;
    }
    while(start <= end){
        int mid = start + (end-start)/2;

        if(nums[mid] == target) return true;
        else if(nums[mid] > target) end = mid - 1;
        else start = mid + 1;
    }
    return false;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target number to search for: ";
    cin >> target;

    if (search(nums, target)) {
        cout << "Target found!" << endl;
    } else {
        cout << "Target not found!" << endl;
    }

    return 0;
}
