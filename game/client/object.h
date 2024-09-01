#pragma once

class Object {
    int m_type_id;

public:
    explicit Object(int typeId)
    : m_type_id(typeId) {}

    [[nodiscard]] int GetTypeId() const { return m_type_id; }
};
