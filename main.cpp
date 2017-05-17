	// reading an entire binary file
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

struct registro{
    char nombre [200];
    char ape[200];
    char cedula [12];
    char fechaN [11];
    float notas[30];
    char direccion[500];
};

void validar(string variable){

}

int main () {
  registro reg;
  streampos size;
    ofstream archivo("hola.csv",ios::trunc);  
    ifstream file ("datos.bin", ios::in|ios::binary|ios::ate);
  if (file.is_open()){
    size = file.tellg();
    file.seekg (0, ios::beg);
    int x=0;
    do{
    file.seekg(x);
    x=x+200+200+11+12+(30*4)+500+1;
    file.read (reg.nombre, 200);
    file.read (reg.ape, 200);
    file.read (reg.fechaN, 11);
    file.read (reg.cedula,12);
    for (int i = 0; i < 30; i++){
            file.read((char *)(&reg.notas[i]),sizeof(reg.notas[i]));
        }
    file.read (reg.direccion,500);
    archivo<<reg.nombre<<",";
    archivo<<reg.ape<<",";
    archivo<<reg.fechaN<<",";
    archivo<<reg.cedula<<",\"";
    for(int x=0;x<30;x++){
        if(x<29){
            archivo<<reg.notas[x]<<",";
        }else{   
            archivo<<reg.notas[x]<<"\",\"";
        }
    }
    archivo<<reg.direccion<<"\"\n";
    /*cout<<reg.nombre<<",";
    cout<<reg.ape<<",";
    cout<<reg.fechaN<<",";
    cout<<reg.cedula<<",";                          este codigo es por si quiere mostrar los datos en pantalla
    for(int x=0;x<30;x++){
        cout<<reg.notas[x]<<",";
    }
    cout<<reg.direccion<<endl;
    system("pause");*/
    }while(x<size);
    cout << "el archivo termino su proceso de transferencia\n\n";
    file.close();
  }else cout << "el archivo no se abrio \n\n";
  system("pause");
  
  return 0;
}	

  
  
  
