#include <iostream>
#include <vector>

template<typename T>
std::vector<T> AvgValue(std::vector<std::vector<T> > vec){
    std::vector <T> avg;
    for(int i=0;i<vec[0].size();i++){
        avg.push_back(0);
    }


    for(auto& row:vec){
       int i =0;
       for(auto& col:row){
         avg[i]+=col;
         i++;
       }
    }
    for(int i=0;i<vec[0].size();i++){
        avg[i]=  avg[i]/vec.size();
        std::cout<<avg[i];
        if(i<vec[0].size()-1) std::cout<<",";
    }
    std::cout<<std::endl;
    return avg;
}


using namespace std;

int main()
{



    //Пример double
    std::vector<vector<double>> vect_int;
    vector <double> a = {1,8};
    vect_int.push_back( a );
    vector <double> b = {3,10};
    vect_int.push_back( b );
    vector <double> c = {4,15};
    vect_int.push_back( c );


    vector<double> avg_int = AvgValue(vect_int);




}
