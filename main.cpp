#include <fstream>
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

fstream arquivo;
unordered_map<string,vector<int>> notas;

int imprimir(){
	int n;
	cout << "1 - adicionas aluno" << endl;
	cout << "2 - exibir informaçoes" << endl;
	cout << "3 - calcular media " << endl;
	cout << "4 - salvar dados" << endl;
	cout << "5 - carregar dados e sair" << endl;
	
	cin >> n;
	
	while (n < 1 || n > 5){
		cout << "escolha um numero de 1 a 5" << endl;
		cin >> n;
	}
	return n;
}

void addAluno(){
	string name;
	cout << "digite o nome do aluno -> " << endl;
	cin.ignore();
	getline(cin,name);
	
	for (int i=0;i<4;i++){
		cout << "digite a " << i+1 << " nota dele: " << endl;
		int e;
		cin >> e;
		notas[name].push_back(e);
	}
	
	arquivo << "aluno -> " << name << " ";
	
	for (auto num : notas[name]){
		arquivo << num << " ";
	}
}

void informacoes(){
	
	for (auto a : notas){
		int m=0;
		
		string p = a.first;
		
		vector<int> arr = a.second;
		
		for (auto num : arr){
			m += num;
		}

		m /= 4;
		if (m >= 6){
			arquivo << "aluno -> " << p << " media: "<< m <<" aprovado" << endl;
			cout << "aluno -> " << p << " media: "<< m <<" aprovado" << endl;
		}else{
			arquivo << "aluno -> " << p << " media: "<< m <<" reprovado" << endl;
			cout << "aluno -> " << p << " media: "<< m <<" reprovado" << endl;
			
		}
	}
	
}

void adicionar(){
	for (auto a : notas){
		string name = a.first;
		
		vector<int> arr = a.second;
		
		double m = 0;
		
		arquivo << "aluno -> " << name << " ";
		
		for (auto num : arr){
			arquivo << num << " ";
			m += num;
		}
		
		m /= 4;
		
		arquivo << "media -> " << m << endl << endl;
		
		cout << "salvo no arquivo!" << endl;
	}
}

void mostrar(){
	
	arquivo.close();
	
	arquivo.open("teste.txt",fstream::in);
	
	string linha;
	
	arquivo.seekg(0);
	
	if (arquivo.is_open()){
		while (getline(arquivo,linha)){
			cout << linha << endl;
		}
	}
	cout << "obrigado por usar !" << endl;
}

int main(){
	
	arquivo.open("teste.txt",fstream::out|fstream::app);
	
	while (true){
		
		cout << "o que voce deseja fazer ? " << endl;
		

		int escolha = imprimir();
		
		if (escolha == 1){
			addAluno();
		}
		
		if (escolha == 2 || escolha == 3){
			informacoes();
		}
		
		if (escolha == 4){
			adicionar();
		}
		
		if (escolha == 5){
			mostrar();
			break;
		}
	}
	
	arquivo.close();
	return 0;
}
