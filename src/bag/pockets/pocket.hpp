#ifndef DEF_POCKET
#define DEF_POCKET

#include <vector>
#include <string>

#include "../../json/json.h"
#include "objects/object.hpp"
#include "../../abstract/functions.hpp"

class Pocket {
private:
    std::vector<Object*> objects;
    std::string name;
    bool default_pocket;

public:
    Pocket(const std::string&, bool default_one=false);
    bool load(Json::Value&);
    void add_object(Object*);
    Object* getObject(int);
    void drop_object(int);
    Json::Value serialize();
    std::string& getName();
    int getSize();
};

#endif // DEF_POCKET
