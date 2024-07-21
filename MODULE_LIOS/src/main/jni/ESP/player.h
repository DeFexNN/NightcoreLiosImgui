vector<void*> players;
vector<void*> myplayers;
vector<void*> monsters;
vector<void*> vehicles;
vector<void*> mines;

bool playerFind(void *player) {
    if (player != NULL) {
        for (int i = 0; i < players.size(); i++) {
            if (player == players[i]) return true;
        }
    }
    return false;
}

bool myplayerFind(void *myplayer) {
    if (myplayer != NULL) {
        for (int i = 0; i < myplayers.size(); i++) {
            if (myplayer == myplayers[i]) return true;
        }
    }
    return false;
}

bool monsterFind(void *monster) {
    if (monster != NULL) {
        for (int i = 0; i < monsters.size(); i++) {
            if (monster == monsters[i]) return true;
        }
    }
    return false;
}

bool vehicleFind(void *vehicle) {
    if (vehicle != NULL) {
        for (int i = 0; i < vehicles.size(); i++) {
            if (vehicle == vehicles[i]) return true;
        }
    }
    return false;
}

bool mineFind(void *mine) {
    if (mine != NULL) {
        for (int i = 0; i < mines.size(); i++) {
            if (mine == mines[i]) return true;
        }
    }
    return false;
}

