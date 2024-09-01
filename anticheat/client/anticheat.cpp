#include "anticheat.h"

static anticheat::ViolationCallback g_ViolationCallback = nullptr;

void anticheat::Init(ViolationCallback Callback) {
    g_ViolationCallback = Callback;
}

void anticheat::Report(Violation& Violation) {
    g_ViolationCallback(&Violation);
}
