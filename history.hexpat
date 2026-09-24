#include <std/mem>

bitfield DateTime {
    day: 5;
    month: 4;
    yearsSince2000: 7;
};

struct Game {
    char Id[0x10] [[color("000080")]];
    u8 GameBootCounter [[color("800000")]];
    u8 NearbyTowerToggles [[color("800080")]];
    u8 MaxNearbyTowers [[color("808080")]];
    padding[1];
    DateTime DateTime;
};

Game Games[while(!std::mem::eof())] @ 0x00;