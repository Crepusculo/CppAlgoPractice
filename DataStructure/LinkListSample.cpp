//
// Created by Crepus    culo on 2016/9/26.
//

#include "LinkListSample.h"
bool LinkListSample::Add(Node * _insert){
    Node *cnt = this->start;
    while (cnt->next != nullptr){
        cnt = cnt->next;
    }
    cnt->next = _insert;
    _insert->prev = cnt;
    this->size++;
    return true;
}

bool LinkListSample::Insert(Node *_prev, Node *_insert)
{
    Node *cnt = this->start;
    while (cnt != NULL)
    {
        if (cnt != _prev){
            cnt = cnt->next;
        } else{
            this->size++;

            Node * _next = _prev->next;
            _insert->next = _next;
            _insert->prev = _prev;
            if(_next != nullptr) _next->prev =_insert;
            if(_prev != nullptr) _prev->next =_insert;
            return true;
        }
    }
    return true;
}

bool LinkListSample::Insert(size_t _loc, Node *_insert)
{
    if(_loc == 0){
        std::clog << "0" << std::endl;
        _insert->next = this->start;
        this->start->prev = _insert;
        this->start = _insert;
        return true;
    }
    if(_loc > this->size){
        std::clog << "LinkListSample::Insert : LinkList Size OverFlow" << std::endl;
        return false;
    }
    size_t count = 0;
    Node *cnt = this->start;
    while (count < _loc)
    {
        if (cnt->next != nullptr){
            cnt = cnt->next;
        } else{
            std::clog<<"null pointer error!"<<std::endl;
        }
        count++;
    }
    this->size++;
    _insert->next = cnt->next;
    _insert->prev = cnt->prev;
    if(cnt->next != nullptr) cnt->next->prev =_insert;
    if(cnt->prev != nullptr) cnt->prev->next =_insert;
    return true;
}

bool LinkListSample::Delete(Node *_target)
{
    Node *cnt = this->start;
    while (cnt->next != NULL)
    {
        if (cnt == _target) {
            if(cnt->prev != nullptr && cnt->next != nullptr){
                cnt->prev->next = cnt->next;
                cnt->next->prev = cnt->prev;
            }
            else if(cnt->prev != nullptr) { // cnt->next == nullptr
                cnt->prev->next = nullptr;
            }
            else if(cnt->next != nullptr) { // cnt->prev == nullptr
                start = cnt->next;
                cnt->next->prev = nullptr;
            }
            delete(cnt);

            size--;
            return true;
        }
        cnt = cnt->next;
    }
    std::clog << "LinkListSample::Delete : No Such Target to Delete Here" << std::endl;
    return false;
}

LinkListSampleNode *LinkListSample::Find(Sample *_target)
{
    Node *cnt = this->start;
    while (cnt->next != nullptr)
    {
        if (*cnt->dataset == *_target) return cnt;
        cnt = cnt->next;
    }
    std::clog << "LinkListSample::Find : No Such Target Sample Here" << std::endl;
    return nullptr;
}


LinkListSampleNode *LinkListSample::Find(int x, int y)
{
    Node *cnt = this->start;
    while (cnt != nullptr)
    {
        if (cnt->dataset->x == x && cnt->dataset->y == y) {
            return cnt;
        }
        cnt = cnt->next;
    }
    std::clog << "LinkListSample::Find : No Such Target X and Y Here" << std::endl;
    return nullptr;
}