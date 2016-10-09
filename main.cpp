#include <iostream>
#include "test/test_build.h"
#include "test/test_link_list_sample.h"
#include "test/test_queue_array_sample.h"
#include "test/test_cft_class_inherits.h"
#include <ctime>
#include <cstdio>


using namespace std;

char get_a_char();
void menu();

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Play with menu" << std::endl;
    menu();
    return 0;
}

void menu() {
    while(get_a_char()) {
//        Test::TLinkListSample();
//        Test::TQueueArraySample();
        Test::TClassInherits();
    }

}

char get_a_char() {
    return std::getchar();
}


