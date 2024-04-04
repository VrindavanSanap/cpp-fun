#include <memory>
#include "entity.h"
// Beginning of a scope
int main()
{
    std::unique_ptr<Entity> e1 = std::make_unique<Entity>(6);
    e1->getEntity(); // unique_ptr is smart, it does not
                     // need to be deleted -- it deallocates
                     // as it goes out of scope
    // However, unique_ptr cannot be copied (it's copy
    // constructor is deleted). So,
    // std::unique_ptr<Entity> e2 = e1 does NOT work
    std::unique_ptr<Entity> e2(std::move(e1)); // point to e1
    // e1->getEntity() will fail because e1 has been freed
    e2->getEntity();
} // End of main
