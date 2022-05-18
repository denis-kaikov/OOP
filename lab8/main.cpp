#include <iostream>
#include <vector>

template<typename T>
std::vector<T> AvgValue(std::vector<std::vector<T> > vec){
    std::vector <T> avg={0,0};
    for(auto& row:vec){
       int i =0;
       for(auto& col:row){
         avg[i]+=col;
         i++;
       }
    }
    for(int i=0;i<vec.size()-1;i++){
        avg[i]=  avg[i]/vec[i].size();
        std::cout<<avg[i];
        if(i<vec.size()-2) std::cout<<",";
    }
    std::cout<<std::endl;
    return avg;
}


using namespace std;

int main()
{



    //Пример Int
    std::vector<vector<int>> vect_int;
    vector <int> a = {1,2};
    vect_int.push_back( a );
    vector <int> b = {3,5};
    vect_int.push_back( b );
    vector <int> c = {4,2};
    vect_int.push_back( c );


    vector<int> avg_int = AvgValue(vect_int);




}
