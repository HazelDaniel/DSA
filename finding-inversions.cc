#include <iostream>
#include <math.h>
#include <vector>

using std::cout;
using std::endl;
using std::boolalpha;
using std::floor;
using std::vector;

size_t merge_sort(vector<int> &list, size_t s_index, size_t l_index);
size_t merge(vector<int> &list, size_t s_index, size_t middle, size_t l_index);


int main (){
    cout << boolalpha;

    vector<int> arr_list {2,6,7,8,0,5,5,4};


    cout << "list before sorting : ";

    for (auto const &item: arr_list){
        cout << item << " " ;
    }

    cout << endl;

    cout << merge_sort(arr_list,0,arr_list.size() - 1) << " inversions found in the array" << endl;
    cout << "list after sorting : ";

    for(auto const &item: arr_list){
        cout << item << " ";
    }
    
    cout << "" << endl;

    return 0;

}

size_t merge(vector<int> &list, size_t s_index, size_t middle, size_t l_index){

    size_t n1{middle - s_index + 1};
    size_t n2{l_index - middle};
    size_t inv {0};

    vector<int> L (n1+1);
    vector<int> R (n2+1);


    for(size_t i {0}; i < n1; i ++){
        L.at(i) = list.at(s_index + i);
    }

    for(size_t j {0}; j < n2; j ++){
        R.at(j) = list.at(middle + j + 1);
    }

    L.at(n1) = static_cast<int>(MAXFLOAT);
    R.at(n2) = static_cast<int>(MAXFLOAT);

    size_t i {0};
    size_t j {0};

    for(size_t k {s_index}; k <= l_index; k++){

        if(L.at(i) <= R.at(j)){
            list.at(k) = L.at(i);
            i++;
        }
        else{
            inv = middle - i;
            list.at(k) = R.at(j);
            j++;
        }

    }
    return inv;

}

size_t merge_sort(vector<int> &list, size_t s_index, size_t l_index){
    
    size_t inv {0};

    if(s_index < l_index){

        size_t middle {static_cast<size_t>(floor((s_index + l_index)/2))};

        inv = merge_sort(list, s_index, middle);
        inv += merge_sort(list, middle + 1, l_index);
        inv += merge(list,s_index,middle,l_index);
    }
    return inv;

}
