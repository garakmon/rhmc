#ifndef MAP_H
#define MAP_H

/*
 * Map class - basically copied from pretmap's map class
 */

// I should really just be adding this to a branch of pretmap, huh

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <map>
using std::map;

#include "global.h"
#include "rom.h"

class MapGroups;

// struct?
class Connection {

public:
    Connection() {}
    string direction;
    string offset;
    string map_name;

};

// probably shouldn't worry about events? at least not yet?
class Event {

public:
    string type;
    int    x;
    int    y;
    string script;
}

class MapLayout {

public:
    MapLayout() {}
    int index;
    string name;
    string label;
    string width;
    string height;
    string border_label;
    string border_path;
    string blockdata_label;
    string blockdata_path;
    string tileset_primary_label;
    string tileset_secondary_label;
    //Tileset *tileset_primary = NULL;
    //Tileset *tileset_secondary = NULL;
    //Blockdata* blockdata = NULL;
    //QImage border_image;
    //QPixmap border_pixmap;
    //Blockdata *border = NULL;
    //Blockdata *cached_blockdata = NULL;
    //Blockdata *cached_collision = NULL;
    //Blockdata *cached_border = NULL;
};

// what are you doing stupid
class Map {

private:
    // connections
    //vector<string> map_names_;
    string name;
    string constantName;
    string group_num;
    string layout_label;
    string events_label;
    string scripts_label;
    string connections_label;
    string song;
    string layout_id;
    string location;
    string requiresFlash;
    string weather;
    string type;
    string unknown;
    string show_location;
    string battle_scene;

    MapLayout *layout;
    map<string, vector<Event*>> events;
    //QMap<QString, QList<Event*>> events;
    //QList<Connection*> connections;

public:
    // 
    void read_maps();

    friend class MapGroups;

}

class MapGroup {

private:
    vector<string> map_names_;
    vector<Map>    maps_;

public:
    //
}

#endif // MAP_H
