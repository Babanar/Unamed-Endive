#ifndef DEF_PNJMANAGER
#define DEF_PNJMANAGER

#include <map>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "pnj.hpp"

class PNJManager
{
private:
    std::map<int, std::vector<PNJ*>> pnjs;

public:
    PNJManager();
    ~PNJManager();
    void add_pnj_on_map(int, const std::string&, const std::string&, PNJkind, const std::string&, int x=32, int y=32);
    int countPNJonMap(int);
    PNJ& getPNJonMap(int, int);
    void update(int, sf::RenderWindow&, sf::Time);
    int find_pnjid_at(int, int, int);
};

#endif // DEF_PNJMANAGER
