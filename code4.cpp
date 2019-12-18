#include<iostream>
#define N 5

using std::cout;
using std::endl;
using std::cin;

template<typename T>
T find_Max(T array[N]){
    T max = array[0];

    for(int i=1; i<N; i++){
        if(array[i]>max){
            max = array[i];
        }
    }

    return max;
}

int main(){
    int array1[5] = {3, 4,741, 1, 5};
    double array2[5] = {23.2, 2341.2, 1.3, 31.2, 12.7};

    int max1 = find_Max(array1);
    double max2 = find_Max(array2);

    cout << "the max in the first array is : " << max1 << endl;
    cout << endl;
    cout << "the max int the second array is :" << max2 << "\n";
    cout << "using blank" << endl;

    system("pause");
    return 0;

}