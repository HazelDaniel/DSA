#include <iostream>
#include <cmath>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::floor;
using std::vector;

signed int binary_search (vector<int>const &list, int target, int s_index, int l_index);

int main (){
    vector<int> num_list {1,1,5,6,8,9,12,15};
    int target_num {0};
    int start_index {0};

    cout << "Enter an integer. I'll tell you if i have it in my list in O(logn) time" << endl;
    cin >> target_num;

    signed int search_index = binary_search(num_list, target_num, start_index, num_list.size() - 1);

    if (search_index >= start_index && search_index < static_cast<int>(num_list.size())){
        cout << "found at the index " << search_index << endl;
    }else{
        cout << "cannot find number in array. try with another number" << endl;
    }
    
    return 0;
}




signed int binary_search (vector<int>const &list, int target, int s_index, int l_index){

    while(s_index <= l_index){

        int middle {static_cast<int>(floor((s_index + l_index)/2))};
        int item {list.at(middle)};
        
        if(item < target){
            s_index = middle + 1;
        }else if (item > target){
            l_index = middle - 1;
        }else{
            return middle;
        }

    }

    return -1;
}