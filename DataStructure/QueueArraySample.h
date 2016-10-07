//
// Created by Crepusculo on 2016/10/4.
//

#ifndef ALGOPRACTICE_QUEUEARRAYSAMPLE_H
#define ALGOPRACTICE_QUEUEARRAYSAMPLE_H


#include <cstddef>

template<typename T>
class QueueArraySample {
private:
    constexpr static size_t SIZE = 100;
    size_t len;
    T *array = new T[SIZE];

    T *start = nullptr;
    T *end = nullptr;
protected:
    bool is_full();

public:
    QueueArraySample() : len(0), start(array), end(array) {}

    bool push(T);

    bool fpush(T);

    T pop();

    size_t getSize();

    size_t getLen();
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
    if(this->end != &this->array[SIZE] && this->end != this->start){
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
        if(this->end == &this->array[SIZE]) this->end = this->array;
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
    //  *    start           end
    //  *      |              |
    //  *    ------------------
    //  *

    //  *
    //  *    start            end
    //  *     |                |
    //  *     ------------------
    //  *

    //  *
    //  *     end    start
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
    //  *           end
    //  *           start
    //  *            |
    //  *     -----------------
    //  *    ( len != 0 )
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

#endif //ALGOPRACTICE_QUEUEARRAYSAMPLE_H
