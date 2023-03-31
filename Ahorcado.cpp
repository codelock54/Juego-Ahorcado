    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include<conio.h>
    #include<time.h>
    #include<windows.h>
    #include<stdio.h>

// mejorar la calidad visual
// escoger por temas y dificultad (con botones -interfaces- )
// guardar cada cambio importante y versiones convenientemente
// agregar sonido si pierdes vida o si aciertas


    using namespace std;

string palabra_original, tema;
 int vidas,j;


void juego(char x,string palabra_mostrar);

void gotoxy(int x, int y) // ubicacion de la letras
{
    HANDLE hCon;
    hCon = GetStdHandle (STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hCon, dwPos);
}




    int main()
    {
        system("color 70 " );


        char letra, a;
        int k;


       do
       {
           gotoxy(40,1);
        cout << "BIENVENIDO AL JUEGO DEL AHORCADO" << endl;



         string palabra_most;


         int n;

// aqui modificar a escoger tema (mostrar los temas disponibles y luego es coger el nivel)
         gotoxy(30,3);
        cout<<endl<<" Escoja nivel [ 1/ 2 / 3 ]: ";
        cin>>n;

        switch (n)
        {
            case 1:
                gotoxy(40,6);
                tema="PAISES DE AFRICA";
                cout << "EL TEMA ES:  " << tema<<endl;

            srand((unsigned int)time(NULL));

        k=(int)(rand()%4);

        if(k==0)
        {
            palabra_original="Sudafrica";


        }

        if(k==1)
        {
            palabra_original="Argelia";

        }
         if(k==2)
        {
            palabra_original="Egipto";

        }
         if(k==3)
        {
            palabra_original="Ghana";

        }

 j=palabra_original.size();


        juego(a, palabra_most);
            break;

           case 2:
               tema="GOBERNANTES DEL PERU";
               gotoxy(40,6);
            cout << "EL TEMA ES:   " <<tema<< endl;
           srand((unsigned int)time(NULL));

        k=(int)(rand()%4);

        if(k==0)
        {
            palabra_original="Juan Velasco Alvarado";


        }

        if(k==1)
        {
            palabra_original="Nicolas de Pierola";

        }
         if(k==2)
        {
            palabra_original="Manuel Prado Ugarteche";

        }
         if(k==3)
        {
            palabra_original="Luis Sanchez Cerro";

        }

         j=palabra_original.size();

          juego(a, palabra_most);
            break;

            case 3:
                tema="PREMIO NOBEL DE FISICA";
                gotoxy(40,6);
                cout << "EL TEMA ES:  "<<tema << endl;

        srand((unsigned int)time(NULL));

        k=(int)(rand()%4);

        if(k==0)
        {
            palabra_original="Max Planck";


        }

        if(k==1)
        {
            palabra_original="Marconi";

        }
         if(k==2)
        {
            palabra_original="Albert Einstein";
        }
         if(k==3)
        {
            palabra_original="Marie Curie";

        }

         j=palabra_original.size();

           juego(a, palabra_most);
            break;

            default:
                gotoxy(40,6);
                cout<<endl<<"Escoja un nivel valido";
                break;

        }





        cout<<endl<<" Desea jugar otra vez? [Si(s) / No(n)]: ";
        cin>>letra;

             if(letra>='A' && letra<='Z')
            {
                letra+=32;
            }

        system("cls");

          } while (letra=='s');


        getch();
        return 0;



    }


    void juego(char x, string palabra_mostrar)
    {
         vidas= 10;


         char letras_ingresadas[]="                                                                                  ";
         int  l=0;



        for(int i=0 ; i<j;i++) // convierte la palabra original a  guiones para adivinarla
        {
              if(palabra_original[i]>='a' && palabra_original[i]<='z'){
                palabra_mostrar+='-';
              }

             else if(palabra_original[i]>='A' && palabra_original[i]<='Z')
            {
                palabra_mostrar+='-';
            }

              else{
                palabra_mostrar +=palabra_original[i];
              }
        }


        cout<<"vidas: "<<vidas<<endl; // muestra las vidas
        gotoxy(30,10);
        cout << "ADIVINA LA PALABRA: " << endl;
        gotoxy(50,15);
        cout<<palabra_mostrar<<endl;

       while(vidas>0 && palabra_mostrar!=palabra_original) // el juego en si. termina cuando te quedas sin vidas o adivinas la palabra
        {



                    gotoxy(50,16);
                    cout<<"Ingresa una letra: "<<endl;
                    cin>>x;


                    letras_ingresadas[l]=x;
                     system("cls");

                    bool perdiVidas=true;

                    for(int i=0 ; i<j ; i++) // compara la letra y muestra la letra  si acertaste
                    {
                        if (x == palabra_original[i])
                        {
                            perdiVidas=false;
                            palabra_mostrar[i]=x;
                        }

                    }

                    if (perdiVidas) // te quita vida si perdiste
                    {
                        vidas = vidas - 1;

                    }
                    l=l+2;
                    gotoxy(40,1);
                    cout << "BIENVENIDO AL JUEGO DEL AHORCADO" << endl;

                    gotoxy(40,6);
                    cout << "EL TEMA ES:  " << tema<<endl;

                    cout<<endl<<"vidas: "<<vidas<<endl;
                    gotoxy(30,10);
                    cout << "ADIVINA LA PALABRA: " << endl;
                    gotoxy(50,15);
                    cout<<palabra_mostrar<<endl;
                    gotoxy(2,20);
                    cout<<"Las letras que vas ingresando son: "<<letras_ingresadas<< "  "<<endl;
        }
        if(vidas>0) // mensaje de ganaste // agregar sonido alegre a esta parte 
            {
            cout << endl<< "GANASTE  !!!" << endl;
        }
        else //mensaje de perdiste y muestra la palabra  // Agregar sonido triste a esta parte
        {
            cout<< endl << "PERDISTE. LA PALABRA ERA : "<<palabra_original<< endl;
        }
    }


