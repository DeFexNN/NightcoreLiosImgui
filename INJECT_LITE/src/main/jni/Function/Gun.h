void (*_Gun_DoOneShoot)(long thisPointer);
void Gun_DoOneShoot(long thisPointer) {
    if (GunData.FastShoot && thisPointer != 0) {
        int shootNumber = std::min(GunData.ShootNumber, 10);
        for (int i = 0; i < shootNumber; ++i) {
            _Gun_DoOneShoot(thisPointer);
        }
    }
    _Gun_DoOneShoot(thisPointer);
}
void (*_Gun_CaulateMoveAimRadius)(long point);
void Gun_CaulateMoveAimRadius(long point) {
    if(!GunData.NoRecoil && point != 0){
        _Gun_CaulateMoveAimRadius(point);
    }
}
void (*_Gun_CaulateShootAimRadius)(long point);
void Gun_CaulateShootAimRadius(long point) {
    if(!GunData.NoRecoil && point != 0){
        _Gun_CaulateShootAimRadius(point);
    }
}
void (*_Gun_DoOneShootRecoil)(long point);
void Gun_DoOneShootRecoil(long point){
    if(!GunData.NoRecoil && point != 0){
        _Gun_DoOneShootRecoil(point);
    }
}
