#include <iostream>
#include <random>
#include "../../debug.hpp"

#include "fight.hpp"
#include "../constants.hpp"

#define __X event.mouseButton.x
#define __Y event.mouseButton.y

FightView::FightView() :
    View(FIGHT_VIEW_ID)
    , env(FightEnv::Forest)
    , __c(0)
    , __selected(-1)
    , selectingcrea(false)
    , selectingadv(true)
    , __count_before_flyaway(0)
    , can_escape(true)
{

}

bool FightView::load()
{
    sf::Texture bk1;
    if (!bk1.loadFromFile("assets/gui/fight/background1.png"))
        return false;
    this->textures.add("bk1", bk1);

    sf::Texture bk2;
    if (!bk2.loadFromFile("assets/gui/fight/background2.png"))
        return false;
    this->textures.add("bk2", bk2);

    sf::Texture bk3;
    if (!bk3.loadFromFile("assets/gui/fight/background3.png"))
        return false;
    this->textures.add("bk3", bk3);

    sf::Texture gr1;
    if (!gr1.loadFromFile("assets/gui/fight/ground1.png"))
        return false;
    this->textures.add("gr1", gr1);

    sf::Texture gr2;
    if (!gr2.loadFromFile("assets/gui/fight/ground2.png"))
        return false;
    this->textures.add("gr2", gr2);

    sf::Texture gr3;
    if (!gr3.loadFromFile("assets/gui/fight/ground3.png"))
        return false;
    this->textures.add("gr3", gr3);

    sf::Texture tool;
    if (!tool.loadFromFile("assets/gui/fight/bottom.png"))
        return false;
    this->textures.add("tool", tool);

    sf::Texture overlay;
    if (!overlay.loadFromFile("assets/gui/fight/overlay.png"))
        return false;
    this->textures.add("overlay", overlay);

    sf::Texture lifebar;
    if (!lifebar.loadFromFile("assets/gui/fight/lifebar.png"))
        return false;
    this->textures.add("lifebar", lifebar);

    sf::Texture bkg_select;
    if (!bkg_select.loadFromFile("assets/gui/fight/selectui.png"))
        return false;
    this->textures.add("select", bkg_select);

    this->sprites[this->BKG1] = sf::Sprite(this->textures.get("bk1"));
    this->sprites[this->BKG2] = sf::Sprite(this->textures.get("bk2"));
    this->sprites[this->BKG3] = sf::Sprite(this->textures.get("bk3"));
    this->sprites[this->GRD1] = sf::Sprite(this->textures.get("gr1"));
    this->sprites[this->GRD2] = sf::Sprite(this->textures.get("gr2"));
    this->sprites[this->GRD3] = sf::Sprite(this->textures.get("gr3"));
    this->sprites[this->TOOLS] = sf::Sprite(this->textures.get("tool"));
    this->sprites[this->OVERLAY] = sf::Sprite(this->textures.get("overlay"));
    this->sprites[this->LIFEBAR] = sf::Sprite(this->textures.get("lifebar"));
    this->sprites[this->BKG_SELECT] = sf::Sprite(this->textures.get("select"));

    this->sprites[this->BKG1].setPosition(0.0f, 0.0f);
    this->sprites[this->BKG2].setPosition(0.0f, 0.0f);
    this->sprites[this->BKG3].setPosition(0.0f, 0.0f);
    this->sprites[this->OVERLAY].setPosition(0.0f, 0.0f);
    this->sprites[this->TOOLS].setPosition(0.0f, WIN_H - 150.0f);
    this->sprites[this->BKG_SELECT].setPosition(60.0f, 60.0f);

    if (!this->font.loadFromFile(FONTPATH))
        return false;

    setupFont(this->action, this->font, sf::Color::Black, 24)
    this->action.setPosition(5.0f, WIN_H - 155.0f);
    this->action.setString("Ceci est un message d'action");

    setupFont(this->ennemy, this->font, sf::Color::Black, 24)

    setupFont(this->me, this->font, sf::Color::Black, 24)

    return true;
}

void FightView::render(sf::RenderWindow& window)
{
    switch (this->env)
    {
    case FightEnv::CityWithForest:
        window.draw(this->sprites[this->BKG1]);
        this->sprites[this->GRD1].setPosition(289.0f, 166.0f);
        window.draw(this->sprites[this->GRD1]);
        this->sprites[this->GRD1].setPosition(17.0f, 418.0f);
        window.draw(this->sprites[this->GRD1]);
        break;

    case FightEnv::Forest:
        window.draw(this->sprites[this->BKG2]);
        this->sprites[this->GRD2].setPosition(289.0f, 166.0f);
        window.draw(this->sprites[this->GRD2]);
        this->sprites[this->GRD2].setPosition(17.0f, 418.0f);
        window.draw(this->sprites[this->GRD2]);
        break;

    case FightEnv::Sea:
        window.draw(this->sprites[this->BKG3]);
        this->sprites[this->GRD3].setPosition(289.0f, 166.0f);
        window.draw(this->sprites[this->GRD3]);
        this->sprites[this->GRD3].setPosition(17.0f, 418.0f);
        window.draw(this->sprites[this->GRD3]);
        break;

    default:
        window.clear(sf::Color::Blue);
        break;
    }
    window.draw(this->sprites[this->OVERLAY]);
    window.draw(this->sprites[this->TOOLS]);
    window.draw(this->action);
    window.draw(this->ennemy);
    window.draw(this->me);

    if (this->selectingcrea)
    {
        // draw interface to select a crea
        window.draw(this->sprites[this->BKG_SELECT]);

        if (this->selectingadv)
        {
            for (int i=0; i < this->adv.size(); i++)
            {
                window.draw(this->texts.get(to_string<int>(i) + this->dex->getName(this->adv[i]->getId())));
            }
        }
        else
        {
            for (int i=0; i < this->equip->getSize(); i++)
            {
                window.draw(this->texts.get(to_string<int>(i) + this->equip->getCrea(i)->getName()));
            }
        }
    }
}

int FightView::process_event(sf::Event& event, sf::Time elapsed)
{
    int new_view = -1, m = 0;

    switch(event.type)
    {
    case sf::Event::KeyPressed:
        switch(event.key.code)
        {
        default:
            break;
        }
        break;

    case sf::Event::MouseButtonPressed:
        switch(event.mouseButton.button)
        {
        case sf::Mouse::Button::Left:
            if (!this->selectingcrea)
            {
                if (__Y >= 490 + 75 && __Y <= 490 + 125)
                {
                    /*if (__X >= 5 && __X <= 157)
                    {
                        // attack button
                    }
                    else*/ if (__X >= 164 && __X <= 316)
                    {
                        // equip button
                        new_view = MYCREATURES_VIEW_ID;
                        OMessenger::setlock(MYCREATURES_VIEW_ID);
                    }
                    else if (__X >= 323 && __X <= 475)
                    {
                        // bag button
                        new_view = INVENTORY_VIEW_ID;
                        OMessenger::setlock(INVENTORY_VIEW_ID);
                    }
                    else if (__X >= 480 && __X <= 632 && !this->__count_before_flyaway)
                    {
                        // fly away button
                        this->__count_before_flyaway = 480;
                        if (this->can_escape)
                            this->action.setString("Vous vous �chapez prestement ...");
                        else
                            this->action.setString("Vous ne pouvez pas vous �chaper !");
                    }
                }
            }
            else
            {
                // handle clic in
                if (__X >= X_TEXT_SELCREA_UI && __X <= MX_TEXT_SELCREA_UI)
                {
                    if (__Y >= Y_TEXT_SELCREA_UI && __Y <= MY_TEXT_SELCREA_UI)
                    {
                        this->__selected = (__Y - Y_TEXT_SELCREA_UI) / YS_TEXT_SELCREA_UI;
                        m = (this->selectingadv) ? this->adv.size() : this->equip->getSize();
                        if (this->__selected >= 0 && this->__selected < m)
                            this->selectingcrea = false;
                        else
                            this->__selected = -1;
                    }
                }
            }
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }

    if (this->__count_before_flyaway == 1)
    {
        this->__count_before_flyaway = 0;
        if (this->can_escape)
            return DEFAULT_VIEW_ID;
        else
            return -1;
    }
    return new_view;
}

void FightView::update(sf::RenderWindow& window, sf::Time elapsed)
{
    if (this->__count_before_flyaway)
        this->__count_before_flyaway -= 1;

    if (OMessenger::get().target_view == this->getId())
    {
        int c = 0;
        switch (OMessenger::get().type)
        {
        case ObjType::capture:
            this->__c = OMessenger::get().value;
            break;

        default:
            // should never land here
            DebugLog(SH_WARN, "We land here but we should'nt. What type of object is it ? => " << OMessenger::get().type);
            break;
        }

        this->selectingcrea = true;
        this->selectingadv = true;

        if (this->__c && this->__selected != -1)
        {
            OMessenger::empty();
            std::mt19937 rng;
            rng.seed(std::random_device()());
            std::uniform_int_distribution<std::mt19937::result_type> distgotit(0, 100);
            if (distgotit(rng) >= this->__c)
            {
                // we got the creature let's register it
                this->dex->register_capture(this->adv[this->__selected]->getId());
                if (!this->equip->add_creature(this->adv[this->__selected]))
                {
                    this->pc->add_creature(this->adv[this->__selected]);
                    this->action.setString("La cr�ature a �t� envoy�e au PC");
                }
                else
                    this->action.setString("La cr�ature a �t� ajout�e � l'�quipe !");
            }
            else
                this->action.setString("La cr�ature n'a pas pu �tre attrap�e ...");
            this->__c = 0;
            this->__selected = -1;
        }
    }
}

void FightView::encounter()
{
    if (this->dex)
    {
        for (int i=0; i < this->adv.size(); i++)
            this->dex->register_viewed(this->adv[i]->getId());
    }
}

void FightView::set_env(FightEnv new_env)
{
    this->env = new_env;
}

void FightView::set_dex(Dex* _dex)
{
    this->dex = _dex;
}

void FightView::set_equip(Equip* eq)
{
    this->equip = eq;
}

void FightView::set_pc(Equip* pc)
{
    this->pc = pc;
}

void FightView::set_crealoader(CreaturesLoader* creal)
{
    this->crealoder = creal;
}

void FightView::start()
{
    this->adv.clear();

    // generate adv
    float moy_equip = 0.0f;
    for (int i=0; i < this->equip->getSize(); i++)
    {
        sf::Text _t1;
        setupFont(_t1, this->font, sf::Color::Black, 24)
        _t1.setString(this->equip->getCrea(i)->getName());
        _t1.setPosition(X_TEXT_SELCREA_UI, Y_TEXT_SELCREA_UI + i * YS_TEXT_SELCREA_UI);
        this->texts.add(to_string<int>(i) + this->equip->getCrea(i)->getName(), _t1);

        moy_equip += this->equip->getCrea(i)->getLevel();
    }
    moy_equip /= float(this->equip->getSize());

    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist1(int(moy_equip), moy_equip + 10);
    int _x_ = dist1(rng);
    std::uniform_int_distribution<std::mt19937::result_type> dist2(_x_, _x_ + 4);
    std::uniform_int_distribution<std::mt19937::result_type> distid(0, this->dex->getMaxId());
    std::uniform_int_distribution<std::mt19937::result_type> diststype(0, SortilegeType::Count - 1);
    std::uniform_int_distribution<std::mt19937::result_type> distcd(3, 6);
    std::uniform_int_distribution<std::mt19937::result_type> disttargets(2, this->equip->getSize());

    for (int i=0; i < this->equip->getMaxSize(); i++)
    {
        Creature* crea = new Creature();
        int  id = distid(rng)
              , _t = this->dex->getInfo(id).type
              ,  _s = this->dex->getInfo(id).stade
              , _st = diststype(rng)  // SortilegeType::UniqueTargetAdvDamage
              , level = dist2(rng)
              , life = 2 * level + int(distcd(rng))  // mlife = life
              , pp = Creature::calculatePPFromLevel(level) // mpp = pp
              , scd = distcd(rng)  // cooldown for the sortilege
              , sdmg = ceil(scd * 0.125 * level + 1)  // damages for the sortilege
              , stargets = disttargets(rng)  // targets for the sortilege
              , atk = Creature::calculateStatFromLevel(level)  // attack of the creature
              , def = Creature::calculateStatFromLevel(level);  // defense
        long int exp = Creature::calculateExpFromLevel(level);

        Type t = static_cast<Type>(_t % 8);
        State s = static_cast<State>(_s % 4);
        SortilegeType st = static_cast<SortilegeType>(_st % 14);

        crea->load(id, t, atk, def, life, life, pp, pp, this->dex->getName(id), s, level, exp, st, sdmg, scd, stargets);
        this->adv.push_back(crea);

        sf::Text _t2;
        setupFont(_t2, this->font, sf::Color::Black, 24)
        _t2.setString(this->dex->getName(id));
        _t2.setPosition(X_TEXT_SELCREA_UI, Y_TEXT_SELCREA_UI + i * YS_TEXT_SELCREA_UI);
        this->texts.add(to_string<int>(i) + this->dex->getName(id), _t2);
    }

    this->encounter();
}

void FightView::set_escape(bool v)
{
    this->can_escape = v;
}

FightView::~FightView()
{
    CLEAR_PTR_VECT(this->adv)
    this->dex = NULL;
    this->equip = NULL;
    this->pc = NULL;
    this->crealoder = NULL;
}
