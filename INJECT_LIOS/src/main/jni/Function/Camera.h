typedef void Camera;
/*static Camera *get_main() {
    auto Camera_get_main = (Camera *(*)()) (Methods["Camera::get_main"]);
    return Camera_get_main();
}*/

void *vThirdPersonCamera(){
    return *(void**)((uintptr_t)Player + 0x220);
}
Camera *get_main() {
    if(vThirdPersonCamera()){
        return *(void**)((uintptr_t)vThirdPersonCamera() + 0x48);
    }
}

Vector3 WorldToScreen(Vector3 position) {
    auto main = get_main();
    if (main) {
        auto Camera_WorldToScreenPoint = (Vector3 (*)(void *, Vector3)) (Methods["Camera::WorldToScreenPoint"]);
        return Camera_WorldToScreenPoint(main, position);
    }
   //return {0, 0, 0};
}
Vector3 ViewportToWorldPoint(Vector3 position){
    auto main = get_main();
    if (main) {
        auto Camera_ViewportToWorldPoint = (Vector3 (*)(void *, Vector3)) (Methods["Camera::ViewportToWorldPoint"]);
        return Camera_ViewportToWorldPoint(main, position);
    }
    //return {0, 0, 0};
}
