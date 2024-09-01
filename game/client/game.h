#pragma once

#include <algorithm>
#include <raylib.h>
#include <utils.h>
#include <vector>

#include "entity_base.h"
#include "object.h"

class Game : public Object {
    std::vector<EntityBase*> m_entities;

public:
    static constexpr int ScreenWidth = 800;
    static constexpr int ScreenHeight = 450;

    static constexpr Rectangle GameField{0.0f, 0.0f, ScreenWidth, ScreenHeight};

    Game();

    void Run();

    template <typename TEntity, typename... TArgs>
    TEntity* AddEntity(TArgs&&... args) {
        auto* entity = new TEntity(this, std::forward<TArgs>(args)...);
        m_entities.push_back(entity);
        return entity;
    }

    void DeleteEntity(EntityBase* entity);

    template <typename TEntity>
    size_t FindEntitiesOfType(std::vector<TEntity*>& result) {
        size_t count = 0;

        for (auto entity : m_entities) {
            if (entity->GetTypeId() != TypeId<TEntity>::Value) {
                continue;
            }

            ++count;
            result.push_back(reinterpret_cast<TEntity*>(entity));
        }

        return count;
    }

    template <typename TEntity>
    TEntity* FindEntityOfType() {
        for (auto entity : m_entities) {
            if (entity->GetTypeId() != TypeId<TEntity>::Value) {
                continue;
            }

            return reinterpret_cast<TEntity*>(entity);
        }

        return nullptr;
    }
};
