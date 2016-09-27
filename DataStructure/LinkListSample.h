//
// Created by airfr on 2016/9/26.
//

#include <cstddef>

#ifndef ALGOPRACTICE_LINKLISTSAMPLE_H
#define ALGOPRACTICE_LINKLISTSAMPLE_H

#endif //ALGOPRACTICE_LINKLISTSAMPLE_H

class Sample {
    int x, y;

    Sample() : x(0), y(0) {};

    friend bool operator==(const Sample &lhs, const Sample &rhs) {
        if (lhs.x == rhs.x) return lhs.y == rhs.y;
        return false;
    };
};

class LinkListSample {
private:
    LinkListSampleNode *start;
public:
    bool Insert(LinkListSampleNode *, Sample *);

    bool Insert(size_t, Sample *);

    bool Delete(LinkListSampleNode *);

    bool Find(Sample *);

    inline LinkListSample(int )
    inline LinkListSample(Sample* ct){}
};

class LinkListSampleNode {
private:
    typedef LinkListSampleNode Node;
public:
    Node *next;
    Node *prev;
    Sample *type;

    LinkListSampleNode(Sample){}
};