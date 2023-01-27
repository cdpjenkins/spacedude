#include <iostream>
using namespace std;

#include "Shield.hpp"

void Shield::activate() { active_for = 100; }

bool Shield::is_active() { return active_for > 0; }

void Shield::update() {
    if (is_active()) {
        active_for--;
    }
}
