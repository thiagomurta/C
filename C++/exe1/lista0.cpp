#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    /*QUESTÕES ENTRADE E SAÍDA*/
    /*QUESTÃO 1*/
    /*
    cout << "=============== CADASTRO DE ALUNOS ==================" << endl;
    cout << "[1] Incluir aluno" << endl ;
    cout << "[2] Excluir aluno" << endl ;
    cout << "[3] Alterar aluno" << endl ;
    cout << "[4] Sair" << endl ;
    cout << "=====================================================" <<endl;
    */
   /*QUESTÃO 2*/
   /*
    float valPagar, ICMS = 0.18;
    int KW;
    cin >> KW;
    valPagar = ((float)KW/0.12)*ICMS;
    cout << setiosflags(ios::fixed) << setprecision(1) << valPagar << endl;
    cout << setiosflags(ios::fixed) << setprecision(2) << valPagar << endl;
    cout << setiosflags(ios::fixed) << setprecision(3) << valPagar << endl;
    cout << setiosflags(ios::fixed) << setprecision(5) << valPagar << endl;
    */
   /*ESTRUTURAS DE CONTROLE*/
   /*QUESTÃO 1*/
    int i=0,j=0,k=1, numFilhos, soma, somaSal, cond=1;
    float salario, mediaSal, mediaFil, perc, maior;
    maior = 0;
    soma = 0;
    somaSal = 0;
    while(cond==1){
        cout << "Digite o salário do "<<k<<"º morador: "<< endl; 
        cin >> salario;
        if(salario>=0){
            somaSal = somaSal + salario;
            if(salario<=100 && salario>=0){
                j++;
            }
            cout << "Digite o número de filhos: " << endl;
            cin >> numFilhos;
            soma = soma + numFilhos;
            if(salario>maior){
                maior = salario;
            }
            
        k++;
        i++;
        }
        else{
            cond=0;
        }
    }
    mediaFil = (float)soma/i;
    mediaSal = (float)somaSal/i;
    perc = (j/i)*100;
    cout << setiosflags(ios::fixed) << setprecision(1) << "A média de Salário é: "<< mediaSal << endl;
    cout << setiosflags(ios::fixed) << setprecision(1) << "A média de Filhos é: "<< mediaFil << endl;
    cout << "O maior salário é: "<< maior <<endl;
    cout << setiosflags(ios::fixed) << setprecision(2)<< perc <<"%" << endl;
   /*QUESTÃO 2*/
   /*
    int res;
    cout << "=============== CADASTRO DE ALUNOS ==================" << endl;
    cout << "[1] Incluir aluno" << endl ;
    cout << "[2] Excluir aluno" << endl ;
    cout << "[3] Alterar aluno" << endl ;
    cout << "[4] Sair" << endl ;
    cin >> res;
    switch(res){
        case 1: cout << "[1] Incluir aluno" << endl;
        break;
        case 2: cout << "[2] Excluir aluno" << endl;
        break;
        case 3: cout << "[3] Alterar aluno" << endl;
        break;
        case 4: cout << "[4] Sair" << endl;
        break;
    }
    cout << "=====================================================" <<endl;
    */
    return 0;
}