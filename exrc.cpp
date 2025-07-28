#include <iostream>

using namespace std;
/* 
Este programa calcula o peso ideal de uma pessoa com base na altura e no sexo, e também fornece uma tabela de macronutrientes recomendados para homens e mulheres.
| Macronutriente  | Homens (por kg) | Mulheres (por kg) 
| --------------- | --------------- | -----------------
| **Proteína**    | 1.8–2.2 g       | 1.6–2.0 g         
| **Gordura**     | 0.8–1 g         | 0.9–1.1 g         
| **Carboidrato** | 4–6 g           | 3.5–5.5 g               

*/

int main(){

    float pesoIdeal, altura, pesoAtual, Proteina, Gordura, Carboidrato, DIV = 0 ;
    char sexo;
    int vetor[2];

    cout << "Altura em cm: ";
    cin >> altura;

    cout << "Peso em kg: ";
    cin >> pesoAtual;

    cout << "Sexo (M para masculino, F para feminino): ";
    cin >> sexo;

    if(sexo == 'M' || sexo == 'm'){
        pesoIdeal = (72.7 * altura) - 58;
        cout << "Seu peso ideal eh: " << pesoIdeal << " kg" << endl;
    } else if(sexo == 'F' || sexo == 'f'){
        pesoIdeal = (62.1  * altura) - 44.7;
        cout << "Seu peso ideal eh: " << pesoIdeal << " kg" << endl;

    }

    // Cálculo dos macronutrientes
    if(sexo == 'M' || sexo == 'm'){
        Proteina = pesoIdeal * 2.2; // 2.2 g de proteína por kg
        Gordura = pesoIdeal * 1; // 1 g de gordura por kg
        Carboidrato = pesoIdeal * 6; // 6 g de carboidrato por kg
    }   else if(sexo == 'F' || sexo == 'f'){
        Proteina = pesoIdeal * 2.0; // 2.0 g de proteína por kg
        Gordura = pesoIdeal * 1.1; // 1.1 g de gordura por kg
        Carboidrato = pesoIdeal * 5.5; // 5.5 g de carboidrato por kg
    } 

    vetor[0] = Proteina;
    vetor[1] = Gordura;
    vetor[2] = Carboidrato;

      cout << "===TABELA DE MACRONUTRIENTES===" << endl;


       cout << vetor[0] << "g Proteina" << endl;
       cout << vetor[1]  << "g Gordura" << endl;
       cout << vetor[2]  << "g Carboidrato" << endl;

      



    return 0;
}