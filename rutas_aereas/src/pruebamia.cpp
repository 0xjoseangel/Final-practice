#include "imagen.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


int main(int argc, char * argv[]){
  Imagen I;
  
  I.LeerImagen(argv[1]);
  Imagen::iteradorImagen it = I.begin();
  Imagen::iteradorImagen end = I.end();
  while(it != end){
    Pixel pixel = *it;
    cout << pixel.r << " ";
    ++it;
  }
  cout << end.getCurrentCol();
  cout << it.getCurrentCol();
  cout << endl;

  I.EscribirImagen(argv[2]);
  
  return 0;
}
 