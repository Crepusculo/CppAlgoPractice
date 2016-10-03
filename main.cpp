#include <iostream>
#include "DataStructure/LinkListSample.h"
#include "test.h"
#include <ctime>

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;

    Test::result ret = Test::getIntArray(200);

    for(int i = 0; i< ret.size; i++){
        cout << i << " ";
        cout << ret.loc[i] << endl;
    }

    LinkListSample *linkListSample = new LinkListSample(Test::getInt(),Test::getInt());
    return 0;
}