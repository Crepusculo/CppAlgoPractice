//
// Created by airfr on 2016/10/9.
//

#ifndef ALGOPRACTICE_TANGGEFU_H
#define ALGOPRACTICE_TANGGEFU_H


#include <iostream>

class TangGefu {
public:
    TangGefu(){
        std::cout<<"TangGefu:"<<"\t"<<"Constructor"<<std::endl;
    }
    ~TangGefu(){
        std::cout<<"TangGefu:"<<"\t"<<"Destructor"<<std::endl;
    }
};

class LiRuiDong : TangGefu{
public:
    LiRuiDong(){
         std::cout<<"LiRuiDong:"<<"\t"<<"Constructor"<<std::endl;
    }
    ~LiRuiDong(){
        std::cout<<"LiRuiDong:"<<"\t"<<"Destructor"<<std::endl;
    }
};

//class GuoAoTian : TangGefu {
//
//};
//
//class TuoShengXuan : TuoShengXuan {
//
//};
#endif //ALGOPRACTICE_TANGGEFU_H
