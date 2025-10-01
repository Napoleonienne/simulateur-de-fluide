#pragma once
#include <glad/glad.h>
#include <vector>

class Triangle {
public:
    // Constructeur : ajoute les sommets du triangle à la liste statique
    Triangle(float x, float y, float z, float largeur, float hauteur);

    // Prépare VAO/VBO (à appeler une seule fois avant le draw)
    static void init();

    // Dessine tous les triangles
    static void draw();

    // Libère les ressources GPU
    static void cleanup();

private:
    // Liste statique de tous les sommets
    static std::vector<float> totale_vertice;

    // Compteur d'instances
    static unsigned int compteur;

    // VAO et VBO partagés
    static GLuint VAO;
    static GLuint VBO;
};
