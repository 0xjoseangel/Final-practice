/*!
 * @file imagen.h
 * @brief Cabecera para la clase Imagen
 */

#include <string>

#ifndef __IMAGEN__H
#define __IMAGEN_H

enum Tipo_Pegado {OPACO, BLENDING};
using namespace std;
struct Pixel{
    unsigned char r,g,b;
    unsigned char transp; //0 no 255 si
};  
class Imagen{
private:
    Pixel ** data;
    int nf,nc;

    /**
      @brief Copy una imagen .
      @param orig Referencia a la imagen original que vamos a copiar
      @pre Asume que no hay memoria reservada o se ha llamado antes a Destroy()
      @pre Asume this != &orig
    **/
    void Copiar(const Imagen &I);   
    /**
      @brief Reserva o copia en memoria una imagen.
      @param nrows Número de filas que tendrá la imagen.
      @param ncols Número de colwnnas que tendrá la imagen.
      @param buffer Puntero a un buffer de datos con los que rellenar los píxeles de la imagen. Por defecto, 0.
      @pre nrows >= O y ncols >= O
      @post Reserva memoria para almacenar la imagen y la prepara para usarse.
    **/
    void Allocate(int nrows=0, int ncols=0);  
    /**
     * @brief Borra una imagen
     *
     * Libera la memoria reservada en la que se almacenaba la imagen que llama a la función.
     * Si la imagen estaba vacía no hace nada .
     */
    void Borrar();
public:
    class iterador {
    private:
        Pixel * ptr;
        Imagen& imagen;  
        int currentRow;     
        int currentCol;
    public:
        iterador();
        iterador(const iterador &v);
        ~iterador();
        iterador & operator=(const iterador& orig);
        Pixel & operator*() const;
        iterador & operator++();
        iterador & operator--();
        bool operator!=(const iterador& v) const;
        bool operator==(const iterador& v) const;

    };
    Imagen();

    Imagen(int f,int c);

    Imagen(const Imagen & I);
   
    Imagen & operator=(const Imagen & I);
   
    ~Imagen();
   
    //set y get
    Pixel & operator ()(int i,int j);

    const Pixel & operator ()(int i,int j)const;

    void EscribirImagen(const char * nombre);

    void LeerImagen (const char *nombre,const string &nombremascara="");
    void LimpiarTransp();
    int num_filas()const{return nf;}
    int num_cols()const{return nc;}
    void PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado=OPACO);
    Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj);
};   
#endif