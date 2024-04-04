#include <iostream>
class Entity {
    private:
        int entity_ = 0; // Default value initialized
    public:
        Entity() {
            std::cout << "Constructing entity!"
                      << std::endl;
        }
        Entity(const int& x) {
            entity_ = x;
            std::cout << "Constructing entity with an integer"
                      << std::endl;
        }
        // Creating a copy constructor
        Entity(const Entity& entity) {
            entity_ = entity.entity_;
        }
        ~Entity() {
           std::cout << "Destructing entity!"
                     << std::endl;
        }

        // Marked as const => can not assign data members here
        void getEntity() const {
           std::cout << "The entity is" << entity_
                     << std::endl;
        }

        // const reference => no parameter modified here
        void setEntity(const int& ent) {
           entity_ = ent;
        }
};

