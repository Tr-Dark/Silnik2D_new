#ifndef UPDATABLE_OBJECT_H
#define UPDATABLE_OBJECT_H

#include "GameObject.h"

class UpdatableObject : public virtual GameObject {
public:
    virtual void update() = 0;  
};

#endif // UPDATABLE_OBJECT_H

