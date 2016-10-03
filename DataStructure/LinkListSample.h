//
// Created by airfr on 2016/9/26.
//

#include <cstddef>
#include <iostream>

#ifndef ALGOPRACTICE_LINKLISTSAMPLE_H
#define ALGOPRACTICE_LINKLISTSAMPLE_H


struct Sample {
public:
    int x, y;

    Sample() : x(0), y(0) {};
    Sample(int x, int y) : x(x),y(y){};
    friend bool operator==(const Sample &lhs, const Sample &rhs) {
        if (lhs.x == rhs.x) return lhs.y == rhs.y;
        return false;
    };
};

class LinkListSampleNode {
private:
    typedef LinkListSampleNode Node;
public:
    Node *next = nullptr;
    Node *prev = nullptr;
    Sample *dataset;

    LinkListSampleNode(Sample* pinner):dataset(pinner){  };
};

class LinkListSample {
private:
    size_t size = 0;
    LinkListSampleNode *start;
protected:
    typedef LinkListSampleNode Node;
public:
    bool Add(Node *);

    bool Insert(Node *, Node *);

    bool Insert(size_t, Node *);

    bool Delete(Node *);

    Node* Find(Sample *);

    Node* Find(int, int );

    inline LinkListSample(int x, int y):start(new Node(new Sample(x,y))){};
    inline LinkListSample(Sample* pct):start(new Node(pct)){};
    inline LinkListSample(Node* pnode):start(pnode){};

    // accessor

    inline size_t getSize(){
        return  size;
    }

    inline Node* getStart(){
        return start;
    }

};

#endif //ALGOPRACTICE_LINKLISTSAMPLE_H

