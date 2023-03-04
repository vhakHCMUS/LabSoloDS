#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"

using namespace sf;
using namespace std;




int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML Button Example");

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Error loading font file" << std::endl;
        return 1;
    }

    Button button_Array(50, 50, 100, 50, font, "Array", sf::Color::Red, sf::Color::Blue, sf::Color::Green);
    Button button_LinkedList(50, 150, 100, 50, font, "LinkedList", sf::Color::Red, sf::Color::Blue, sf::Color::Green);
    Button button_Queue(50, 250, 100, 50, font, "Queue", sf::Color::Red, sf::Color::Blue, sf::Color::Green);
    Button button_Stack(50, 350, 100, 50, font, "Stack", sf::Color::Red, sf::Color::Blue, sf::Color::Green);

    bool Array_clicked = false, inputArray = true;
    bool LinkedList_clicked = false;
    bool Queue_clicked = false;
    bool Stack_clicked = false;
    int numValues = 0;
    std::vector<int> values;
    std::vector<sf::RectangleShape> rects;
    float rectWidth = 50.0f;
    float rectHeight = 50.0f;
    float rectSpacing = 10.0f;
    float rectX = rectSpacing;
    float rectY = 0;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        if (!Array_clicked && !LinkedList_clicked && !Queue_clicked && !Stack_clicked)
        {
            renderButtons(window, button_Array, Array_clicked, button_LinkedList, LinkedList_clicked, button_Queue, Queue_clicked, button_Stack, Stack_clicked);
        }


        if (Array_clicked)
        {

            if (inputArray)
            {
                std::cout << "Enter the number of values: ";
                std::cin >> numValues;

                // Prompt the user to enter the values
                std::cout << "Enter the values:\n";
                for (int i = 0; i < numValues; i++) {
                    int value;
                    std::cin >> value;
                    values.push_back(value);
                }
                inputArray = false;

                for (int i = 0; i < numValues; i++) {
                    // Create the rectangle shape
                    sf::RectangleShape rect(sf::Vector2f(rectWidth, rectHeight));
                    rect.setPosition(rectX, rectY);

                    // Set the rectangle color
                    rect.setFillColor(sf::Color::Red);

                    // Create the text for the value
                    sf::Text text(std::to_string(values[i]), font, 20);
                    text.setFillColor(sf::Color::Black);
                    text.setPosition(rectX + rectWidth / 2.0f - text.getLocalBounds().width / 2.0f,
                        rectY + rectHeight / 2.0f - text.getLocalBounds().height / 2.0f);

                    // Add the rectangle and text to the vectors
                    rects.push_back(rect);

                    // Increment the rectangle position for the next rectangle
                    rectX += rectWidth + rectSpacing;
                }
            }
            for (int i = 0; i < numValues; i++) {
                window.draw(rects[i]);

                sf::Text text(std::to_string(values[i]), font, 20);

                text.setFillColor(sf::Color::Black);

                text.setPosition(rects[i].getPosition().x + rectWidth / 2.0f - text.getLocalBounds().width / 2.0f,
                    rects[i].getPosition().y + rectHeight / 2.0f - text.getLocalBounds().height / 2.0f);

                window.draw(text);
            }
        }


        window.display();
    }

    return 0;
}