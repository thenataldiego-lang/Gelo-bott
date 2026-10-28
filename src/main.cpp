#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;

class $modify(MyLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;
        auto label = CCLabelBMFont::create("GELA BOT OK", "goldFont.fnt");
        label->setPosition({ CCDirector::sharedDirector()->getWinSize().width / 2, 50 });
        label->setScale(0.6f);
        this->addChild(label, 1000);
        return true;
    }
};pl=static_cast<PlayLayer*>(m_parentLayer); if(!pl||!pl->m_objects) return false; float x=getPositionX(),y=getPositionY(); for(auto* o:CCArrayExt<GameObject*>(pl->m_objects)){ if(!o) continue; float ox=o->getPositionX(),oy=o->getPositionY(); if(ox>x&&ox<x+d&&std::abs(oy-y)<90){ if(o->m_type==GameObjectType::Hazard||o->m_type==GameObjectType::Solid) return true; } } return false; }
 void update(float dt){if(BOT&&!m_isDead&&m_parentLayer){ if(m_isInWave){ if(getPositionY()<200){ if(!m_isHolding){m_isHolding=true; pushButton(PlayerButton::Jump);} } else if(getPositionY()>210){ if(m_isHolding){m_isHolding=false; releaseButton(PlayerButton::Jump);} } }else if(m_isInShip||m_isInBird){ if(getPositionY()<90){ if(!m_isHolding){m_isHolding=true; pushButton(PlayerButton::Jump);} } else if(getPositionY()>300){ if(m_isHolding){m_isHolding=false; releaseButton(PlayerButton::Jump);} } else if(danger(150)){ if(!m_isHolding){m_isHolding=true; pushButton(PlayerButton::Jump);} } }else{ if(danger(85)){ if(!m_isHolding){m_isHolding=true; pushButton(PlayerButton::Jump);} }else{ if(m_isHolding&&m_jumpTimer>0.06f){m_isHolding=false; releaseButton(PlayerButton::Jump);} } } float px=getPositionX(); for(float dd:DEATHS){ if(px<dd&&dd-px<90&&dd-px>0){ if(!m_isHolding){m_isHolding=true; pushButton(PlayerButton::Jump);} } } } PlayerObject::update(dt); }
 void playerDestroyed(bool b){ if(BOT){ DEATHS.push_back(getPositionX()); if(DEATHS.size()>40) DEATHS.erase(DEATHS.begin()); } PlayerObject::playerDestroyed(b); }
};
class $modify(Layer, PlayLayer){ bool init(GJGameLevel* l,bool r,bool d){ if(!PlayLayer::init(l,r,d)) return false; auto lb=CCLabelBMFont::creat#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
using namespace geode::prelude;
bool BOT=true;
std::vector<float> DEATHS;
class $modify(Bot, PlayerObject){
 bool danger(float d){if(!m_parentLayer) return false; auto* pl=static_cast<PlayLayer*>(m_parentLayer); if(!pl||!pl->m_objects) return false; float x=getPositionX(),y=getPositionY(); for(auto* o:CCArrayExt<GameObject*>(pl->m_objects)){ if(!o) continue; float ox=o->getPositionX(),oy=o->getPositionY(); if(ox>x&&ox<x+d&&std::abs(oy-y)<90){ if(o->m_type==GameObjectType::Hazard||o->m_type==GameObjectType::Solid) return true; } } return false; }
 void update(float dt){if(BOT&&!m_isDead&&m_parentLayer){ if(m_isInWave){ if(getPositionY()<200){ if(!m_isHolding){m_isHolding=true; pushButton(PlayerButton::Jump);} } else if(getPositionY()>210){ if(m_isHolding){m_isHolding=false; releaseButton(PlayerButton::Jump);} } }else if(m_isInShip||m_isInBird){ if(getPositionY()<90){ if(!m_isHolding){m_isHolding=true; pushButton(PlayerButton::Jump);} } else if(getPositionY()>300){ if(m_isHolding){m_isHolding=false; releaseButton(PlayerButton::Jump);} } else if(danger(150)){ if(!m_isHolding){m_isHolding=true; pushButton(PlayerButton::Jump);} } }else{ if(danger(85)){ if(!m_isHolding){m_isHolding=true; pushButton(PlayerButton::Jump);} }else{ if(m_isHolding&&m_jumpTimer>0.06f){m_isHolding=false; releaseButton(PlayerButton::Jump);} } } float px=getPositionX(); for(float dd:DEATHS){ if(px<dd&&dd-px<90&&dd-px>0){ if(!m_isHolding){m_isHolding=true; pushButton(PlayerButton::Jump);} } } } PlayerObject::update(dt); }
 void playerDestroyed(bool b){ if(BOT){ DEATHS.push_back(getPositionX()); if(DEATHS.size()>40) DEATHS.erase(DEATHS.begin()); } PlayerObject::playerDestroyed(b); }
};
class $modify(Layer, PlayLayer){ bool init(GJGameLevel* l,bool r,bool d){ if(!PlayLayer::init(l,r,d)) return false; auto lb=CCLabelBMFont::create("GELA EXTREME AI ON","goldFont.fnt"); lb->setPosition({CCDirector::get()->getWinSize().width/2, CCDirector::get()->getWinSize().height-20}); lb->setScale(0.5f); addChild(lb,999); return true; } };
