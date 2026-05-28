#pragma once

#include "StoneTile.h"

class DeepslateTile : public Tile {
protected:
    int resourceId;
public:
    DeepslateTile(int id, int tex, int resId = 0) : Tile(id, tex, Material::stone) {
        if (resId == 0) this->resourceId = id;
        else this->resourceId = resId;
    }

    int getResource(int data, Random* random) {
        return resourceId;
    }
};

class PolishedDeepslateTile : public StoneTile {
public:
    PolishedDeepslateTile(int id) : StoneTile(id, 18 | Tile::TEXTURE_ALT_FLAG) {
        setDescriptionId("polished_deepslate");
    }
};

class DeepslateTilesTile : public StoneTile {
public:
    DeepslateTilesTile(int id) : StoneTile(id, 19 | Tile::TEXTURE_ALT_FLAG) {
        setDescriptionId("deepslate_tiles");
    }
};

class DeepslateBricksTile : public StoneTile {
public:
    DeepslateBricksTile(int id) : StoneTile(id, 20 | Tile::TEXTURE_ALT_FLAG) {
        setDescriptionId("deepslate_bricks");
    }
};
