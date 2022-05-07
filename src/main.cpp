#include <raylib-cpp.hpp>
#include "menu.hpp"
#include "option.hpp"
#include <string>
#include <iostream>

int main() {
    
    // Initialization
    int screenWidth = 800;
    int screenHeight = 450;
    float delta_time = 0.0f;

    raylib::Color textColor(LIGHTGRAY);
    raylib::Window w(screenWidth, screenHeight, "Menu System");
    
    SetTargetFPS(60);

    // Create menu items, move them onto the stack
    Option test_option0 = Option("I am option 1!");
    Option test_option1 = Option("I am option 2!");
    Option test_option2 = Option("I am option 3!");
    Option test_option3 = Option("I am option 4!");
    std::vector<Option> options;
    options.push_back(test_option0);
    options.push_back(test_option1);
    options.push_back(test_option2);
    options.push_back(test_option3);

    Menu main_menu = Menu(options, {10.0f, 10.0f}, {0.0f, 50.0f});

    // Each subsequent menu will be put ontop of the last menu in the stack
    std::vector<Menu> menus;
    menus.push_back(main_menu);
    // options will contain a rectangle, text and 'selected' state
    // clicking on an option will 'do something'
    std::cout << menus.size() << "\n";

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        delta_time = GetFrameTime();
        // Update

        // Update only the menu on top of the stack
        menus.back().Update(delta_time, GetMousePosition());

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        menus.back().Draw();

        EndDrawing();
    }

    return 0;
}