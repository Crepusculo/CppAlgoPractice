//
// Created by Crepusculo on 2016/10/4.
//

#ifndef ALGOPRACTICE_QUEUEARRAYSAMPLE_H
#define ALGOPRACTICE_QUEUEARRAYSAMPLE_H


#include <cstddef>

template<typename T>
class QueueArraySample {
private:
    constexpr static size_t SIZE = 5;
    size_t len;
    T *array = new T[SIZE];

    T *array_start = array;
    T *array_end   = &array[SIZE];

    T *start = nullptr;
    T *end = nullptr;
protected:
    bool is_full();

public:
    QueueArraySample() : len(0), start(array), end(array+1) {
        for(int i = 0; i<SIZE; i+=1){
            array[i] = NULL;
        }
    }

    bool push(T);

    bool fpush(T);

    T pop();

    size_t getSize();

    size_t getLen();

    void  treval();
};

//
// Created by airfr on 2016/10/4.
//

#include "QueueArraySample.h"

template<typename T>
bool QueueArraySample<T>::is_full() {
    return this->getSize() <= this->getLen();
}


template<typename T>
bool QueueArraySample<T>::push(T target) {
    if (getSize() <= getLen()) {
        std::clog << "Queue is Full, Push Failed" << std::endl;
        return false;
    }

    //  *
    //  *  start      end
    //  *    |         |
    //  *    ------------------
    //  *

    //  *
    //  *    start    end
    //  *      |       |
    //  *    ------------------
    //  *

    //  *
    //  *     end    start
    //  *      |       |
    //  *    ------------------
    //  *
    if(this->end != this->array_end && this->end != this->start){
        *(this->end) =  target;
        this->end++;
        this->len++;

        //  *
        //  *    start            end
        //  *      |               |
        //  *    ------------------
        //  *

        //  *
        //  *    start             end
        //  *     |                 |
        //  *     ------------------
        //  *
        if(this->end == this->array_end) this->end = this->array_start;
    }

    //  *
    //  *           end
    //  *           start
    //  *            |
    //  *     -----------------
    //  *    ( len != 0 )
    else if (SIZE <= this->len){
        std::clog << "Failed to push, array has already fulled." << std::endl;
    }

    else{
        std::clog<< "Some Status I can't found out." << std::endl;
        return false;
    }
    return true;
}

template<typename T>
bool QueueArraySample<T>::fpush(T target) {
    if (getSize() <= getLen()) {
        std::clog << "Queue is Full, Push Failed" << std::endl;
        return false;
    }

    //  *
    //  *  start      end
    //  *    |         |
    //  *    ------------------
    //  *

    //  *
    //  *    start    end
    //  *      |       |
    //  *    ------------------
    //  *

    //  *
    //  *     end    start
    //  *      |       |
    //  *    ------------------
    //  *
    if(this->end != this->array_end && this->end != this->start){
        *(this->end) =  target;
        this->end++;
        this->len++;

        //  *
        //  *    start            end
        //  *      |               |
        //  *    ------------------
        //  *

        //  *
        //  *    start             end
        //  *     |                 |
        //  *     ------------------
        //  *
        if(this->end == this->array_end) this->end = this->array_start;
    }

        //  *
        //  *           end
        //  *           start
        //  *            |
        //  *     -----------------
        //  *    ( len != 0 )
    else if (SIZE <= this->len){
        std::clog << "Failed to push, array has already fulled." << std::endl;
    }

    else{
        std::clog<< "Some Status I can't found out." << std::endl;
        return false;
    }
    return true;
}

template<typename T>
T QueueArraySample<T>::pop() {
    //  *
    //  *    start    end
    //  *      |       |
    //  *    ------------------
    //  *

    //  *
    //  *    end
    //  *    start
    //  *     |
    //  *     -----------------
    //  *    ( len == 0 )

    //  *
    //  *
    //  *    end     start
    //  *     |        |
    //  *     -----------------
    //  *    ( len != 0 )
}

template<typename T>
size_t QueueArraySample<T>::getSize() {
    return this->SIZE;
}

template<typename T>
size_t QueueArraySample<T>::getLen() {
    return this->len;
}

template<typename T>
void QueueArraySample<T>::treval(){
    T* cnt = this->array_start;
    std::cout<<"Size:" << getSize();
    for (; cnt<this->array_end; cnt += 1){
        if(cnt != this->array_start) std::cout << " <- ";
        std::cout.width(15);
        if(start == nullptr) std::cout << "null";
        else std::cout << *cnt;
    }
    std::cout<<std::endl;
}
#endif //ALGOPRACTICE_QUEUEARRAYSAMPLE_H
