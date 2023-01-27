#ifndef SPACEDUDE_SHIELD_H
#define SPACEDUDE_SHIELD_H

class Shield {
public:
    void activate();
    bool is_active();
    void update();
    int strength() { return active_for; }

private:
    int active_for = 0;
};

#endif //SPACEDUDE_SHIELD_H
