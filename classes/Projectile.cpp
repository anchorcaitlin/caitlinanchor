#include "Projectile.h"

#include <SFML/System.hpp>
using sf::Vector2f;

#include <SFML/Graphics.hpp>
using sf::CircleShape;

Projectile::Projectile(Vector2f position, Vector2f velocity, float size) {
    self->position
}

void Projectile::move()
{
    body.move(velocity);
}

bool Projectile::damageEntity(Entity *entity)
{
    return entity->takeDamage(damage);
}

void Projectile::update(GameManager *manager)
{
    lifespan -= 1;
}

Projectile::Projectile(Vector2f position, Vector2f velocity, float size, int lifespan)
{
    self.body = CircleShape(size);
    self.body.setPosition(position);
    self.body.setOrigin(size, size);

    self->velocity = velocity;

    self->lifespan = lifespan;
}