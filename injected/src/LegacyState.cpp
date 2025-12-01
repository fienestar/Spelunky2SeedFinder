#include "LegacyState.h"

State& State::get()
{
    static State STATE;
    API::init();
    return STATE;
}

StateMemory* State::ptr() const
{
    return get_state_ptr();
}

std::pair<float, float> State::click_position(float x, float y)
{
    return API::click_position(x, y);
}

void State::zoom(float level)
{
    API::zoom(level);
}

void State::godmode(bool g)
{
    API::godmode(g);
}

void State::warp(uint8_t w, uint8_t l, uint8_t t)
{
    ptr()->warp(w, l, t);
}

void State::set_seed(uint32_t seed)
{
    ptr()->set_seed(seed);
}

Entity* State::find(uint32_t uid)
{
    return ptr()->get_entity(uid);
}
