#pragma once
#include <vector>
#include "option.hpp"

class Menu 
{
private:
    std::pair<float, float>start_pos;
    std::vector<Option> options;
    std::pair<float, float> offset;

public:
    Menu(std::vector<Option> _options, std::pair<float, float> _start_pos, std::pair<float, float> offset);
    void Update(float delta_time, Vector2 mouse_pos);
    void Draw();
};