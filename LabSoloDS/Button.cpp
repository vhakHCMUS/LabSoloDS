#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font& font, std::string text,
    sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->pos_x = x;
    this->pos_y = y;
    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->shape.setFillColor(this->idleColor);

    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(20);
    this->text.setFillColor(sf::Color::White);
    this->text.setPosition(
        this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - (this->text.getGlobalBounds().width / 2.f),
        this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - (this->text.getGlobalBounds().height / 2.f)
    );
}

bool Button::isMouseOver(sf::RenderWindow& window)
{
    sf::IntRect buttonRect(this->shape.getPosition().x, this->shape.getPosition().y, this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().height);
    if (buttonRect.contains(sf::Mouse::getPosition(window)))
    {
        return true;
    }
    return false;
}

void Button::update(sf::RenderWindow& window)
{
    sf::Vector2f originalPos = this->shape.getPosition();
    float move_x = this->pos_x - 5;
    float move_y = this->pos_y - 5;
    if (this->isMouseOver(window))
    {
        this->shape.setFillColor(this->hoverColor);
        this->shape.setPosition(move_x, move_y);
    }
    else
    {
        this->shape.setFillColor(this->idleColor);
        this->shape.setPosition(this->pos_x, this->pos_y);
    }
}

bool Button::isClicked(sf::RenderWindow& window)
{
    if (this->isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return true;
    }
    return false;
}

void Button::render(sf::RenderTarget& target)
{
    target.draw(this->shape);
    target.draw(this->text);
}

void renderButtons(sf::RenderWindow& window,
    Button& button_Array, bool& Array_clicked,
    Button& button_LinkedList, bool& LinkedList_clicked,
    Button& button_Queue, bool& Queue_clicked,
    Button& button_Stack, bool& Stack_clicked)

{
    button_Array.update(window);
    button_LinkedList.update(window);
    button_Queue.update(window);
    button_Stack.update(window);

    button_Array.render(window);
    button_LinkedList.render(window);
    button_Queue.render(window);
    button_Stack.render(window);

    if (button_Array.isClicked(window) && !Array_clicked)
    {
        Array_clicked = true;

    }

    if (button_LinkedList.isClicked(window) && !LinkedList_clicked)
    {
        LinkedList_clicked = true;

    }

    if (button_Queue.isClicked(window) && !Queue_clicked)
    {
        Queue_clicked = true;

    }

    if (button_Stack.isClicked(window) && !Stack_clicked)
    {
        Stack_clicked = true;

    }
}
