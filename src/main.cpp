#include "M5StickCPlus2.h"
#include "menu.h"

Menu menu;

void setup() {
    auto cfg = M5.config();
    M5.begin(cfg);
    Serial.begin(115200);

    menu.setup();
    menu.addCategory("Wireless");
    menu.addCategory("Tools");
}

void loop() {
    menu.update();
}

