#include <SFML/Graphics.hpp>
#include <iostream>
#include "tools/cpp/runfiles/runfiles.h"
#include "consts.h"

using bazel::tools::cpp::runfiles::Runfiles;

int main(int argc, char** argv)
{

    std::string error;

    Runfiles* runfiles = Runfiles::Create(argv[0], &error);
    std::string fontPath = "";

    if(runfiles != nullptr)
    {
        std::string rloc = "_main/";
        fontPath = runfiles->Rlocation(rloc + fontRegular);
    }

    sf::Font font(fontPath);

    sf::Text text(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Green);
    text.setString("Hello");


    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(text);

        // end the current frame
        window.display();
    }
}
