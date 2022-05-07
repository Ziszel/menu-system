#include "option.hpp"
#include <iostream>

Option::Option(std::string _option_value)
{
    option_value = _option_value;
    rect_colour = LIGHTGRAY;
    rect_pos = {0.0f, 0.0f};
    rect_size = {100.0f, 25.0f};
    font_size = 30;
    text_margin = {10.0f, 10.0f};
    rect.SetPosition(rect_pos.first, rect_pos.second);
    rect.SetSize(rect_size.first, rect_size.second);
}

void Option::Update(float delta_time, std::pair<float, float> start_pos, std::pair<float, float> option_margin, float mouse_x, float mouse_y)
{
    // position options
    rect_pos.first = start_pos.first + option_margin.first ;
    rect_pos.second = start_pos.second + option_margin.second;
    rect.SetPosition(rect_pos.first, rect_pos.second);

    // set '' hover
    if (aabb(mouse_x, mouse_y))
    {
        rect_colour = DARKBLUE;
    }
    else
    {
        rect_colour = LIGHTGRAY;
    }
}

void Option::Draw()
{
    DrawRectangleRec(rect, rect_colour);
}

bool Option::aabb(float mouse_x, float mouse_y)
{
    bool return_value = false;
    if (mouse_x < rect_pos.first + rect_size.first &&
        mouse_x > rect_pos.first &&
        mouse_y < rect_pos.second + rect_size.second &&
        mouse_y > rect_pos.second)
    {
        return_value = true;
    }

    return return_value;

}