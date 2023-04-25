class game
{
private:
    /* data */
public:
    game(/* args */);
    ~game();
};

game::game(/* args */)
{
}

game::~game()
{
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

