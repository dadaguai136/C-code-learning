typedef struct {
    int b, m, s;
} ParkingSystem;

ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem* ret = malloc(sizeof(ParkingSystem));
    ret->b = big;
    ret->m = medium;
    ret->s = small;
    return ret;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    if (carType == 1) {
        if (obj->b > 0) {
            obj->b--;
            return true;
        }
    } else if (carType == 2) {
        if (obj->m > 0) {
            obj->m--;
            return true;
        }
    } else if (carType == 3) {
        if (obj->s > 0) {
            obj->s--;
            return true;
        }
    }
    return false;
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
}
