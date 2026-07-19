#pragma once
#include <save_file.h>
#include <level.h>
#include <gc_json.h>
#include <level_loader.h>
#include <engine.h>

class STASaveFile : public ufo::SaveFile{
public:
    //The overworld level
    ufo::Level* overworld = nullptr;
    int lives = 0;
    int powerup = 0;
    int coins = 0;

    STASaveFile(const std::string& _path) : SaveFile(_path){}

    void OnLoad(ufo::gc::JsonMap* _save_file){

    }

};
