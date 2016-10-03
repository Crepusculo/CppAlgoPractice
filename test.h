//
// Created by airfr on 2016/10/3.
//
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <ctime>

#ifndef _TEST_
#define _TEST_
using namespace std;
namespace Test{
    struct result{
        size_t size;
        int32_t * loc;
        result(size_t size, int32_t* loc):size(size),loc(loc){}
    };

    result getIntArray(size_t size){
        srand((unsigned)time(NULL));
        int32_t ret[size];
        for(int32_t i = size-1; i>0; i--) {
            ret[i] = rand();
        }
        return result(size, ret);
    }

    int32_t getInt(){
        srand((unsigned)time(NULL));
        return static_cast<int32_t>(rand());
    }
}
#endif