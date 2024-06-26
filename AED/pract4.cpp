#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Estructura para almacenar la información de un país
struct pais {
  string nombre;
  string idioma;
  int poblacion;
};

// Función para leer el archivo CSV y devolver una lista de estructuras pais
vector<pais> leer_archivo(const string &archivo) {
  // Abrir el archivo
  ifstream fp("Paises.txt");
  if (!fp.is_open()) {
    throw runtime_error("Error al abrir el archivo.");
  }

  // Declarar una lista para almacenar los países
  vector<pais> paises;

  // Leer el archivo
  string linea;
  while (getline(fp, linea)) {
    // Separar la línea en campos
    vector<string> campos;
    stringstream ss(linea);
    while (getline(ss, linea, ',')) {
      campos.push_back(linea);
    }

    // Agregar el país a la lista
    pais pais;
    pais.nombre = campos[0];
    pais.idioma = campos[1];
    pais.poblacion = stoi(campos[2]);
    paises.push_back(pais);
  }

  // Cerrar el archivo
  fp.close();

  // Devolver la lista de países
  return paises;
}

// Función para ordenar una lista de países por población
void ordenar_paises_por_poblacion(vector<pais> &paises) {
  // Implementar el algoritmo de ordenamiento burbuja
  for (int i = 0; i < paises.size() - 1; i++) {
    for (int j = 0; j < paises.size() - i - 1; j++) {
      if (paises[j].poblacion > paises[j + 1].poblacion) {
        pais temp = paises[j];
        paises[j] = paises[j + 1];
        paises[j + 1] = temp;
      }
    }
  }
}

// Función para buscar un país por su nombre utilizando búsqueda secuencial
pais *buscar_pais_secuencial(vector<pais> &paises, const string &nombre) {
  // Iterar sobre la lista de países
  for (pais &pais : paises) {
    // Comparar el nombre del país
    if (pais.nombre == nombre) {
      // Devolver el país
      return &pais;
    }
  }

  // El país no se encontró
  return nullptr;
}

// Función para mostrar la información de un país
void mostrar_pais(pais *pais) {
  cout << "País: " << pais->nombre << endl;
  cout << "Idioma: " << pais->idioma << endl;
  cout << "Población: " << pais->poblacion << endl;
}

// Función principal
int main() {
  // Declarar una variable para almacenar la opción del menú
  int opcion;

  // Declarar una variable para almacenar el nombre del país
  string nombre_pais;

  // Declarar una variable para almacenar el idioma del país
  string idioma_pais;

  // Declarar una variable para almacenar la población del país
  int poblacion_pais;

  // Declarar una variable para almacenar la cantidad total de población que habla el idioma
  int poblacion_total = 0;

  // Declarar una lista para almacenar los países
  vector<pais> paises = leer_archivo("paises.csv");

  // Imprimir el menú
    cout << endl;
    cout << "Menú:" << endl;
    cout << "1. Buscar país por nombre" << endl;
    cout << "2. Buscar países por idioma" << endl;
    cout << "3. Mostrar cantidad total de población que habla el idioma" << endl;
    cout << "4. Mostrar países en orden descendente por población" << endl;
    cout << "5. Salir" << endl;
    cout<< "Seleccione una opcion"<<endl;
	}
    