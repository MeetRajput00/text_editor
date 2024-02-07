#include "../include/CustomWindow.h"

//define input buffer
std::string inputBuff="";
bool showCursor = true; 

void CustomWindow::start_window(){
    this->initialize_text();
    this->initialize_cursor();
    while (CustomWindow::window.isOpen())
    {        
        if (this->clock.getElapsedTime() > sf::seconds(0.5f))
        {
            // half a second has passed
            this->clock.restart(); // restart the clock
            showCursor = !showCursor; // toggle the flag
        }
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (CustomWindow::window.pollEvent(event))
        {
            this->handle_events(&event,&window);   
        }
    }
}

void CustomWindow::handle_events(sf::Event *event, sf::RenderWindow *window){
    window->clear(sf::Color::White); // clear the window with white color
    // "close requested" event: we close the window
    if (event->type == sf::Event::Closed)
        window->close();
    if (event->type == sf::Event::Resized)
    {
        //todo: handle screen resize
        std::cout << "new width: " << event->size.width << std::endl;
        std::cout << "new height: " << event->size.height << std::endl;
    }
    if (event->type == sf::Event::KeyPressed) {
         // a key was pressed
        if (event->key.code == sf::Keyboard::BackSpace)
        {
            // backspace was pressed
            // remove the last character from your text string
            if(!inputBuff.empty())
                inputBuff.pop_back();
        }
        else if (event->key.code == sf::Keyboard::Return)
        {
            inputBuff+="\n";
        }
      }
      else if(event->type == sf::Event::TextEntered){
        if(event->text.unicode!=8){
            inputBuff+=static_cast<char>(event->text.unicode);                
        }
    }        
    this->text.setString(inputBuff);
    this->text.setPosition(this->pos.x,this->pos.y);
    this->window.draw(this->text);
    if (showCursor)
    {
        // show the cursor rectangle
        this->cursor.setPosition(this->text.findCharacterPos(inputBuff.size())); // set the rectangle position at the end of the text
        this->window.draw(this->cursor); // draw the rectangle
    }
    this->window.display();
  }

void CustomWindow::initialize_cursor(){
    this->cursor.setSize(sf::Vector2f(2, this->text.getCharacterSize())); // set the size of the rectangle
    this->cursor.setFillColor(this->text.getFillColor()); // set the fill color of the rectangle
}

void CustomWindow::initialize_text(){    
    if (!CustomWindow::font.loadFromFile("../../fonts/OpenSans-Regular.ttf"))
    {
        std::cout<<"Error loading font."<<std::endl;
    }
    this->CharacterSize=12;
    this->pos.currLine=1;
    this->pos.x=0;
    this->pos.y=0;
    CustomWindow::text.setFont(CustomWindow::font);

    // set the character size
    CustomWindow::text.setCharacterSize(24); // in pixels, not points!

    // set the color
    CustomWindow::text.setFillColor(sf::Color::Black);
}