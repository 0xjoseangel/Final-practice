/**
 * @file ruta_aerea.cpp
 * @author Jesús Rodríguez
 * @author José Ángel Carretero
 * @brief El programa `ruta_aerea.cpp` es una aplicación que utiliza diversas clases y funciones
 * para visualizar rutas aéreas en un mapa del mundo. El proceso comienza leyendo información sobre
 * países desde un archivo, así como una imagen representativa del mapa mundial. Además, se carga una
 * imagen que simboliza un avión. Luego, se lee un conjunto de rutas aéreas desde un archivo de almacenamiento
 * de rutas. El usuario selecciona una ruta específica mediante un código. La aplicación utiliza esta ruta para
 * trazar una trayectoria en el mapa del mundo, superponiendo las banderas de los países por los cuales pasa la
 * ruta. La posición del avión se actualiza a medida que avanza por la ruta, creando así una representación visual
 * de un vuelo. El programa emplea técnicas de rotación de imágenes para orientar adecuadamente la representación
 * del avión en la dirección de vuelo. Además, utiliza coordenadas geográficas para posicionar las banderas de
 * los países en sus ubicaciones correspondientes en el mapa. Al finalizar la visualización de la ruta seleccionada,
 * el programa genera una imagen resultante y la guarda en un archivo con el mismo código de la ruta y la extensión ".ppm".
 * @date 2023-12-20
 * 
 */
#include <iostream>
#include <fstream>
#include <cmath>
#include "imagen.h"
#include "Pais.h"
#include "Paises.h"
#include "Almacen_Rutas.h"
using namespace std;

/**
 * @brief Pinta la trayectoria de un avión en una imagen, teniendo en cuenta la posición actual
 * y la posición anterior en la ruta.
 * @param f1: fila de la posición anterior
 * @param f2: fila de la posición actual
 * @param c1: columna de la posición anterior
 * @param c2: columna de la posición actual
 * @param I: imagen sobre la cual se pinta la trayectoria
 * @param avion: imagen del avión
 * @param mindisf: distancia mínima en filas para activar el pintado
 * @param mindisc: distancia mínima en columnas para activar el pintado
 */
void Pintar(int f1, int f2, int c1, int c2, Imagen &I, const Imagen &avion, int mindisf, int mindisc);
/**
 * @brief Obtiene una nueva imagen que es la versión rotada de una imagen de entrada
 * @param Io: imagen de entrada
 * @param angulo: angulo a rotar la imagen de entrada. Debe estar en radianes.
 * @return Una nueva imagen que es la versión rotada de Io.
 * */
Imagen Rota(const Imagen &Io, double angulo);

/**
 * @brief Calcula la columna correspondiente en el mapa para una longitud dada.
 * @param totalColumnas: número total de columnas en el mapa
 * @param longitud: longitud para la cual se quiere calcular la columna
 * @return La columna correspondiente en el mapa.
 */
int GetMapCol(int totalColumnas, int longitud);

/**
 * @brief Calcula la fila correspondiente en el mapa para una latitud dada.
 * @param totalFilas: número total de filas en el mapa
 * @param latitud: latitud para la cual se quiere calcular la fila
 * @return La fila correspondiente en el mapa.
 */
int GetMapRow(int totalFilas, int latitud);
int main(int argc, char *argv[])
{
  if (argc != 7)
  {
    cout << "Los parametros son:" << endl;
    cout << "1.-Fichero con la informacion de los paises" << endl;
    cout << "2.-Nombre de la imagen con el mapa del mundo" << endl;
    cout << "3.-Directorio con las banderas" << endl;
    cout << "4.-Fichero con el almacen de rutas" << endl;
    cout << "5.- Nombre de la imagen con el avion" << endl;
    cout << "6.- Nombre de la imagen de la mascara del avion" << endl;
    return 1; // Salir con código de error
  }

  // Lectura de información de países desde el archivo
  Paises Pses;
  ifstream f(argv[1]);
  f >> Pses;

  // Lectura de la imagen del mapa del mundo
  Imagen I;
  I.LeerImagen(argv[2]);

  // Lectura de la imagen del avión
  Imagen avion;
  avion.LeerImagen(argv[5], argv[6]);

  // Lectura de las rutas desde el archivo
  Almacen_Rutas Ar;
  f.close();
  f.open(argv[4]);
  f >> Ar;

  // Impresión de las rutas en la consola
  cout << "Las rutas: " << endl << Ar;
  
  // Lectura de la ruta seleccionada por el usuario
  cout << "Dime el codigo de una ruta" << endl;
  string a;
  cin >> a;
  Ruta R = Ar.GetRuta(a);

  // Iteradores movernos sobre la ruta
  Ruta::iterator it, auxItRuta;
  Paises::iterator auxItPais = Pses.end();
  Paises::iterator ip = Pses.end();
  Imagen imagenAux;
  int posi_ini, posj_ini;

  it = R.begin();
  while (it != R.end())
  {
    Punto pto = (*it);
    auxItPais = ip;
    ip = Pses.find(pto);

    // Construcción del nombre de la bandera
    string name = (*ip).GetBandera();
    string n_com = argv[3] + name;

    // Lectura de la imagen de la bandera
    Imagen imagenBandera;
    imagenBandera.LeerImagen(n_com.c_str());

    cout << (*ip).GetPais() << " ";
    // Cálculo de las coordenadas en la imagen del mapa
    int x = GetMapCol(I.num_cols(), pto.GetLongitud());
    int y = GetMapRow(I.num_filas(), pto.GetLatitud());
    if (auxItPais != Pses.end())
    {
      // Pintado de la trayectoria del avión
      int x_old = GetMapCol(I.num_cols(), (*auxItRuta).GetLongitud());
      int y_old = GetMapRow(I.num_filas(), (*auxItRuta).GetLatitud());
      Pintar(y_old - avion.num_filas() / 2, y - avion.num_filas() / 2, x_old - avion.num_cols() / 2, x - avion.num_cols() / 2, I, avion, 50, 50);
    }
    // Superposición de la bandera en la posición actual
    I.PutImagen(y - imagenBandera.num_filas() / 2, x - imagenBandera.num_cols() / 2, imagenBandera, BLENDING);

    // Superposición de la imagen anterior en la posición anterior
    if (ip != Pses.begin())
    {
      I.PutImagen(posi_ini - imagenAux.num_filas() / 2, posj_ini - imagenAux.num_cols() / 2, imagenAux, BLENDING);
    }

    // Actualización de variables auxiliares
    imagenAux = imagenBandera;
    posi_ini = y;
    posj_ini = x;
    auxItRuta = it;
    ++it;
  }

  // Impresión de la imagen final
  cout << endl;
  string salida = a + ".ppm";
  I.EscribirImagen(salida.c_str());

  return 0;
}

int GetMapCol(int totalColumnas, int longitud) 
{
  // Formula transparencia 30
  return (int)((totalColumnas / 360.0) * (180 + longitud));
}
int GetMapRow(int totalFilas, int latitud) 
{
  // Formula transparencia 30
  return (int)((totalFilas / 180.0) * (90 - latitud));
}

Imagen Rota(const Imagen &Io, double angulo)
{
  double rads = angulo;
  double coseno = cos(angulo);
  double seno = sin(angulo);
  // Para obtener las dimensiones de la imagen
  int rcorners[4], ccorners[4];
  int newimgrows, newimgcols;
  double new_row_min, new_col_min, new_row_max, new_col_max;
  double inter, inter1;
  rcorners[0] = 0;
  rcorners[1] = 0;
  ccorners[0] = 0;
  ccorners[2] = 0;
  rcorners[2] = Io.num_filas() - 1;
  rcorners[3] = Io.num_filas() - 1;
  ccorners[1] = Io.num_cols() - 1;
  ccorners[3] = Io.num_cols() - 1;
  new_row_min = 0;
  new_col_min = 0;
  new_row_max = 0;
  new_col_max = 0;
  newimgrows = 0;
  newimgcols = 0;
  for (int count = 0; count < 4; count++)
  {

    inter = rcorners[count] * coseno + ccorners[count] * seno;
    if (inter < new_row_min)
      new_row_min = inter;
    if (inter > new_row_max)
      new_row_max = inter;
    inter1 = -rcorners[count] * seno + ccorners[count] * coseno;
    if (inter1 < new_col_min)
      new_col_min = inter1;
    if (inter1 > new_col_max)
      new_col_max = inter1;
  }

  newimgrows = (unsigned)ceil((double)new_row_max - new_row_min);
  newimgcols = (unsigned)ceil((double)new_col_max - new_col_min);

  Imagen Iout(newimgrows, newimgcols);
  for (int rows = 0; rows < newimgrows; rows++)
  {
    for (int cols = 0; cols < newimgcols; cols++)
    {
      float oldrowcos = ((float)rows + new_row_min) * cos(-rads);
      float oldrowsin = ((float)rows + new_row_min) * sin(-rads);
      float oldcolcos = ((float)cols + new_col_min) * cos(-rads);
      float oldcolsin = ((float)cols + new_col_min) * sin(-rads);
      float old_row = oldrowcos + oldcolsin;
      float old_col = -oldrowsin + oldcolcos;
      old_row = ceil((double)old_row);
      old_col = ceil((double)old_col);
      if ((old_row >= 0) && (old_row < Io.num_filas()) &&
          (old_col >= 0) && (old_col < Io.num_cols()))
      {
        Iout(rows, cols) = Io(old_row, old_col);
      }
      else
      {
        Iout(rows, cols).r = Iout(rows, cols).g = Iout(rows, cols).b = 255;
        Iout(rows, cols).transp = 0;
      }
    }
  }
  return Iout;
}

void Pintar(int f1, int f2, int c1, int c2, Imagen &I, const Imagen &avion, int mindisf, int mindisc)
{

  int fila, col;
  if (abs(f2 - f1) >= mindisf || abs(c2 - c1) >= mindisc)
  {
    if (c1 != c2)
    {
      double a, b;
      a = double(f2 - f1) / double(c2 - c1);
      b = f1 - a * c1;
      col = (int)(c1 + c2) / 2;
      fila = (int)rint(a * col + b);
    }
    else
    {
      col = c1;
      fila = (f1 + f2) / 2;
    }

    double angulo = atan2((f2 - f1), (c2 - c1));
    Imagen Irota = Rota(avion, angulo);
    I.PutImagen(fila, col, Irota); // pensar si debe ser opaco o blending

    angulo = atan2((f2 - fila), (c2 - col));
    Irota = Rota(avion, angulo);
    I.PutImagen(f2, c2, Irota); // pensar si debe ser opaco o blending
    angulo = atan2((fila - f1), (col - c1));
    Irota = Rota(avion, angulo);
    I.PutImagen(f1, c1, Irota); // pensar si debe ser opaco o blending
  }
}