#include "anticheat_handler.h"

#include <anticheat.h>
#include <Windows.h>

static void OnAnticheatViolationDetected(anticheat::Violation* violation) {
    MessageBoxA(nullptr, "OnAnticheatViolationDetected", "Detected violation", MB_OK);
}

void AnticheatHandler::Init() {
    anticheat::Init(OnAnticheatViolationDetected);
}
