#include <iostream>
using namespace std;

int main( ){

    int nums[10] = {0,0,1,1,1,2,2,3,3,4};

    int index = 0;
    cout<<2<<endl;

    for(int i=0;i<10;++i){
        if(nums[i] != nums[index]){
            swap(nums[index++],nums[i]);
            cout<<"swap"<<endl;
        }
         cout<<"i = "<<i<<"   index= "<<index<<endl;
         for(int j=0;j<10;++j)
            cout<<nums[j];
        cout<<endl;
    }


    return 0;
}

