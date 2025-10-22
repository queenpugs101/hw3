#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
        bool operator()(uint64_t lhs, uint64_t rhs)const{
            return lhs<rhs ;
        }
} EventLess;
	
#endif
