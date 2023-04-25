class gotoXy
{
private:
    /* data */
public:
    gotoXy(/* args */);
    ~gotoXy();
};

gotoXy::gotoXy(/* args */)
{
}

gotoXy::~gotoXy()
{
}

void gotoxy(int x, int y) // ubicacion de la letras
{
    HANDLE hCon;
    hCon = GetStdHandle (STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hCon, dwPos);
}


