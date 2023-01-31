#include <iostream>
#include <math.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;
using std::floor;
using std::vector;

void merge_sort(vector<int> &list, size_t s_index, size_t l_index);
void merge(vector<int> &list, size_t s_index, size_t middle, size_t l_index);
void check_sum(vector<int> &list, size_t s_index, size_t l_index, int test_num, vector<int> &sum_list);
void show_sorted_list(vector<int> &list);

int main (){
    cout << boolalpha;

    vector<int> arr_list {7,1,3,0,9,2,4,5};
    vector<int> sum_list;

    show_sorted_list(arr_list);
    check_sum(arr_list,0,arr_list.size() - 1 ,9,sum_list);

    return 0;

}

void merge(vector<int> &list, size_t s_index, size_t middle, size_t l_index){

    size_t n1{middle - s_index + 1};
    size_t n2{l_index - middle};

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
        }else{
            list.at(k) = R.at(j);
            j++;
        }

    }

}

void merge_sort(vector<int> &list, size_t s_index, size_t l_index){
    
   if(s_index < l_index){

        size_t middle {static_cast<size_t>(floor((s_index + l_index)/2))};

        merge_sort(list, s_index, middle);
        merge_sort(list, middle + 1, l_index);
        merge(list,s_index,middle,l_index);
        
   }


}

void check_sum(vector<int> &list, size_t s_index, size_t l_index, int test_num, vector<int> &sum_list){

    if(list.at(s_index) < list.at(l_index)){

        while(l_index > s_index){

            int left_item {list.at(s_index)};
            int right_item {list.at(l_index)};

            if(left_item + right_item > test_num){
                l_index--;
            }else if (left_item + right_item < test_num){
                s_index++;
            }else{
                sum_list.push_back(left_item);
                sum_list.push_back(right_item);
                break;
            }
        }

        if(sum_list.size() == 2){
                cout << sum_list.size() << " items found in the list that sum up to " << test_num << " and they are : " << sum_list.at(0) << " and " << sum_list.at(1) << endl;
        }else{
                cout << "no items found in list that sum up to " << test_num << endl;
        }
    }

    if(list.at(s_index) > list.at(l_index)){

         while(l_index > s_index){

            int left_item {list.at(s_index)};
            int right_item {list.at(l_index)};

            if(left_item + right_item > test_num){
                s_index++;
            }else if (left_item + right_item < test_num){
                l_index--;
            }else{
                sum_list.push_back(left_item);
                sum_list.push_back(right_item);
                break;
            }
        }

        if(sum_list.size() == 2){
                cout << sum_list.size() << " items found in the list that sum up to " << test_num << " and they are : " << sum_list.at(0) << " and " << sum_list.at(1) << endl;
        }else{
                cout << "no items found in list that sum up to " << test_num << endl;
        }
    }
}

void show_sorted_list(vector<int> &list){
    cout << "list before sorting : ";
    
    for (auto const &item: list){
        cout << item << " " ;
    }
    cout << endl;

    cout << "\n list after sorting : ";
    merge_sort(list,0,list.size()-1);

    for(auto const &item: list){
        cout << item << " ";
    }
    cout << "" << endl;
}