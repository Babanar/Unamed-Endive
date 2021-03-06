#ifndef DEF_DEX
#define DEF_DEX

#include <vector>
#include <map>
#include <string>
#include "../json/json.h"
#include "../abstract/type.hpp"
#include "../abstract/functions.hpp"

class Dex
{
private:
    Json::Value root;
    Json::Value root_player;
    std::map<std::string, struct DexInfo> content;
    std::map<int, std::string> id_name;
    std::vector<std::string> names;
    int _current;

public:
    Dex();
    bool load(const std::string&);
    void save(const std::string&);
    std::string getNext();
    DexInfo getInfo(const std::string&);
    DexInfo getInfo(int);
    void register_viewed(int);
    void register_capture(int);
    std::string getName(int);
    int getMaxId();
};

#endif // DEF_DEX
