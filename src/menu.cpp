#include "menu.hpp"
#include <iostream>

// _value (ALWAYS USE A DIFFERENT VALUE THAN THAT OF THE CLASS PARAMETER (Ambiguity is bad m'kay))
Menu::Menu(std::vector<Option> _options, std::pair<float, float> _start_pos, std::pair<float, float> _offset)
{
    options = _options;
    start_pos = _start_pos;
    offset = _offset;
}

void Menu::Update(float delta_time, Vector2 mouse_pos)
{
    std::pair<float, float> option_margin = start_pos;
    float mouse_x = mouse_pos.x;
    float mouse_y = mouse_pos.y;
    for (auto &opt : options)
    {
        opt.Update(delta_time, start_pos, option_margin, mouse_x, mouse_y);
        option_margin.first += offset.first;
        option_margin.second += offset.second;
    }
}

void Menu::Draw()
{
    for (auto opt : options)
    {
        opt.Draw();
    }
}