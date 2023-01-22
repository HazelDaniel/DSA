#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> insertion_sort(vector<int> &list);

int main (){

    vector<int> vec_list {1,7,3,0,9,2};

    cout << "list before sorting : ";
    
    for (auto const &item: vec_list){
        cout << item << " " ;
    }

    cout << "\n list after sorting : ";
    
    for (auto const &item: insertion_sort(vec_list)){
        cout << item << " ";
    }

    return 0;

}

vector<int> insertion_sort(vector<int> &list){

    for(size_t j {1}; j < list.size(); j++){

        int key {list.at(j)};
        int i;

        i = j - 1;

        while(list.at(i) > key && i > -1){
            list.at(i + 1) = list.at(i);
            i--;
            list.at(i + 1) = key;
        }


    }

    return list;
}