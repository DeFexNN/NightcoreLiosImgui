typedef void Camera;
static Camera *get_main() {
    auto Camera_get_main = (Camera *(*)()) (Methods["Camera::get_main"]);
    return Camera_get_main();
}

Vector3 WorldToScreen(Vector3 position) {
    auto main = get_main();
    if (main) {
        auto Camera_WorldToScreenPoint = (Vector3 (*)(void *, Vector3)) (Methods["Camera::WorldToScreenPoint"]);
        return Camera_WorldToScreenPoint(main, position);
    }
    return {0, 0, 0};
}
Vector3 ViewportToWorldPoint(Vector3 position){
    auto main = get_main();
    if (main) {
        auto Camera_ViewportToWorldPoint = (Vector3 (*)(void *, Vector3)) (Methods["Camera::ViewportToWorldPoint"]);
        return Camera_ViewportToWorldPoint(main, position);
    }
    return {0, 0, 0};
}
