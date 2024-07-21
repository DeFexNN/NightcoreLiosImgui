Vector3 get_position(Transform *instance) {
    auto Transform_get_position = (Vector3 (*)(void *)) (Methods["Transform::get_position"]);
    return Transform_get_position(instance);
}

void *(*set_position)(void *instance, Vector3 value);
