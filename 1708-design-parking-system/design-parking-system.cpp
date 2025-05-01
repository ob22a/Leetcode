class ParkingSystem {
public:
    int availableSize[3];
    ParkingSystem(int big, int medium, int small) {
        availableSize[0]=big;
        availableSize[1]=medium;
        availableSize[2]=small;
    }
    
    bool addCar(int carType) {
        return availableSize[carType-1]-->0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */