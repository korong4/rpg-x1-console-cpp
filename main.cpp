#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <string>
using namespace std;

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void barravidap1(string nome,int vidaAtual){
	const int maxVida = 10;
	
	setColor(10);
	cout << nome << " ->  ";
	cout << "[";
	for (int i=0;i<vidaAtual;i++){
		cout << "#";
	}
	for (int i=vidaAtual;i<maxVida;i++){
		cout << "-";
	}
	cout << "] ";
	setColor(7);
	cout << vidaAtual << "/" << maxVida << endl;
	setColor(7);
}

void barravidap2(string nome,int vidaAtual){
	const int maxVida = 10;
	
	setColor(12);
	cout << nome << " ->  ";
	cout << "[";
	for (int i=0;i<vidaAtual;i++){
		cout << "#";
	}
	for (int i=vidaAtual;i<maxVida;i++){
		cout << "-";
	}
	cout << "] ";
	setColor(7);
	cout << vidaAtual << "/" << maxVida << endl;
	setColor(7);
}

void empate(){
	system("cls");
	setColor(11);
	cout << "========================================\n";
    cout << "                EMPATE                 \n";
    cout << "========================================\n\n";
    setColor(7);
    cout << "Ambos os guerreiros caem exaustos..." << endl;
    cout << "Nenhum saiu vitorioso desta batalha." << endl << endl;
    system("pause");
}

void derrota(){
	system("cls");
	setColor(12);
	cout << "========================================\n";
    cout << "              GAME OVER                \n";
    cout << "========================================\n\n";
	setColor(7);
    cout << "Voce lutou bravamente, mas foi derrotado..." << endl << endl;
    system("pause");	
}

void vitoria (){
	system("cls");
	setColor(10);
	cout << "========================================\n";
    cout << "              VITORIA!!!               \n";
    cout << "========================================\n\n";
    setColor(7);
    cout << "Parabens! Voce derrotou o oponente!!!!" << endl << endl;
    system("pause");
}

int rodada = 0;

void vidas(int v1, int v2){
	setColor(7);
	cout << "=========== BATALHA RPG X1 ===========" << endl << endl;
	
	cout << "rodada -> " << rodada << endl;
	
    cout << "\n====================================\n";
    setColor(11);
    cout << " STATUS DOS JOGADORES\n";
    setColor(7);
    cout << "------------------------------------\n";

  	barravidap1("voce     ",v1);
  	barravidap2("oponente ",v2);

    cout << endl;
    
    cout << "voce deseja ? " << endl;
    setColor(12);
	cout << "1 - para atacar" << endl;
	setColor(10);
	cout << "2 - para defender" << endl;
	setColor(7);
}

class Player {
	
	private:
		int vida = 10;
		int defesa = 0;
	
	public:
		
		int getVida(){
			if (vida <= 0){
				return -1;
			}
			return vida;
		}
		
		int getdefesa(){
			return defesa;
		}
		
		void setVida(int n){
			vida = vida - n;
		}
		
		int setDano(){  // dano ou defesa;
			int d = 0 + (rand() % 7);
			return d;
		}
};



int main(){
	
	srand(time(NULL));
	
	Player* p1 = new Player;
	Player* p2 = new Player;
		
	while (true){
		
		rodada++;
		int vidaAtual = p1->getVida();
		int danoAtual = p1->setDano();
		int defesaAtual = p1->setDano();
		int defesap2 = p2->setDano();
		int danop2 = p2->setDano();
		int vidap2 = p2->getVida();
		
		vidas(vidaAtual,vidap2);
		
		int e;
		
		while (cin >> e){
			if (e != 1 && e != 2){
				cout << "numero invalido! " << endl;
				cin >> e;
			}
			else break;		
		}
		
		int e2 = 1 + (rand() % 2);
		
		if (e2 == 1 && e == 1){ //os dois ataca
		
			setColor(14);
			cout << "===================================================\n";
			cout << "COLISAO DE ATAQUE! OS DOIS ATACAM AO MESMO TEMPO!!!" << endl;
			cout << "===================================================\n";
			
			setColor(12);
			cout << "seu ataque -> " << danoAtual << endl;
			cout << "ataque oponente -> " << danop2 << endl;
			
			if (danoAtual == danop2){
				setColor(11);
				cout << "empate... nada acontece" << endl;
				setColor(7);
				system("pause");
				system("cls");
				continue;
			}
			else if (danoAtual > danop2){
				setColor(10);
				cout << "seu ataque e maior!!!!!" << endl;
				
				int dife = danoAtual - danop2;
				
				setColor(7);
				cout << "seu oponente toma -> ";
				setColor(10);
				cout << dife;
				
				cout << " de dano!!!" << endl;
				
				p2->setVida(dife);
			}
			else{
				setColor(12);
				cout << "seu ataque e menor...." << endl;
				int dife = danop2 - danoAtual;
				
				setColor(7);
				cout << "voce toma -> " ;
				setColor(12);
				cout << dife;
		
				cout << " de dano " << endl;
				p1->setVida(dife);
			}
			setColor(7);
		}
		
		else if (e == 2 && e2 == 1){ // voce defende ele ataca
		
			setColor(14);
			cout << "===========================================================\n";
			cout << "o oponente ataca com tudo enquanto você bloqueia o impacto!" << endl;
			cout << "===========================================================\n" << endl;
			
			setColor(10);
			cout << "sua defesa -> " << defesaAtual << endl;
			
			setColor(12);
			cout << "ataque do oponente -> " << danop2 << endl;
			
			if (defesaAtual == danop2){
				setColor(11);
				cout << "ataque iguais " << endl;
				cout << "empate nada acontece..." << endl;
				setColor(7);
				system("pause");
				system("cls");
				continue;
			}
			else if (defesaAtual < danop2){
				setColor(12);
				cout << "sua defesa e menor..." << endl;
				
				int dife = danop2 - defesaAtual;
				
				setColor(7);
				cout << "voce toma -> " ;
				setColor(12);
				cout << dife;

				cout << " de dano " << endl;
				p1->setVida(dife);
			}
			else{
				setColor(10);
				cout << "sua defesa e maior !!!! " << endl;
				
				int dife = defesaAtual - danop2;
				
				setColor(7);
				cout << "seu oponente toma -> ";
				setColor(10);
				cout << dife;
		
				cout << " de dano!!!" << endl;
				
				p2->setVida(dife);
			}
			setColor(7);
		}
		
		else if (e == 2 && e2 == 2){  //duas defesas
		
			setColor(14);
			cout << "==================\n";
			cout << "COLISAO DE DEFESAS" << endl;
			cout << "==================\n" << endl;
			
			setColor(11);
			cout << "nada acontece" << endl;
			setColor(7);
		}
		
		else{ //eu ataco e ele defende
			
			setColor(14);
			cout << "========================================================\n";
			cout << "VOCE ATACA COM TUDO ENQUANTO SEU OPONENTE TENTA BLOQUEAR" << endl;
			cout << "========================================================\n" << endl;
			
			setColor(12);
			cout << "seu ataque -> " << danoAtual << endl;
			setColor(10);
			cout << "defesa do oponente -> " << defesap2 << endl;
			
			if (danoAtual == defesap2){
				setColor(11);
				cout << "seu ataque foi igual a defesa..." << endl;
				cout << "nada acontece" << endl;
				setColor(7);
				system("pause");
				system("cls");
				continue;
			}
			else if (danoAtual > defesap2){
				setColor(10);
				cout << "seu ataque e maior que a defesa!!!!" << endl;
				int dife = danoAtual - defesap2;
				
				setColor(7);
				cout << "seu oponente toma -> ";
				setColor(10);
				cout << dife;
				
				cout << " de dano!!!" << endl;
				p2->setVida(dife);
			}
			else{
				setColor(12);
				cout << "voce nao consegue vencer a defesa dele..." << endl;
				int dife = defesap2 - danoAtual;
				
				setColor(7);
				cout << "voce toma -> " ;
				setColor(12);
				cout << dife;
				
				cout << " de dano " << endl;
				p1->setVida(dife);
			}
			setColor(7);
		}
		
		if (p1->getVida() == -1 && p2->getVida() == -1){
			cout << "sua vida -> " << p1->getVida() << " vida do oponente -> " << p2->getVida() << endl;
			system("pause");
			empate();
			return 0;
		}
		
		if (p1->getVida() == -1){
			cout << "sua vida -> " << p1->getVida() << " vida do oponente -> " << p2->getVida() << endl;
			system("pause");
			derrota();
			return 0;
		}
		
		if (p2->getVida() == -1){
			cout << "sua vida -> " << p1->getVida() << " vida do oponente -> " << p2->getVida() << endl;
			system("pause");
			vitoria();
			return 0;
		}
		
		system("pause");
		system("cls");

	}
	return 0;
}
