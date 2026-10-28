#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;
class $modify(MyPlayLayer, PlayLayer) {
    bool init(GJGameLevel* p0, bool p1, bool p2) {
        if(!PlayLayer::init(p0,p1,p2)) return false;
        log::info("GELA BOT OK");
        return true;
    }
};
