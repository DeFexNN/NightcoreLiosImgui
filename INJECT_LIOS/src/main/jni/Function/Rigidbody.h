typedef void Rigidbody;
Vector3 (*get_velocity)(void *point);
Rigidbody (*set_velocity)(void *point, Vector3 pos);
Rigidbody (*set_isKinematic)(void *point, bool value);
Rigidbody (*set_detectCollisions)(void *point, bool value);
Vector3 (*get_posRigidbody)(void *point);
Rigidbody (*MovePosition)(void *point, Vector3 pos);
Rigidbody (*AddForce)(void *point, Vector3 force);
Rigidbody (*AddForceAtPosition)(void *point, Vector3 force, Vector3 position, int mode);

