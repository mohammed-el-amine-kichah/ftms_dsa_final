 #include <iostream>
    #include <vector>
    #include <unordered_map>
    using namespace std;
    int nOccur(vector<int>& nums) {
        unordered_map<int,int> mymap;
        int size = nums.size();
        int n = size / 2;
        for (int i=0; i < size; i++ ) {
            mymap[nums[i]]++;
            if (  mymap[nums[i]] == n ) return nums[i];
        }
        return 0;
    }2,1,2,5,3,2
    int main () { 
        vector<int> nums;
        int numsSize = 0;
        cout << " enter the size of the array " << endl;
        cin >> numsSize;
        int num = 0;
        int j =0;
        while ( j < numsSize) {
            cin >> num ;
            nums.push_back(num);
            j++;
        }
        
        
        cout << " the element that occurs n times is " << nOccur(nums) << endl;
        
    
    return 0;}
