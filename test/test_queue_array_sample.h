//
// Created by airfr on 2016/10/4.
//

#ifndef ALGOPRACTICE_TEST_QUEUE_ARRAY_SAMPLE_H
#define ALGOPRACTICE_TEST_QUEUE_ARRAY_SAMPLE_H
#include "test_build.h"
#include "../data_structure/QueueArraySample.h"

using namespace std;
namespace Test {
    void PrintQueueArraySampleMessage(){

    }

    void TQueueArraySample(){
        QueueArraySample<int> *queue = new QueueArraySample<int>();
        for (int i = 0; i<queue->getSize()-1 ; i+=1) {
            queue->push(i+100);
            queue->treval();
        }
        for (int i = 0; i<queue->getSize()-2 ; i+=1) {
            queue->pop();
            queue->treval();
        }
        for (int i = 0; i<queue->getSize()+3 ; i+=1) {
            queue->push(i+100);
            queue->treval();
        }
    }
}

#endif //ALGOPRACTICE_TEST_QUEUE_ARRAY_SAMPLE_H
