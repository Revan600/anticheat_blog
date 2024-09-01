#include "anticheat_handler.h"
#include "game.h"

int main() {
    AnticheatHandler::Init();

    Game game;
    game.Run();

    return 0;
}
