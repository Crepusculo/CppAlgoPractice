//
// Created by airfr on 2016/10/3.
//

#ifndef ALGOPRACTICE_TEST_LINK_LIST_SAMPLE_H
#define ALGOPRACTICE_TEST_LINK_LIST_SAMPLE_H

#include "../DataStructure/LinkListSample.h"
#include "test_build.h"
#include <sstream>

using namespace std;
namespace Test {
    void PrintMessage(string str) {
        cout << "Link List Sample:\t" << str << endl;
    }

    void TravelNode(LinkListSampleNode *cnt) {
        while (cnt->next != nullptr){
            cout<<"("<< cnt->dataset->x<<","<<cnt->dataset->y <<") <- ";
            cnt = cnt->next;
        }
        cout<<"("<< cnt->dataset->x<<","<<cnt->dataset->y <<")"<<endl;
    }

    void TLinkListSample() {
        std::stringstream ss;
        const int SIZE = 5;
        result array = getIntArray(SIZE * 2);

        Sample *sample = new Sample[SIZE];
        for (size_t i = 0; i < SIZE; i++) {
            // Random Array
//            sample[i] = Sample(array.loc[i],array.loc[i+1]);
            // Order Array
            sample[i] = Sample(i, i);
        }

        // *
        // * Test Constructor
        // *

        LinkListSampleNode *node = new LinkListSampleNode(new Sample(255,255));

        PrintMessage("Build");
        LinkListSample *linklist = new LinkListSample(node);

        //
        // * Test Func : Add
        //
        ss.clear();
        ss << "Add 50 ""Size of link list:" << linklist->getSize();
        PrintMessage(ss.str());

        for (int32_t i = 0; i < SIZE; i += 1) {
            linklist->Add(new LinkListSampleNode(&sample[i]));
        }

        ss.clear();
        ss << "Size of link list:" << linklist->getSize();
        PrintMessage(ss.str());

        //
        // Test Func : Delete & Find
        //
        TravelNode(linklist->getStart());


        PrintMessage("Find and Delete by value:");
        LinkListSampleNode *node1 = linklist->Find(2,2);
        linklist->Delete(node1);
        TravelNode(linklist->getStart());

        PrintMessage("Find and Delete by sample");
        linklist->Delete(linklist->Find(new Sample(255,255)));
        TravelNode(linklist->getStart());
    }
}
#endif //ALGOPRACTICE_TEST_LINK_LIST_SAMPLE_H
