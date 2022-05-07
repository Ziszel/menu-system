#pragma once
#include <string>
#include <raylib-cpp.hpp>

class Option
{
private:
    std::string option_value;
    int font_size;
    std::pair<float, float> text_margin;
    std::pair<float, float> rect_size;
    raylib::Color rect_colour;
    bool selected = false;

public:
    std::pair<float, float> rect_pos;
    raylib::Rectangle rect;
    bool aabb(float mouse_x, float mouse_y);
    Option(std::string option_value);
    void Update(float delta_time, std::pair<float, float> start_pos, std::pair<float, float> offset, float mouse_x, float mouse_y);
    void Draw();

};