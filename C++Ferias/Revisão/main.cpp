#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void estacao(int dia, int mes){
    if(dia >= 22 && mes >= 9 && dia > 0 && mes < 12 && dia < 21 && mes == 12){
        cout << "Primavera." << endl;
    }
    else if(dia >= 21 && mes == 12 && dia < 20 && mes == 3 && dia > 0 && mes < 3){
        cout << "Verão." << endl;
    }
    else if(dia < 21 && mes <= 6){
        cout << "Outono." << endl;
    }
    else{
        cout << "Inverno." << endl;
    }
}

int fatorial(int n){
    float fat = 1;
    for(int i = 1; i <= n; i++){
        fat = fat * i;
    }
    return fat;
}

float somatorio(int n){
    float k = 0;
    int m = 1;
    for(int j = 0; j < n && m <= n; j++){
        k += (n-j)/((float)fatorial(m));
        m++;
    }
    return k;
}

bool verifica(int n){
    if(n % 3 == 0 && n % 5 == 0){
        return true;
    }
    return false;
}

string c(char str[]){
    return str;
}

int main(){
    ///Parte 1- Entrada e Saída
    /* 
    1. Instrução cout
    cout << "=============== CADASTRO DE ALUNOS ==================" << endl;
    cout << "[1] Incluir aluno" << endl;
    cout << "[2] Excluir aluno" << endl;
    cout << "[3] Alterar aluno" <<endl;
    cout << "[4] Sair" << endl;
    cout << "=====================================================";
    */
    /*
    2. Formatação de valores
    double f = 2.346728;
    cout << setiosflags(ios::fixed) << setprecision(1) << f << endl;
    cout << setiosflags(ios::fixed) << setprecision(2) << f << endl;
    cout << setiosflags(ios::fixed) << setprecision(3) << f << endl;
    cout << setiosflags(ios::fixed) << setprecision(5) << f << endl;
    */
    /*
    3. Instrução cin
    float w;
    cout << "Digite o número de quilowatts consumidos: " << endl;
    cin >> w;
    double tot = (w*0.12) + ((18*w)/100);
    cout << "Valor total a pagar será " << tot << "." << endl;
    */

    ///Parte 2 - Estruturas de Controle
    /*
    1. Loops e condições
    int filhos, salario = 0, maiorSal = 0, i = 0, tFilhos = 0, cont = 0;
    float media, mFilhos, tSalario, perc;
    while(salario >= 0){
        cout << "Digite o salário: " << endl;
        cin >> salario;
        if(salario < 0){
            break;
        }
        tSalario += salario;
        if(salario > maiorSal){
            maiorSal = salario;
        }
        if( salario <= 100 && salario > 0){
            cont++;
        }
        if(salario >= 0){
            cout << "Digite o número de filhos: " << endl;
            cin >> filhos;
            tFilhos += filhos;
            i++;
        }
    }
    mFilhos = tFilhos / i;
    media = tSalario / i;
    perc = (cont*100)/i;
    cout << "Média de filhos: " << setiosflags(ios::fixed) << setprecision(2) << mFilhos << endl;
    cout << "Média de salário: " << setiosflags(ios::fixed) << setprecision(2) << media << endl;
    cout << "Maior Salário: " << setiosflags(ios::fixed) << setprecision(2) << maiorSal << endl;
    cout << "Percentual de pessoas com salário até R$ 100,00: " << setiosflags(ios::fixed) << setprecision(2) << perc << endl;
    */
    /*
    2. Comando switch (expression)
    int x;
    cout << "=============== CADASTRO DE ALUNOS ==================" << endl;
    cout << "[1] Incluir aluno" << endl << "[2] Excluir aluno" << endl << "[3] Alterar aluno" <<endl << "[4] Sair" << endl << "=====================================================" << endl;
    cin >> x;
    switch(x){
    case 1: cout << "[1] Incluir aluno" << endl;
        break;
    case 2: cout << "[2] Excluir aluno" << endl;
        break;
    case 3: cout << "[3] Alterar aluno" <<endl;
        break;
    case 4: cout << "[4] Sair" << endl;
        break;
    default: cout << "Valor inválido!" << endl;
    }
    */

    ///Parte 3 - Funções
    /*
    1. Função
    int dia, mes;
    cout << "Digite uma dia: ";
    cin >> dia;
    while(dia > 31){
        cout << "Digite uma data válida: ";
        cin >> dia;
    }
    cout << "Digite um mês: ";
    cin >> mes;
    while(mes > 12){
        cout << "Digite uma data válida: ";
        cin >> mes;
    }
    estacao(dia, mes);
    */
    /*
    2. Funções auxiliares
    int n;
    cout << "Digite um número para realizar o somatório: ";
    cin >> n;
    while(n < 0){
        cout << "Digite um valor válido: ";
        cin >> n;
    }
    cout << "Resultado do somatório: " << setiosflags(ios::fixed) << setprecision(3) << somatorio(n) << endl;
    */
    /*
    3. Função booleana
    int n;
    cout << "Digite um número: ";
    cin >> n;
    if(verifica(n)){
        cout << "TRUE" << endl;
    }
    else{
        cout << "FALSE" << endl;
    }
    */
    ///Parte 4 - Arrays
    /*
    1. Impressão de tabela
    int vet[20];
    int m = 0;
    for(int i = 0; i < 20; i++){
        cout << "Digite um valor: ";
        cin >> vet[i];
        m += vet[i];
    }
    int media = m/20;
    cout << "Valor | Media" << endl << "_____________" << endl << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << vet[i] << " -- " << media << endl;
    }
    */
    /*
    2. Vetores como parâmetros
    int vet[50] = {0};
    int n, m;
    cout << "Digite uma posição que será alterado o valor: ";
    cin >> n;
    while(n>=50){
        cout << "Digite uma posição válida que será alterado o valor: ";
        cin >> n;
    }
    cout << "Digite um valor para a posição: ";
    cin >> m;
    vet[n] = m;
    cout << "Digite uma posição que será excluída: ";
    cin >> n;
    */
    /*
    3. Matrizes
    int mat[10][10] = {0};
    for(int i = 0; i < 10; i++){
        mat[i][i] = 1;
    }
    int mat2[10][10] = {0};
    int mat3[10][10];
    int mat4[10][10];
    for(int i = 0; i < 10; i++){
        mat2[i][i] = 1;
    }

    //soma
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            mat3[i][j] = mat[i][j] + mat2[i][j];
        }
    }

    //multiplicação
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            mat4[i][j] = mat[j][i] * mat3[i][j];
        }
    }

    //impressão
    cout << "Matriz somada: " << endl;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << mat3[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Matriz multiplicada: " << endl;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << mat4[i][j] << "\t";
        }
        cout << endl;
    }
    */
    ///Parte 5- Strings
    /*
    1. Strings C-style
    char str[500];
    string s;
    cout << "Digite uma palavra: ";
    cin >> str;
    s = c(str);
    cout << "A palavra digitada foi: " << s << endl;
    */
    /*
    2. Particionamento de strings
    string s, frase;
    cout << "Digite a frase que será particionada: ";
    getline(cin,frase);
    cout << "Digite o caractere que será usado para quebrar linha: ";
    cin >> s;
    for(int i = 0; i < frase.size(); i++){
        if(frase[i] == s[0]){
            cout << endl;
        }
        else{
            cout << frase[i];
        }
    }
    cout << endl;
    */
    /*
    3. Particionamento de strings com vetores
    string s, frase, particionamento;
    int cont = 0;
    cout << "Digite a frase que será particionada: ";
    getline(cin,frase);
    cout << "Digite o caractere que será usado para quebrar linha: ";
    cin >> s;
    cout << "String  |  Tamanho" << endl;
    cout << "_______________________" << endl << endl;
    for(int i = 0; i <= frase.size(); i++){
        if(frase[i] == s[0]){
            cout << particionamento << "\t--\t" << cont << endl;
            particionamento = '\0';
            cont = 0;
        }
        else{
            particionamento += frase[i];
            cont++;
        }
    }
    cout << endl;
    */
    /*
    4. Substituição de caracteres
    string str;
    cout << "Digite uma frase que será trocada as vogais: "; 
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'a'){
            str[i] = 'e';
        }
        else if(str[i] == 'e'){
            str[i] = 'i';
        }
        else if(str[i] == 'i'){
            str[i] = 'o';
        }
        else if(str[i] == 'o'){
            str[i] = 'u';
        }
        else{
            str[i];
        }
    }
    cout << str << endl;
    */
    /*
    5. Minha string.h
    string strA, strB, len, cat, cpy;
    strA = 'Olá, '; 
    strB = 'tudo bem!';
    // criar nova função string
    */
}