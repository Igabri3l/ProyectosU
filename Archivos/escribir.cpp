#include<iostream>

using namespace std;

int main(){
	
	string palabra;
	
	cout<<"escritura en archivo de texto";
	cout<<"escribi lo que quieras"<<endl<<endl;
	
	cin>>palabra;
	
	FILE*f;
	f=fopen("lele.txt", "w");
	
	fprintf(f,"la palabra que escribiste es %s" , palabra.c_str());
	
	fclose(f);
	
	return 0;
}
