#include <SFML/Graphics.hpp>
#include "../lib/imgGen.h"

int main()
{
    int windowWidth = 400;
    int windowHeight = 300;

    // create the window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "My window");

    // image stuff
    FractImg img1(windowWidth, windowHeight);

    sf::Texture texture;
    sf::Sprite sprite;

    // non animated Image
    img1.genImg(1);
    img1.img.saveToFile("img/img.png");
    texture.loadFromFile("img/img.png");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);


        // animate image
        img1.genImg(1);
        img1.permute();
        img1.img.saveToFile("img/img.png");
        texture.loadFromFile("img/img.png");


        sprite.setTexture(texture);
        window.draw(sprite);

        // end the current frame
        window.display();
    }

    return 0;
}
