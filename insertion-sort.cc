#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::boolalpha;

int* insertion_sort(int* list, size_t size);

int main (){
    cout << boolalpha;

    int arr_list [6] {7,1,3,0,9,2};

    cout << "list before sorting : ";
    
    for (auto const &item: arr_list){
        cout << item << " " ;
    }

    cout << "\n list after sorting : ";
    

    for(size_t i{0}; i < 6; i++){
        cout << insertion_sort(arr_list,6)[i] << " ";
    }

    return 0;

}

int* insertion_sort(int* list, size_t size){

    for(size_t j {1}; j < size ; j++){

        int key {list[j]};
        int i;

        i = j - 1;

        while(list[i] > key && i > -1){
            list[i+1] = list[i];
            i--;
            list[i+1] = key;
        }


    }

    return list;
}