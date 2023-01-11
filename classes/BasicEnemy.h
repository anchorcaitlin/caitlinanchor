#ifndef OOP_GROUP_PROJECT_BASICENEMY_H
#define OOP_GROUP_PROJECT_BASICENEMY_H

#include "Projectile.h"
#include "Entity.h"


class BasicEnemy : public Entity{
public:
    explicit BasicEnemy(Vector2f position);

    // Called before the move function.
    void update(GameManager *manager);
};


#endif //OOP_GROUP_PROJECT_BASICENEMY_H
