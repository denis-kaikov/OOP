#include <iostream>
#include <vector>
#include "coordinates.h"
//template<typename T>
//std::vector<T> AvgValue(std::vector<std::vector<T> > vec){
//    std::vector <T> avg;
//    for(int i=0;i<vec[0].size();i++){
//        avg.push_back(0);
//    }


//    for(auto& row:vec){
//       int i =0;
//       for(auto& col:row){
//         avg[i]+=col;
//         i++;
//       }
//    }
//    for(int i=0;i<vec[0].size();i++){
//        avg[i]=  avg[i]/vec.size();
//        std::cout<<avg[i];
//        if(i<vec[0].size()-1) std::cout<<",";
//    }
//    std::cout<<std::endl;
//    return avg;
//}


using namespace std;




template<typename T>
T AvgValue(std::vector<T> vec){
    T avg{};
    for (const auto &v: vec){
        avg = avg + v;
    }
    T ans = avg/vec.size();
    return ans;
}

int main()
{



    //Пример double
    std::vector<Coordinates<double>> vect_int;
    Coordinates a (2.5,3.8);
    vect_int.push_back( a );
    Coordinates c (10.5,4.9);
    vect_int.push_back( c );
    Coordinates b (8.0,7.0);
    vect_int.push_back( b );


    Coordinates avg_int = AvgValue(vect_int);
    cout<<avg_int.GetX()<<","<<avg_int.GetY()<<endl;




}
