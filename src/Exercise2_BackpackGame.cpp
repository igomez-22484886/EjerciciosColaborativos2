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
    Exercise2_BackpackGame(std::string nom) : nombre(std::move(nom)) {}

    bool cargarDesdeArchivo(const std::string& ruta) {
        std::ifstream archivo(ruta);
        if (!archivo.is_open()) return false;

        std::string linea;
        contenido.clear();
        while (getline(archivo, linea)) {
            contenido += linea + "\n";
        }
        archivo.close();
        return true;
    }

    void mostrarContenido() const {
        std::cout << "Document: " << nombre << std::endl;
        std::cout << contenido << std::endl;
    }

    void run();
};

class MochilaDigital {
private:
    Exercise2_BackpackGame* documentos[20];
    int numDocumentos;

public:
    MochilaDigital() : numDocumentos(0) {}

    bool agregarDocumento(Exercise2_BackpackGame* doc) {
        if (numDocumentos < 20) {
            documentos[numDocumentos++] = doc;
            return true;
        }
        return false;
    }

    void mostrarMochila() const {
        for (int i = 0; i < numDocumentos; i++) {
            documentos[i]->mostrarContenido();
        }
    }
};


void Exercise2_BackpackGame::run() {
    std::cout << "Running Exercise 2 - Digital Backpack..." << std::endl;

    const std::string nombreArchivo = "ejemplo.txt";

    // 🔹 If the file doesn't exist, create it automatically
    if (!std::filesystem::exists(nombreArchivo)) {
        std::ofstream nuevoArchivo(nombreArchivo);
        if (nuevoArchivo.is_open()) {
            nuevoArchivo << "This is an example file created automatically.\n";
            nuevoArchivo << "You can edit or replace it anytime.\n";
            nuevoArchivo.close();
            std::cout << "File '" << nombreArchivo << "' did not exist and has been created automatically.\n";
        } else {
            std::cerr << "Error: could not create file '" << nombreArchivo << "'.\n";
            return;
        }
    }

    MochilaDigital mochila;
    auto* ejemplo = new Exercise2_BackpackGame(nombreArchivo);

    std::cout << "Loading file '" << nombreArchivo << "'..." << std::endl;
    if (!ejemplo->cargarDesdeArchivo(nombreArchivo)) {
        std::cout << "Could not load file '" << nombreArchivo << "'." << std::endl;
    }

    mochila.agregarDocumento(ejemplo);

    std::cout << "Current backpack:" << std::endl;
    mochila.mostrarMochila();

    std::cout << "Current directory: " << std::filesystem::current_path() << std::endl;
    std::cout << "File '" << nombreArchivo << "' exists: "
              << std::filesystem::exists(nombreArchivo) << std::endl;

    std::cout << std::endl;
}