#include<iostream>

using namespace std;

int main(){
	
	int numero=0;
	int tam,narch;
	
	FILE*f;
	f=fopen("leo.binario","wb");
	
	for(int i=1;i<10;i++){
		numero++;
		fwrite(&numero,sizeof(int),1,f);
	}
	
	fclose(f);
	
	f=fopen("leo.binario","rb");
	
	for(int i=1;i<10;i++){
		fread(&numero,sizeof(int),1,f);
		cout<<numero<<endl;
	}
	
	fclose(f);
	cout<<"*************************"<<endl;
	f=fopen("leo.binario","rb+");
	
	
	fseek(f,sizeof(int),SEEK_SET);
	fread(&numero,sizeof(int),1,f);
	cout<<numero<<endl;
	
	cout<<"*************************"<<endl;

	fseek(f,sizeof(int)*5,SEEK_SET);
	fread(&numero,sizeof(int),1,f);
	numero=numero*100;
	cout<<"este es el cout de :"<<numero<<endl;
	fseek(f,sizeof(int)*5,SEEK_SET);
	fwrite(&numero,sizeof(int),1,f);
	
	cout<<"*************reimprimiendo**********"<<endl;
	fseek(f,0,SEEK_SET);
	for(int i=1;i<10;i++){
		fread(&numero,sizeof(int),1,f);
		cout<<numero<<endl;
	}
	fseek(f,0,SEEK_END);
	tam=ftell(f);
	narch=tam/sizeof(int);
	cout<<"el tama�o es : "<<tam<<endl;
	cout<<"cantidad de archivos : "<<narch<<endl;

	fclose(f);

	system("PAUSE");
	return 0;
}
