#include "../include/CustomWindow.h"

void CustomWindow::start_window(){
    this->text.initialize();
    this->cursor.initialize(&this->text.text);
    while (CustomWindow::window.isOpen())
    {        
        if (this->clock.getElapsedTime() > sf::seconds(0.5f))
        {
            this->clock.restart();
            this->cursor.showCursor = !this->cursor.showCursor;
        }
        sf::Event event;
        while (CustomWindow::window.pollEvent(event))
        {
            this->handle_events(&event);   
        }
    }
}

void CustomWindow::handle_events(sf::Event *event){
    this->window.clear(sf::Color::White);
    if (event->type == sf::Event::Closed)
        this->window.close();
    if (event->type == sf::Event::Resized)
    {
        std::cout << "new width: " << event->size.width << std::endl;
        std::cout << "new height: " << event->size.height << std::endl;
    }
    this->handle_keyboard_input(event);
    this->draw_text();
    this->handle_cursor_visibility();
    this->window.display();
  }

  void CustomWindow::handle_keyboard_input(sf::Event *event){
    if (event->type == sf::Event::KeyPressed) {
        if (event->key.code == sf::Keyboard::BackSpace)
        {
            if(!this->text.inputBuff.empty())
                this->text.inputBuff.pop_back();
        }
        else if (event->key.code == sf::Keyboard::Return)
        {
            this->text.inputBuff+="\n";
        }
      }
    else if(event->type == sf::Event::TextEntered){
        if(event->text.unicode!=8){
            this->text.inputBuff+=static_cast<char>(event->text.unicode);                
        }
    }        
  }

  void CustomWindow::draw_text(){
    this->text.text.setString(this->text.inputBuff);
    this->text.text.setPosition(this->text.pos.x,this->text.pos.y);
    this->window.draw(this->text.text);
  }

  void CustomWindow::handle_cursor_visibility(){
    if (this->cursor.showCursor)
    {
        this->cursor.cursor.setPosition(this->text.text.findCharacterPos(this->text.inputBuff.size()));
        this->window.draw(this->cursor.cursor); // draw the rectangle
    }
  }