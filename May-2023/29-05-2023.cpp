// C++ Solution
class ParkingSystem {
    using VI = vector<int>;
    VI A;
public:
    ParkingSystem(int a, int b, int c) : A{ 0, a, b, c } {}
    bool addCar(int x) {
        if (!A[x])
            return false;
        --A[x];
        return true;
    }
};
/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */