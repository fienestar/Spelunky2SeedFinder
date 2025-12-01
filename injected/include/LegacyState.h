#pragma once

#include "state.hpp"

struct SaveData;
struct Layer;
struct LevelGenSystem;
class ThemeInfo;

struct State
{
    static State& get();

    // Returns the main-thread version of StateMemory*
    StateMemory* ptr() const;

    Layer* layer(uint8_t index) const
    {
        return ptr()->layers[index];
    }

    Items* items() const
    {
        return ptr()->items;
    }

    void godmode(bool g);

    void zoom(float level);

    std::pair<float, float> click_position(float x, float y);

    Entity* find(uint32_t uid);

    void warp(uint8_t w, uint8_t l, uint8_t t);
    void set_seed(uint32_t seed);
};
