#include <SFML/Graphics.hpp>
#include "../lib/imgGen.h"

int main()
{
    int windowWidth = 800;
    int windowHeight = 800;

    // create the window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "My window");

    // image stuff
    FractImg img1(windowWidth, windowHeight);

    sf::Texture texture;
    sf::Sprite sprite;

    // non animated Image
    /*
    int zero{0};
    img1.genImg(zero);
    cout << zero << endl;
    img1.img.saveToFile("img/img.png");
    texture.loadFromFile("img/img.png");
    */
    int count{0};

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
        img1.genImg(0);
        img1.permute();
        img1.img.saveToFile("img/img.png");
        count++;
        // save images so gif can be made
        img1.img.saveToFile("img/img" + to_string(count) + ".png");
        texture.loadFromFile("img/img.png");


        sprite.setTexture(texture);
        window.draw(sprite);

        // end the current frame
        window.display();
    }

    return 0;
}
