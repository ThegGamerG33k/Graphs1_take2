#define DO_GRAPH_TESTS 1
#if DO_GRAPH_TESTS
#include <gtest/gtest.h>
#else
#include <SFML/Graphics.hpp>
#include <text_circle.h>
#include <graph1.h>
#include <iostream>
#include <word_drawer.h>
#include <fstream>
#include <string>
#endif

int main()
{
#if DO_GRAPH_TESTS
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
#else
    const unsigned int win_width = 1000, win_height = 800;
    sf::RenderWindow window(sf::VideoMode(win_width, win_height), "SFML works!");
    sf::Font circle_font;
    if (!circle_font.loadFromFile("../../../media/fonts/Lato/Lato-Black.ttf"))
        std::cout << "Error opening font file\n";

    std::fstream inputFile("../../../media/books/output.txt", std::ios::in);
    std::string line;

    ssuds::Graph<int, float> con;
    ssuds::UnorderedMap<int, sf::TextCircle> extra;

    while (getline(inputFile, line))
    { 
        if (inputFile.peek() == 'e')
        {
            std::string edge;
            getline(inputFile, edge, ':');
            int nodebase;
            inputFile >> nodebase;
            int nodecon;
            inputFile >> nodecon;
            float edgelen;
            inputFile >> edgelen;
            con.add_edge(nodebase, nodecon, edgelen);
        }
        else
        {
            std::string node;
            getline(inputFile, node, ':');
            int nindex;
            inputFile >> nindex;
            std::string name;
            getline(inputFile, name, ':');
            int red;
            inputFile >> red;
            int green;
            inputFile >> green;
            int blue;
            inputFile >> blue;
            float x;
            inputFile >> x;
            float y;
            inputFile >> y;
            con.add_node(nindex);
            sf::TextCircle temp(x, y, circle_font, name);
            temp.setCircleColor(sf::Color(red, green, blue));
            extra[nindex] = temp;
        }

        std::cout << line << std::endl;
    }

    inputFile.close();

    
    /*misc::WordDrawer WD("../../../media/SCOWL/final/american-words.80", circle_font);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (!WD.handle_event(event))
                window.close();
        }

        window.clear();
        WD.draw(window);
        window.display();
    }*/

    return 0;
#endif
}