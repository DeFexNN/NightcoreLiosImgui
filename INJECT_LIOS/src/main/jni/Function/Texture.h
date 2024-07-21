void (*_TreeObject_AddToScene)(long thisPointer);
void TreeObject_AddToScene(long thisPointer) {
    if (Texture.tree) { } else { _TreeObject_AddToScene(thisPointer); }
}

void (*_GrassObject_AddToScene)(long thisPointer);
void GrassObject_AddToScene(long thisPointer) {
    if (Texture.grass) { } else { _GrassObject_AddToScene(thisPointer); }
}

void (*_ThingsObject_AddToScene)(long thisPointer);
void ThingsObject_AddToScene(long thisPointer) {
    if (Texture.things) { } else { _ThingsObject_AddToScene(thisPointer); }
}
