#ifndef ATIVIDADE3_H_
#define ATIVIDADE3_H_

using namespace std;

class Atividade3{
	private:
		int n; //(quantidade de valores);
		float m; //(média dos valores);
		int* x; //(valores).
		void leDados();
	public:
		Atividade3(int nn);
		~Atividade3();
		void setX();
		void setM();
		float getM();
};
#endif /*ATIVIDADE3_H_*/