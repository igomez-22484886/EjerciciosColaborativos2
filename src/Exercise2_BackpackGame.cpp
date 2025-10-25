//
// Created by Israel on 07/10/2025.
//
using namespace std;
#include <fstream>
#include <iostream>
#include <filesystem>

class Exercise2_BackpackGame {
private:
    std::string nombre;
    std::string contenido;

public:
    Exercise2_BackpackGame(std::string nom) : nombre(nom) {}

    bool cargarDesdeArchivo(std::string ruta) {
        std::ifstream archivo(ruta);
        if (!archivo.is_open()) return false;

        std::string linea;
        contenido = "";
        while (getline(archivo, linea)) {
            contenido += linea + "\n";
        }
        archivo.close();
        return true;
    }

    void mostrarContenido() {
        std::cout << "Documento: " << nombre << std::endl;
        std::cout << contenido << std::endl;
    }

    void run();
};

class MochilaDigital {
private:
    Exercise2_BackpackGame* documentos[20]; // Array para máximo 20 documentos
    int numDocumentos;

public:
    MochilaDigital() : numDocumentos(0) {}

    bool agregarDocumento(Exercise2_BackpackGame *doc) {
        if (numDocumentos < 20) {
            documentos[numDocumentos++] = doc;
            return true;
        }
        return false;
    }

    void mostrarMochila() {
        for (int i = 0; i < numDocumentos; i++) {
            documentos[i]->mostrarContenido();
        }
    }
};


void Exercise2_BackpackGame::run() {
    std::cout << "Ejecutando Ejercicio 2 - Mochila Digital..." << std::endl;
    MochilaDigital mochila;
    Exercise2_BackpackGame* ejemplo = new Exercise2_BackpackGame(std::string("ejemplo.txt"));
    std::cout << "Cargando archivo `ejemplo.txt`..." << std::endl;
    if (!ejemplo->cargarDesdeArchivo(std::string("ejemplo.txt"))) {
        std::cout << "No se pudo cargar el archivo `ejemplo.txt`." << std::endl;
    }
    mochila.agregarDocumento(ejemplo);
    std::cout << "Mochila actual:" << std::endl;
    mochila.mostrarMochila();

    std::cout << "cwd: " << std::filesystem::current_path() << std::endl;
    std::cout << "existe `ejemplo.txt`: " << std::filesystem::exists("ejemplo.txt") << std::endl;

    std::cout << std::endl;
}
