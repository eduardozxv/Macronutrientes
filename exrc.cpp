#include <iostream>
using namespace std;

#include <string>
struct Alimento {
    string nome;
    float proteina;
    float gordura;
    float carbo;
};


float calculaPesoIdeal(char sexo, float altura){
    if(sexo == 'M' || sexo == 'm') return (72.7 * altura) - 58;
    else return (62.1 * altura) - 44.7;
}


void calculaMacros(float pesoIdeal, char sexo, float &Proteina, float &Gordura, float &Carbo){
    if(sexo == 'M' || sexo == 'm'){
        Proteina = pesoIdeal * 2.2;
        Gordura = pesoIdeal * 1.0;
        Carbo = pesoIdeal * 6.0;
    } else {
        Proteina = pesoIdeal * 2.0;
        Gordura = pesoIdeal * 1.1;
        Carbo = pesoIdeal * 5.5;
    }
}


void calculaMacrosPrato(Alimento a, float quantidade, float &p, float &g, float &c){
    p = (quantidade / 100.0) * a.proteina;
    g = (quantidade / 100.0) * a.gordura;
    c = (quantidade / 100.0) * a.carbo;
}

int main() {

    Alimento banco[] = {
        {"Arroz", 2.6, 0.3, 28.0},
        {"Feijao", 9.0, 0.5, 27.0},
        {"Frango", 31.0, 3.6, 0.0},
        {"Ovo", 13.0, 11.0, 1.1},
        {"Batata", 2.0, 0.1, 17.0},
        {"Pao", 8.0, 1.5, 50.0}
    };

    float altura, pesoAtual, pesoIdeal;
    char sexo;


    cout << "Altura em cm: ";
    cin >> altura;

    cout << "Peso em kg: ";
    cin >> pesoAtual;

    cout << "Sexo (M/F): ";
    cin >> sexo;

    
    pesoIdeal = calculaPesoIdeal(sexo, altura);
    cout << "Seu peso ideal eh: " << pesoIdeal << " kg" << endl;


    float Proteina, Gordura, Carboidrato;
    calculaMacros(pesoIdeal, sexo, Proteina, Gordura, Carboidrato);

    cout << "\n===TABELA DE MACRONUTRIENTES POR KG===" << endl;
    cout << Proteina << "g Proteina" << endl;
    cout << Gordura << "g Gordura" << endl;
    cout << Carboidrato << "g Carboidrato" << endl;


    char continuar, opcao;
    float totalProteina = 0, totalGordura = 0, totalCarbo = 0;

    cout << "\nDeseja pesar quanto de macro tem em cada alimento do seu prato? (S/N): ";
    cin >> opcao;

    if(opcao == 's' || opcao == 'S'){
       do {

        cout << "\nEscolha o alimento no banco de dados: " << endl;
        for(int i = 0; i < 6; i++){
            cout << i+1 << ". " << banco[i].nome << endl;
        }


        int escolha;
        cout << "Digite o numero do alimento: ";
        cin >> escolha;
        int indice = escolha - 1;


        float quantidade, proteinaFinal, gorduraFinal, carboFinal;
        cout << "Digite a quantidade em gramas: ";
        cin >> quantidade;


        calculaMacrosPrato(banco[indice], quantidade, proteinaFinal, gorduraFinal, carboFinal);


        if(banco[indice].nome == "Arroz" || banco[indice].nome == "Batata" || banco[indice].nome == "Pao"){
            cout << "Carboidratos: " << carboFinal << "g\n";
        } else if(banco[indice].nome == "Frango" || banco[indice].nome == "Feijao"){
            cout << "Proteina: " << proteinaFinal << "g\n";
        } else if(banco[indice].nome == "Ovo"){
            cout << "Proteina: " << proteinaFinal << "g\n";
            cout << "Gordura: " << gorduraFinal << "g\n";
        }


        totalProteina += proteinaFinal;
        totalGordura  += gorduraFinal;
        totalCarbo    += carboFinal;

        
        cout << "Deseja adicionar outro alimento? (S/N): ";
        cin >> continuar;

    } while(continuar == 's' || continuar == 'S');

        cout << "\n===Macros totais do prato===" << endl;
        cout << totalProteina << "g Proteina\n";
        cout << totalGordura  << "g Gordura\n";
        cout << totalCarbo    << "g Carboidrato\n";

    return 0;
}
}
