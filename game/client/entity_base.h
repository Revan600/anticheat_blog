#pragma once

#include "object.h"

class EntityBase : public Object {
protected:
    class Game* m_game;

public:
    explicit EntityBase(Game* game, int typeId)
    : Object(typeId), m_game(game) {}

    virtual ~EntityBase() = default;
    virtual void Tick() = 0;
};
