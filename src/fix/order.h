#ifndef ORDER_H
#define ORDER_H

namespace fix
{

enum State
{
    UNINIT=0,
    PENDING_NEW,
    NEW,
    PENDING_REPLACE,
    REPLACED,
    PENDING_CANCEL,
    CANCELLED,
    PARTIALLY_FILLED,
    FILLED,
    SUSPENDED,
    EXPIRED
};

class Order
{
    
};
}

#endif //ORDER_H
