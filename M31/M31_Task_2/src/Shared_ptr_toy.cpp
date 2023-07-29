#include "Shared_ptr_toy.h"

Shared_ptr_toy::Shared_ptr_toy(): refCount(new int(1))
{
    obj = new Toy("SomeToyName");
}

//    Type* operator-> () {return obj;}         // возможно полезно, переформат операторов
//    Type & operator* () {return *obj;}

Shared_ptr_toy::Shared_ptr_toy(std::string inName) : refCount(new int(1))
{
    obj = new Toy(inName);
}

Shared_ptr_toy::Shared_ptr_toy(const Shared_ptr_toy &oth)
{

}

Shared_ptr_toy &Shared_ptr_toy::operator=(const Shared_ptr_toy &oth)
{
    if (this==&oth)
        return *this;
    if (obj!= nullptr)
        delete obj;
    obj = new Toy(*oth.obj);
    refCount=oth.refCount;
    (*refCount)++;
    return *this;
}

Shared_ptr_toy::~Shared_ptr_toy()
{
    (*refCount)--;
    if (*refCount == 0) {
        delete obj;
//            delete refCount;
    }
}

Shared_ptr_toy Shared_ptr_toy::make_shared_toy(std::string inName)
{
    return Shared_ptr_toy(inName);
};

Shared_ptr_toy Shared_ptr_toy::make_shared_toy(Shared_ptr_toy &inToy)
{
    return Shared_ptr_toy(inToy.obj->name);
};

void Shared_ptr_toy::destruct_ptr_toy()
{
    obj = nullptr;
    (*refCount)--;
    delete obj;
}

void Shared_ptr_toy::resetPtr()
{
    (*refCount)--;
    if (*refCount == 0) {
        delete obj;
//            delete refCount;
    }
}

int Shared_ptr_toy::getCount()
{
    if (refCount!= nullptr)
        return *refCount;
    else return 0;
}
