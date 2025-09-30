#include <array>
#include <iostream>

class particule {
private:
    std::array<float, 3> pos;
    float viscosité;
    float vitesse;
    float masse;
    float densité;
    float pression;

public:
    particule(const std::array<float, 3> &pos, float viscosité, float vitesse, float masse, float densité, float pression) {
        this->pos = pos;
        this->viscosité = viscosité;
        this->vitesse = vitesse;
        this->masse = masse;
        this->densité = densité;
        this->pression = pression;
    }
    std::array<float, 3> get(){
        return pos;
    }

};



// Classe 2D : ignore la coordonnée z
class particule2d : public particule {
public:
    particule2d(const std::array<float, 2> &pos2d, float viscosité, float vitesse, float masse, float densité, float pression)
        : particule({pos2d[0], pos2d[1], 0.0f}, viscosité, vitesse, masse, densité, pression) {
        std::cout << "Constructeur particule2d" << std::endl;
    }
};

// Classe 3D
class particule3d : public particule {
public:
    particule3d(const std::array<float, 3> &pos3d, float viscosité, float vitesse, float masse, float densité, float pression)
        : particule(pos3d, viscosité, vitesse, masse, densité, pression) {
        std::cout << "Constructeur particule3d" << std::endl;
    }
};

int main() {
    std::array<float,2> pos2d = {1.0f, 2.0f};
    particule2d p2(pos2d, 0.1f, 5.0f, 1.0f, 1000.0f, 0.5f);

    std::array<float,3> pos3d = {1.0f, 2.0f, 3.0f};
    particule3d p3(pos3d, 0.2f, 6.0f, 2.0f, 1200.0f, 0.8f);
}
