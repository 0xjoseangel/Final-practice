// #include <iostream>
// #include <fstream>
// #include <cmath>

// #include "imagen.h"
// #include "Paises.h"
// #include "Almacen_Rutas.h"

// using namespace std;
// void Pintar( int f1,int f2,int c1,int c2,Imagen &I, const Imagen &avion,int mindisf,int mindisc);
  
// /** 
//  * @brief Obtiene una nueva imagen que es la versión rotada de una imagen de entrada
//  * @param Io: imagen de entrada
//  * @param angulo: angulo a rotar la imagen de entrada. Debe estar en radianes.
//  * @return Una nueva imagen que es la versión rotada de Io.
//  * */

// Imagen Rota(const Imagen & Io,double angulo);

// int main(int argc, char * argv[]){
//   if (argc!=7){
//       cout<<"Los parametros son:"<<endl;
//       cout<<"1.-Fichero con la informacion de los paises"<<endl;
//       cout<<"2.-Nombre de la imagen con el mapa del mundo"<<endl;
//       cout<<"3.-Directorio con las banderas"<<endl;
//       cout<<"4.-Fichero con el almacen de rutas"<<endl;
//       cout<<"5.- Nombre de la imagen con el avion"<<endl;
//       cout<<"6.- Nombre de la imagen de la mascara del avion"<<endl;
//   }
//       Paises Pses;
//   ifstream f (argv[1]);
//   f>>Pses;
//   //cout<<Pses;
//   Imagen I;
//   I.LeerImagen(argv[2]);
  
//   //Leemos los aviones 
//   Imagen avion;
//   avion.LeerImagen(argv[5],argv[6]);
  
//   Almacen_Rutas Ar;
//   f.close();
//    f.open (argv[4]);
//   f>>Ar;
//   cout<<"Las rutas: "<<endl<<Ar;
//   cout<<"Dime el codigo de una ruta"<<endl;
//   string a;
//   cin>>a;
//   Ruta R=Ar.GetRuta(a);
//       return 0;
// }    


// Imagen Rota(const Imagen & Io,double angulo){
//     double rads=angulo;
//     double coseno = cos(angulo);
//     double seno = sin(angulo);
//     //Para obtener las dimensiones de la imagen
//     int rcorners[4],ccorners[4];
//     int newimgrows,newimgcols;
//     double new_row_min,new_col_min,new_row_max,new_col_max;
//     double inter,inter1;
//     rcorners[0]=0;
//     rcorners[1]=0;
//     ccorners[0]=0;
//     ccorners[2]=0;
//     rcorners[2]=Io.num_filas()-1;
//     rcorners[3]=Io.num_filas()-1;
//     ccorners[1]=Io.num_cols()-1;
//     ccorners[3]=Io.num_cols()-1;
//     new_row_min=0;
//     new_col_min=0;
//     new_row_max=0;
//     new_col_max=0;
//     newimgrows=0;
//     newimgcols=0;
//     for(int count=0;count<4;count++)
//     {
// 	    inter=rcorners[count]*coseno+ccorners[count]*seno;
	   
// 	    if(inter<new_row_min)
// 		    new_row_min=inter;
// 	    if(inter>new_row_max)
// 		    new_row_max=inter;
// 	    inter1=-rcorners[count]*seno+ccorners[count]*coseno;
	   
// 	    if(inter1<new_col_min)
// 		    new_col_min=inter1;	
// 	    if(inter1>new_col_max)
// 		    new_col_max=inter1;
//    }
    
//     newimgrows=(unsigned)ceil((double)new_row_max-new_row_min);
//     newimgcols=(unsigned)ceil((double)new_col_max-new_col_min);
   
//     Imagen Iout(newimgrows,newimgcols);
//     for(int rows=0;rows<newimgrows;rows++)
//       {
// 	for(int cols=0;cols<newimgcols;cols++)
// 	{
// 	   float oldrowcos=((float)rows+new_row_min)*cos(-rads);
// 	   float oldrowsin=((float)rows+new_row_min)*sin(-rads);
// 	   float oldcolcos=((float)cols+new_col_min)*cos(-rads);
// 	   float oldcolsin=((float)cols+new_col_min)*sin(-rads);
// 	   float old_row=oldrowcos+oldcolsin;
// 	   float old_col=-oldrowsin+oldcolcos;
// 	   old_row=ceil((double)old_row);
// 	   old_col=ceil((double)old_col);
// 	   if((old_row>=0)&&(old_row<Io.num_filas())&&
// 	      (old_col>=0)&&(old_col<Io.num_cols()))
// 	   {
// 	      Iout(rows,cols)=Io(old_row,old_col);
              
// 	   }
// 	   else
// 	     Iout(rows,cols).r=Iout(rows,cols).g=Iout(rows,cols).b=255;
// 	}
//     }
//     return Iout;
	  
// }

// void Pintar( int f1,int f2,int c1,int c2,Imagen &I, const Imagen &avion,int mindisf,int mindisc){
      
//       int fila,col;
//       if (abs(f2-f1)>=mindisf || abs(c2-c1)>=mindisc){ 
	
// 	 if (c1!=c2){
// 	   double a,b;
// 	   a= double(f2-f1)/double(c2-c1);
// 	   b= f1-a*c1;
// 	   col = (int)(c1+c2)/2;
// 	   fila = (int)rint(a*col+b);
// 	 }  
// 	 else{
// 	   col = c1;
// 	   fila = (f1+f2)/2;
// 	 }  
	  
	  
// 	  double angulo = atan2((f2-f1),(c2-c1));
// 	  Imagen Irota=Rota(avion,angulo);
	
// 	  I.PutImagen(fila,col,Irota);//pensar si debe ser opaco o blending
	  
// 	   angulo = atan2((f2-fila),(c2-col));
// 	  Irota=Rota(avion,angulo);
	
// 	  I.PutImagen(f2,c2,Irota);//pensar si debe ser opaco o blending
// 	  angulo = atan2((fila-f1),(col-c1));
// 	  Irota=Rota(avion,angulo);
	
// 	  I.PutImagen(f1,c1,Irota);//pensar si debe ser opaco o blending
	 
      
//       }
     
// }  

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}
