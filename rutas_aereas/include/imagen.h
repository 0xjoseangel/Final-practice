/*!
 * @file imagen.h
 * @brief Cabecera para la clase Imagen
 */

#include <string>

#ifndef __IMAGEN__H
#define __IMAGEN_H

/**
 * @brief Enumeración para definir los tipos de pegado.
 *
 * Se utiliza para especificar el tipo de pegado al insertar una imagen en otra.
 */
enum Tipo_Pegado {OPACO, BLENDING};

using namespace std;

/**
 * @brief Estructura para representar un píxel en una imagen.
 *
 * Esta estructura almacena los componentes de color (rojo, verde, azul) y un componente de transparencia.
 */
struct Pixel{
    unsigned char r, g, b; /**< Componentes de color (rojo, verde, azul). */
    unsigned char transp; /**< Componente de transparencia (0 significa no transparente, 255 significa completamente transparente). */
};  

/**
 * @brief Clase para representar una imagen en formato PPM.
 *
 * La clase proporciona métodos para la manipulación y gestión de imágenes.
 */
class Imagen{
private:
    Pixel ** data; /**< Matriz dinámica para almacenar los píxeles de la imagen. */
    int nf, nc; /**< Número de filas (nf) y columnas (nc) de la imagen. */

    /**
      @brief Copia una imagen.
      @param orig Referencia a la imagen original que se va a copiar.
      @pre Asume que no hay memoria reservada o se ha llamado antes a Destroy().
      @pre Asume this != &orig.
    **/
    void Copiar(const Imagen &I);   

    /**
      @brief Reserva o copia en memoria una imagen.
      @param nrows Número de filas que tendrá la imagen.
      @param ncols Número de columnas que tendrá la imagen.
      @param buffer Puntero a un buffer de datos con los que rellenar los píxeles de la imagen. Por defecto, 0.
      @pre nrows >= 0 y ncols >= 0
      @post Reserva memoria para almacenar la imagen y la prepara para usarse.
    **/
    void Allocate(int nrows=0, int ncols=0);  

    /**
     * @brief Borra una imagen.
     *
     * Libera la memoria reservada en la que se almacenaba la imagen que llama a la función.
     * Si la imagen estaba vacía no hace nada.
     */
    void Borrar();

public:
    /**
     * @brief Clase iterador para la clase Imagen.
     *
     * Proporciona un iterador para recorrer la matriz de píxeles de la imagen.
     */
    class iteradorImagen {
    private:
        Pixel * ptr;
        Imagen& imagen;  
        int currentRow;     
        int currentCol;

    public:
        iteradorImagen(Imagen& img);
        iteradorImagen(Imagen& img, Pixel* start, int cols, int fils); // hace más cómodo el end()
        iteradorImagen(const iteradorImagen &v);
        iteradorImagen & operator=(const iteradorImagen& orig);
        Pixel & operator*() const;
        iteradorImagen & operator++();
        iteradorImagen & operator--();
        bool operator!=(const iteradorImagen& v) const;
        bool operator==(const iteradorImagen& v) const;
        // Get set
        int getCurrentRow() const;
        int getCurrentCol() const;
    };

    /**
     * @brief Clase iterador constante para la clase Imagen.
     *
     * Proporciona un iterador constante para recorrer la matriz de píxeles de la imagen.
     */
    class const_iteradorImagen {
    private:
        const Pixel *ptr;
        const Imagen &imagen;
        int currentRow;
        int currentCol;

    public:
        const_iteradorImagen(const Imagen &img);
        const_iteradorImagen(const Imagen &img, Pixel *start, int cols, int fils);
        const_iteradorImagen(const const_iteradorImagen &v);
        const Pixel &operator*() const;
        const_iteradorImagen &operator++();
        const_iteradorImagen &operator--();
        bool operator!=(const const_iteradorImagen &v) const;
        bool operator==(const const_iteradorImagen &v) const;
        // Get set
        int getCurrentRow() const;
        int getCurrentCol() const;
    };

    /**
     * @brief Constructor por defecto de la clase Imagen.
     *
     * Crea una imagen vacía sin filas ni columnas.
     */
    Imagen();

    /**
     * @brief Constructor de la clase Imagen.
     *
     * Crea una imagen con el número especificado de filas y columnas.
     * @param f Número de filas de la imagen.
     * @param c Número de columnas de la imagen.
     */
    Imagen(int f, int c);

    /**
     * @brief Constructor de copia de la clase Imagen.
     *
     * Crea una copia de la imagen proporcionada.
     * @param I Referencia a la imagen que se va a copiar.
     */
    Imagen(const Imagen & I);
   
    /**
     * @brief Operador de asignación de la clase Imagen.
     *
     * Asigna los valores de la imagen proporcionada a la imagen actual.
     * @param I Referencia a la imagen que se va a asignar.
     * @return Referencia a la imagen actual.
     */
    Imagen & operator=(const Imagen & I);
   
    /**
     * @brief Destructor de la clase Imagen.
     *
     * Libera la memoria reservada para la imagen.
     */
    ~Imagen();
   
    /**
     * @brief Operador de acceso a píxeles de la imagen.
     *
     * Permite acceder y modificar el píxel en la posición (i, j) de la imagen.
     * @param i Fila del píxel.
     * @param j Columna del píxel.
     * @return Referencia al píxel en la posición especificada.
     */
    Pixel & operator()(int i, int j);

    /**
     * @brief Operador de acceso constante a píxeles de la imagen.
     *
     * Permite acceder al píxel en la posición (i, j) de la imagen sin modificarlo.
     * @param i Fila del píxel.
     * @param j Columna del píxel.
     * @return Referencia constante al píxel en la posición especificada.
     */
    const Pixel & operator()(int i, int j) const;

    /**
     * @brief Escribe la imagen en un archivo en formato PPM.
     *
     * @param nombre Nombre del archivo en el que se escribirá la imagen.
     */
    void EscribirImagen(const char * nombre);

    /**
     * @brief Lee una imagen desde un archivo en formato PPM.
     *
     * @param nombre Nombre del archivo desde el cual se leerá la imagen.
     * @param nombremascara Nombre del archivo de la máscara de transparencia. Por defecto, vacío.
     */
    void LeerImagen(const char *nombre, const string &nombremascara="");

    /**
     * @brief Limpia el componente de transparencia de todos los píxeles de la imagen.
     */
    void LimpiarTransp();

    /**
     * @brief Obtiene el número de filas de la imagen.
     * @return Número de filas de la imagen.
     */
    int num_filas() const { return nf; }

    /**
     * @brief Obtiene el número de columnas de la imagen.
     * @return Número de columnas de la imagen.
     */
    int num_cols() const { return nc; }

    /**
     * @brief Inserta una imagen en otra en una posición especificada.
     *
     * @param posi Posición de fila en la que se insertará la imagen.
     * @param posj Posición de columna en la que se insertará la imagen.
     * @param I Referencia a la imagen que se insertará.
     * @param tippegado Tipo de pegado (OPACO o BLENDING).
     */
    void PutImagen(int posi, int posj, const Imagen &I, Tipo_Pegado tippegado=OPACO);

    /**
     * @brief Extrae una subimagen de la imagen actual.
     *
     * @param posi Posición de fila de inicio de la subimagen.
     * @param posj Posición de columna de inicio de la subimagen.
     * @param dimi Número de filas de la subimagen.
     * @param dimj Número de columnas de la subimagen.
     * @return Nueva imagen que representa la subimagen extraída.
     */
    Imagen ExtraeImagen(int posi, int posj, int dimi, int dimj);

    /**
     * @brief Obtiene un iterador al inicio de la imagen.
     * @return Iterador al inicio de la imagen.
     */
    iteradorImagen begin();

    /**
     * @brief Obtiene un iterador al final de la imagen.
     * @return Iterador al final de la imagen.
     */
    iteradorImagen end();

    /**
     * @brief Obtiene un iterador constante al inicio de la imagen.
     * @return Iterador constante al inicio de la imagen.
     */
    const_iteradorImagen begin() const;

    /**
     * @brief Obtiene un iterador constante al final de la imagen.
     * @return Iterador constante al final de la imagen.
     */
    const_iteradorImagen end() const;
};

#endif
