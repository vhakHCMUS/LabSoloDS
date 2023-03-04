#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

struct Button {
    sf::RectangleShape shape;
    sf::Text text;
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;
    float pos_x;
    float pos_y;

    Button(float x, float y, float width, float height, sf::Font& font, std::string text,
        sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);

    bool isMouseOver(sf::RenderWindow& window);

    void update(sf::RenderWindow& window);

    bool isClicked(sf::RenderWindow& window);

    void render(sf::RenderTarget& target);

};

void renderButtons(sf::RenderWindow& window,
    Button& button_Array, bool& Array_clicked,
    Button& button_LinkedList, bool& LinkedList_clicked,
    Button& button_Queue, bool& Queue_clicked,
    Button& button_Stack, bool& Stack_clicked);