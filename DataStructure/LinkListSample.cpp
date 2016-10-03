//
// Created by Crepus    culo on 2016/9/26.
//

#include "LinkListSample.h"
bool LinkListSample::Add(Node * _insert){
    Node *cnt = this->start;
    while (cnt->next != NULL){
        cnt = cnt->next;
    }
    cnt->next = _insert;
    return true;
}

bool LinkListSample::Insert(Node *_prev, Node *_insert)
{
    Node *cnt = this->start;
    while (cnt->next != NULL)
    {
        if (cnt != _prev){
            cnt = cnt->next;
        } else{
            this->size++;

            Node * _next = _prev->next;
            _insert->next = _next;
            _insert->prev = _prev;
            _next->prev =_insert;
            _prev->next =_insert;
            return true;
        }
    }
    return true;
}

bool LinkListSample::Insert(size_t _loc, Node *_insert)
{
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
            this->size++;
            _insert->next = cnt->next;
            _insert->prev = cnt->prev;
            cnt->next->prev =_insert;
            cnt->prev->next =_insert;
            return true;
        }
        count++;
    }
    return false;
}

bool LinkListSample::Delete(Node *_target)
{
    Node *cnt = this->start;
    while (cnt->next != NULL)
    {
        if (cnt == _target) {
            Node* prev = cnt->prev;
            Node* next = cnt->next;
            if(prev != nullptr) prev->next = cnt->next;
            if(next != nullptr) next->prev = cnt->prev;
            delete(cnt);
            size--;
            return true;
        }
        cnt = cnt->next;

    }
    std::clog << "LinkListSample::Delete : No Such Target Here" << std::endl;
    return false;
}

LinkListSampleNode *LinkListSample::Find(Sample *_target)
{
    Node *cnt = this->start;
    while (cnt->next != NULL)
    {
        if (*cnt->dataset == *_target) return cnt;
        cnt = cnt->next;
    }
    std::clog << "LinkListSample::Find : No Such Target Here" << std::endl;
    return NULL;
}


LinkListSampleNode *LinkListSample::Find(int x, int y)
{
    Sample target(x, y);
    Node *cnt = this->start;
    while (cnt->next != NULL)
    {
        if (cnt->dataset->x == target.x && cnt->dataset->y == target.y) {
            return cnt;
        }
        cnt = cnt->next;
    }
    std::clog << "LinkListSample::Find : No Such Target Here" << std::endl;
    return NULL;
}