#ifndef DEF_VIEW
#define DEF_VIEW

#include <SFML/Graphics.hpp>

class View {
private:
    int id;

public:
    View(int);
    int getId();
    virtual void render(sf::RenderWindow&) = 0;
    virtual int process_event(sf::Event&) = 0;
};

#endif // DEF_VIEW