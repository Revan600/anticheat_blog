#include "game.h"

#include <entities/pickup_controller.h>

#include "utils.h"

#include "entities/local_player.h"

Game::Game() : Object(TypeId<Game>::Value) {
    AddEntity<LocalPlayer>();
    AddEntity<PickupController>();
}

void Game::Run() {
    InitWindow(ScreenWidth, ScreenHeight, "Simple 2D playground");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // do not use range-based for because iterator may become invalid
        for (int i = 0; i < m_entities.size(); ++i) { // NOLINT(*-loop-convert)
            m_entities[i]->Tick();
        }

        EndDrawing();
    }

    CloseWindow();
}

void Game::DeleteEntity(EntityBase* entity) {
    const auto it = std::find(m_entities.begin(), m_entities.end(), entity);
    m_entities.erase(it);
    delete entity;
}
