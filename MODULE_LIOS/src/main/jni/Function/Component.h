typedef void Component;
Component *get_transform(void *player) {
    auto Component_get_transform = (Component *(*)(void *)) (Methods["Component::get_transform"]);
    return Component_get_transform(player);
}

GameObject *get_gameObject(void *point){
    auto Component_get_gameObject = (void *(*)(void *)) (Methods["Component::get_gameObject"]);
    return Component_get_gameObject(point);
}
