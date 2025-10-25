//
// Created by Israel on 07/10/2025.
//
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <utility>
#include "../include/Exercise2_BackpackGame.h"


class Documento {
private:
    std::string nombre;
    std::string contenido;
public:
    // Constructor que recibe nombre y contenido (la lectura se realiza en MochilaDigital)
    Documento(std::string nombre_, std::string contenido_) : nombre(std::move(nombre_)), contenido(std::move(contenido_)) {}
    [[nodiscard]] const std::string& getNombre() const { return nombre; }
    [[nodiscard]] const std::string& getContenido() const { return contenido; }
};

class MochilaDigital {
private:
    std::vector<Documento> documentos;
public:
    // Agrega un documento leyendo el archivo; retorna true si se pudo leer y agregar
    bool agregarDocumento(const std::string& rutaArchivo) {
        std::ifstream archivo(rutaArchivo);
        if (!archivo.is_open()) {
            return false;
        }
        std::stringstream buffer;
        buffer << archivo.rdbuf();
        std::string contenido = buffer.str();
        documentos.emplace_back(rutaArchivo, contenido);
        return true;
    }

    void mostrarDocumentos() const {
        if (documentos.empty()) {
            std::cout << "La mochila está vacía." << std::endl;
            return;
        }
        for (const auto& doc : documentos) {
            std::cout << "Documento: " << doc.getNombre() << std::endl;
            std::cout << doc.getContenido() << std::endl;
            std::cout << "-------------------" << std::endl;
        }
    }
};


void Exercise2_BackpackGame::run() {
    std::cout << "Ejecutando Ejercicio 2 - Mochila Digital..." << std::endl;
    MochilaDigital mochila;
    const std::string ejemplo = "ejemplo.txt";
    if (mochila.agregarDocumento(ejemplo)) {
        std::cout << "Documento agregado correctamente." << std::endl;
    } else {
        std::cout << "No se pudo agregar el documento '" << ejemplo << "'." << std::endl;
    }

    mochila.mostrarDocumentos();

    cout << endl;

}