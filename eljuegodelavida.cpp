#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include <unistd.h>
#include<time.h>
using namespace std;


/// Al inicar cada opción ponemos en el tablero todas las células como muertas
/// para después poder ir insertando las células vivas.

void inicio_partida (int celulamadref[15][20], int celulahijaf[15][20])
{
    int i,j;
    for (i=0; i<15; i++) /// Se implementa todo el tablero principal a cero
    {
        for (j=0; j<20; j++)
        {
            celulamadref[i][j]=0;

        }

    }
    for (i=0; i<15; i++) /// Se implementa todo el tablero auxiliar a cero
    {
        for (j=0; j<20; j++)
        {
            celulahijaf[i][j]=0;

        }

    }
}

///muestra los valores introducidos manualmente por pantalla

void mostrar_evolucion_provisional (int celulahijaf[15][20])
{
    int i,j,cont,cont1;
    cont=0;
    cont1=0;
    system("cls");
    cout<<"   ";
    do
    {
        do
        {
            cout<<cont;
            cont++;
        }
        while(cont<10);
        cont=0;
        cont1++;
        if (cont1==2){cout<<endl;}
    }
    while (cont1<2);

    cont=0;
    cout<<"   ";
    do
    {
        cout<<"-";
        cont++;
        if (cont==20){cout<<endl;}
    }
    while(cont<20);



    cont=0;
    for (i=0; i<15; i++)
    {
        for (j=0; j<20; j++)
        {
            if (j==0)
            {
                if (cont<10)
                {
                    cout<<" "<<cont<<"|";
                    cont++;
                }
                else
                {
                    cout<<cont<<"|";
                    cont++;
                }
            }
            if (celulahijaf[i][j]==1)
            {
                cout<<char(219);
            }
            else
            {
                cout<<char(32);
            }
        }
        cout<<endl;
    }
}


///En esta función se introducen manualmente las células
void introcelulas (int celulahijaf[15][20])
{
    int f,c;
    char opcion;
    opcion='N';
    do
    {
        cout<<"Introduciremos celulas para hacer nuestros patrones"<<endl;
        cout<<"Puedes escoger: "<<endl;
        cout<<"de la fila 0 a la fila 19 y de la columna 0 a la 14"<<endl;
        cout<<"dime el numero de la fila: ";
        cin>>f;
        cout<<"dime el numero de la columna: ";
        cin>>c;
        celulahijaf[f][c]=1;
        mostrar_evolucion_provisional(celulahijaf);
        cout<<endl<<endl<<"Si quieres finalizar de introducir celulas y pasar a visualizar las evoluciones introduce la 'Y'";
        cin>>opcion;
        cout<<endl;
    }
    while(opcion !='Y');
}


///En esta función se introducen aleatoriamente un numero de células definidas por el usuario


void introcelulasrandom (int celulahijaf[15][20])
{
    int f,c,cont,celula;
    int opcion;
    cout<<"Introduce la cantidad de celulas que quieres generar aleatoriamente"<<endl;
    cin>>cont;
    srand(time(NULL));
    celula=1;
    do
    {
        do
        {
            f=rand() % 14;
            c=rand() % 20;
            usleep(500000);
        }
        while(celulahijaf[f][c]!=0);
        celulahijaf[f][c]=1;
        cout<<endl<<"celula: "<<celula<<endl;
        mostrar_evolucion_provisional(celulahijaf);
        cont--;

        celula++;
    }
    while(cont>0);
}

///En esta funcion se muestran los patrones predeterminados que puede introducir el Jugador
void patronesfun (int patronesf[5][17])
{
    int i,j,cont,cont1;
    int matrizpatrones[5][17];
    int posicionespatrones[18]={18,27,31,32,35,37,39,40,41,44,45,47,48,53,54,60,62,65};
    cont=0;
    cont1=0;
     for (i=0; i<5; i++) /// ponemos el patron a mostrar con todas las células muertas.
     {
        for (j=0; j<17; j++)
        {

                matrizpatrones[i][j]=0;
        }
    }
    for (i=0; i<5; i++) /// Introducimos los patrones de las figuras que vamos a evaluar.
    {
        for (j=0; j<17; j++)
        {
            if (posicionespatrones[cont1]==cont)
            {
                matrizpatrones[i][j]=1;
                cont1++;
            }
            cont++;
        }
    }
    cout<<endl<<endl<<"  1   2   3   4"<<endl;
    for (i=0; i<5; i++)
    {
        for (j=0; j<17; j++)
        {
            if (matrizpatrones[i][j]==1)
            {
                cout<<char(219);
            }
            else
            {
                cout<<char(32);
            }
        }
        cout<<endl;
    }



}


/// Menu para escoger la igura predefinida
int menupatrones(int opcionpatron)
{
    int p[5][17];
    cout<<"================================="<<endl;
    cout<<"Escoje que figura quieres mostrar"<<endl;
    cout<<"================================="<<endl;
    cout<<"    1-Barco"<<endl;
    cout<<"    2-Faro"<<endl;
    cout<<"    3-Deslizador"<<endl;
    cout<<"    4-Pentomimo"<<endl;
    cout<<"================================="<<endl;
    cout<<"================================="<<endl<<endl;
    patronesfun(p);
    cout<<"Figura: ";
    cin>>opcionpatron;
    return opcionpatron;
}


/// Patron de la Figura 1 Barco
void patron_barco (int celulahijaf[15][20])
{
    int i,j,cont,cont1,f,c;
    int matrizpatron_barco[5]={0,3,5,7,8};
    cout<<"Introduce el numero de fila y columna donde quieres que se muestre el barco"<<endl;
    cout<<"Introduce el numero de fila, valores 0 a 12"<<endl;
    cin>>f;
    cout<<endl<<"Introduce el numero de fila, valores 0 a 17"<<endl;
    cin>>c;
    cont=0;
    cont1=0;
    for (i=f; i<f+3; i++)
    {
        for (j=c; j<c+3; j++)
        {
            if (matrizpatron_barco[cont1]==cont)
            {
                celulahijaf[i][j]=1;
                cont1++;
            }
            cont++;
        }
    }

}

/// Patron de la Figura 2 Faro
void patron_faro (int celulahijaf[15][20])
{
    int i,j,f,c,cont,cont1;
    int matrizpatron_faro[3]={3,4,5};
    cout<<"Introduce el numero de fila y columna donde quieres que se muestre el faro"<<endl;
    cout<<"Introduce el numero de fila, valores 0 a 12"<<endl;
    cin>>f;
    cout<<endl<<"Introduce el numero de columna, valores 0 a 17"<<endl;
    cin>>c;
    cont=0;
    cont1=0;
    for (i=f; i<f+3; i++) /// Introducimos el patron de las figuras que vamos a evaluar.
    {
        for (j=c; j<c+3; j++)
        {
            if (matrizpatron_faro[cont1]==cont)
            {
                celulahijaf[i][j]=1;
                cont1++;
            }
            cont++;
        }
    }
}

/// Patron de la Figura 3 Deslizador
void patron_deslizador (int celulahijaf[15][20])
{
    int i,j,f,c,cont,cont1;
    int matrizpatron_deslizador[5]={1,4,5,6,8};
    cout<<"Introduce el numero de fila y columna donde quieres que se muestre el deslizador"<<endl;
    cout<<"Introduce el numero de fila, valores 0 a 12"<<endl;
    cin>>f;
    cout<<endl<<"Introduce el numero de fila, valores 0 a 17"<<endl;
    cin>>c;
    cont=0;
    cont1=0;
    for (i=f; i<f+3; i++)
    {
        for (j=c; j<c+3; j++)
        {
            if (matrizpatron_deslizador[cont1]==cont)
            {
                celulahijaf[i][j]=1;
                cont1++;
            }
            cont++;
        }
    }
}

/// Patron de la Figura 4 Pentomimo
void patron_pentomimo (int celulahijaf[15][20])
{
    int i,j,f,c,cont,cont1;
    int matrizpatron_pentomimo[5]={1,2,3,4,7};
    cout<<"Introduce el numero de fila y columna donde quieres que se muestre el faro"<<endl;
    cout<<"Introduce el numero de fila, valores 0 a 12"<<endl;
    cin>>f;
    cout<<endl<<"Introduce el numero de fila, valores 0 a 17"<<endl;
    cin>>c;
    cont=0;
    cont1=0;
    for (i=f; i<f+3; i++)
    {
        for (j=c; j<c+3; j++)
        {
            if (matrizpatron_pentomimo[cont1]==cont)
            {
                celulahijaf[i][j]=1;
                cont1++;
            }
            cont++;
        }
    }
}


/// Aqui es donde se ejecuta la opcion del menú de escoger figura predeterminada
void patronescogido(int celulahijap[15][20], int opcionpatron)
{
    switch (opcionpatron)
    {
        case 1:
            {
                patron_barco(celulahijap);
                break;
            }
        case 2:
            {
                patron_faro(celulahijap);
                break;
            }
        case 3:
            {
                patron_deslizador(celulahijap);
                break;
            }
        case 4:
            {
                patron_pentomimo(celulahijap);
                break;
            }
    }
}

/// Muestra las generaciones de células por pantalla

void mostrar_evolucion (int celulamadref[15][20])
{

    int i,j;
    for (i=0; i<15; i++)
    {
        for (j=0; j<20; j++)
        {
            if (celulamadref[i][j]==1)
            {
                cout<<char(219);
            }
            else
            {
                cout<<char(32);
            }
        }
        cout<<endl;
    }
}



/// Verificamos si la celula está viva o muerta. Y se pasa al tablero auxiliar.
void celula_viva_muerta (int celulamadref[15][20], int celulahijaf[15][20])
{
    int i,j,cont;
    for (i=0; i<15; i++)
    {
        for (j=0; j<20; j++)
        {
            cont=0;
            if(i-1 >= 0 && j-1 >= 0)
            {
                if (celulamadref[i-1][j-1]==1)
                {
                    cont++;

                }
            }

            if(i-1 >= 0)
            {
                 if (celulamadref[i-1][j]==1)
                {
                    cont++;


                }
            }
            if(i-1 >= 0 && j+1 < 20)
            {
                if (celulamadref[i-1][j+1]==1)
                {
                    cont++;

                }
            }
            if(j-1 >= 0)
            {
                if (celulamadref[i][j-1]==1)
                {
                    cont++;

                }
            }
            if(j+1 < 20)
            {
                if (celulamadref[i][j+1]==1)
                {
                    cont++;
                }
            }
            if(i+1 < 15 && j-1 >= 0)
            {
                if (celulamadref[i+1][j-1]==1)
                {
                    cont++;

                }
            }
            if(i+1 < 15)
            {
                if (celulamadref[i+1][j]==1)
                {
                    cont++;

                }
            }
            if(i+1 < 15 && j+1 < 20)
            {
                if (celulamadref[i+1][j+1]==1)
                {
                    cont++;

                }
            }

            if (celulamadref[i][j]==1)
            {
                if(cont==2 || cont==3)
                {
                    celulahijaf[i][j]=1;
                }
                else
                {
                    celulahijaf[i][j]=0;
                }
            }
            else
            {
                if(cont==3)
                {
                    celulahijaf[i][j]=1;
                }
                else
                {
                    celulahijaf[i][j]=0;
                }
            }
        }
    }
}


/// En esta funcion una vez hemos recorrido el tablero principal y guardados en el tablero auxiliar
///Pasamos los datos del tablero auxiliar al principal para ir realizando las generaciones.
void duplicado_tablero (int celulamadref[15][20], int celulahijaf[15][20])
{
    int i,j;
    for(i=0; i<15; i++)
    {
        for(j=0; j<20; j++)
        {
            celulamadref[i][j]=celulahijaf[i][j];
        }
    }
}


///En esta funcion evolucionan las generaciones manualmente.
void evolucion_generacion_generacion (int celulamadref[15][20], int celulahijaf[15][20])
{
    int generacion;
    char evolucion;
    evolucion='N';
    generacion=0;
    do
    {
        cout<<"generacion "<<generacion+1<<endl<<endl;
         celula_viva_muerta(celulamadref, celulahijaf);
         duplicado_tablero(celulamadref,celulahijaf);
         mostrar_evolucion(celulamadref);
        cout<<endl<<"Si quieres seguir con la evolucion pulsa S, si no pulsa F"<<endl;
        cin>>evolucion;
        generacion++;
        system("cls");
    }
    while(evolucion !='F');
}


///En esta funcion evolucionan las generaciones automaticamente.
///Se pide al jugador que introduzca numero de generaciones a mostrar
///Y la velocidad del automatismo.
void evolucion_generacion_N (int celulamadref[15][20], int celulahijaf[15][20])
{
    int opcion,generacion,speed;
    cout<<"Introduce el numero de generaciones que quieres mostrar del patron"<<endl;
    cin>>opcion;
    cout<<endl;
    speed=0;
    cout<<"Introduce la velocidad a la que quiere que evolucione el patron desde 0 hasta 999999"<<endl;
    cin>>speed;
    cout<<endl;
    generacion=0;
    do
    {
        cout<<"generacion "<<generacion+1<<endl<<endl;
        celula_viva_muerta(celulamadref, celulahijaf);
        duplicado_tablero(celulamadref,celulahijaf);
        mostrar_evolucion(celulamadref);
        generacion++;
        usleep(speed);

        if (generacion<=opcion-1)
        {
            system("cls");
        }
    }
    while(generacion<opcion);
    system("pause");
    system("cls");


}


///En esta función el jugador determina si quiere una evolución automática o manual
void tipo_evolucion (int celulamadref[15][20], int celulahijaf[15][20])
{
    char eleccion;
    cout<<"Indica si la generacion de celulas las quieres ver: "<<endl;
    cout<<"Si continua marca C, si generacion a generacion marca cualquier otra"<<endl;
    cin>>eleccion;
    if (eleccion=='C')
    {
         evolucion_generacion_N(celulamadref,celulahijaf);
    }
    else
    {

        evolucion_generacion_generacion(celulamadref,celulahijaf);
    }
}

///Ahora empezamos con El menu de Ayuda.

///En esta funcion nos muestra la Historia del Juego de la vida
void Historia()
{
    cout<<""<<endl;
    cout<<"HISTORIA DEL JUEGO"<<endl<<endl;
    cout<<"El juego de la vida es un automata celular diseñado por el matematico britanico "<<endl;
    cout<<"John Horton Conway en 1970."<<endl<<endl;
    cout<<"Hizo su primera aparicion pública en el numero de octubre de 1970 de la revista Scientific "<<endl;
    cout<<"American, en la columna de juegos matematicos de Martin Gardner. Desde un punto de vista "<<endl;
    cout<<"teorico, es interesante porque es equivalente a una maquina universal de Turing, es decir, todo lo "<<endl;
    cout<<"que se puede computar algoritmicamente se puede computar en el juego de la vida."<<endl<<endl;
    cout<<"Desde su publicacion, ha atraido mucho interes debido a la gran variabilidad de la evolucion de los "<<endl;
    cout<<"patrones. Se considera que la vida es un buen ejemplo de emergencia y autoorganizacion. Es "<<endl;
    cout<<"interesante para los cientificos, matematicos, economistas y otros observar como patrones "<<endl;
    cout<<"complejos pueden provenir de la implementacion de reglas muy sencillas."<<endl<<endl;
    cout<<"Para muchos aficionados, el juego de la vida solo era un desafio de programacion y una manera "<<endl;
    cout<<"divertida de usar ciclos de la CPU. Para otros, sin embargo, el juego adquirio mas connotaciones "<<endl;
    cout<<"filosoficas. Desarrollo un seguimiento casi fanatico a lo largo de los años 1970 hasta mediados de "<<endl;
    cout<<"los 80."<<endl<<endl;
    cout<<"Pulsa el retorno para volver al menu de Ayuda"<<endl;

}

///En esta funcion se explica al jugador en que consiste el Juego de la vida
void Funcionamiento()
{
    cout<<""<<endl;
    cout<<"EN QUE CONSISTE EL JUEGO DE LA VIDA"<<endl<<endl;
    cout<<"El juego de la vida es en realidad un juego de cero jugadores, lo que quiere decir que su evolucion "<<endl;
    cout<<"esta determinada por el estado inicial y no necesita ninguna entrada de datos posterior. El 'tablero'"<<endl;
    cout<<"de juego' es una malla formada por cuadrados ('celulas') que se extiende por el infinito en todas las "<<endl;
    cout<<"direcciones. Cada celula tiene 8 celulas vecinas, que son las que estan proximas a ella, incluidas las "<<endl;
    cout<<"diagonales. Las celulas tienen dos estados: estan 'vivas' o 'muertas' (o 'encendidas' y 'apagadas'). "<<endl;
    cout<<"El estado de la malla evoluciona a lo largo de unidades de tiempo discretas (se podria decir que por "<<endl;
    cout<<"turnos). El estado de todas las celulas se tiene en cuenta para calcular el estado de las mismas al "<<endl;
    cout<<"turno siguiente. Todas las celulas se actualizan simultaneamente."<<endl<<endl;
    cout<<"Las transiciones dependen del numero de celulas vecinas vivas:"<<endl<<endl;
    cout<<"Una celula muerta con exactamente 3 celulas vecinas vivas 'nace' (al turno siguiente estara viva)."<<endl;
    cout<<"Una celula viva con 2 o 3 celulas vecinas vivas sigue viva, en otro caso muere o permanece muerta "<<endl;
    cout<<"(por 'soledad' o 'superpoblacion')."<<endl<<endl;
    cout<<"Pulsa el retorno para volver al menu de Ayuda"<<endl;
}


///En esta funcion se explica al jugador las diferentes opciones que se necesitan
///mientras se desarrolla El Juego de la vida.
void Opciones ()
{

    cout<<"OPCIONES DEL JUEGO"<<endl<<endl;
    cout<<"1-Introducir celulas vivas manualmente"<<endl<<endl;
    cout<<"     -Iras anyadiendo manualmente el numero de celulas vivas que consideres oportuno, para ello "<<endl;
    cout<<"     tienes que indicar en que fila y columna quieres que se inserten y posteriormente decidir si "<<endl;
    cout<<"     quieres pasar manualmente las generaciones o que se realicen automáticamente"<<endl<<endl;
    cout<<"     -Si decides que se pasen automáticamente tendrás que indicar el número de "<<endl;
    cout<<"     generaciones que quieres pasar y la velocidad de paso de estas."<<endl<<endl<<endl;
    cout<<"2-Generando Aleatoriamente la configuracion inicial"<<endl;
    cout<<"     -Primero se te indica que numero de celulas quieres que introduzca el sistema. Y este "<<endl;
    cout<<"     aleatoriamente las ira repartiendo por el tablero. Es posible que si pones un numero "<<endl;
    cout<<"     pequeño de celulas o se mueran todas pronto o queden estáticas."<<endl<<endl<<endl;
    cout<<"3-Introduciendo una Figura Predefinida"<<endl;
    cout<<"     -Nos mostrara las 4 figuras predefinidas que tenemos para cargar en el tablero. Una vez "<<endl;
    cout<<"     escogida la figura introduciremos la fila y la columna donde queramos que se introduzca "<<endl;
    cout<<"     esta. A continuacion podremos escoger si hacer la evolucion de las generaciones "<<endl;
    cout<<"     manualmente o automaticamente. Si escogemos automaticamente Nos pedira tambien que "<<endl;
    cout<<"     introduzcamos la cantidad de generaciones que queremos mostrar y la velocidad de evolucion. "<<endl<<endl;
    cout<<"Pulsa el retorno para volver al menu de Ayuda"<<endl;

}

///En esta Funcion se muestra el Menu de ayuda del Juego de la Vida.
int menu_ayuda(int opcionp2)
{
    system("cls");
    printf("\n\nMenu de Ayuda y Reglas del Juego de la vida\n\n");
    printf("1-Historia del Juego de la vida. \n");
    printf("2-Funcionamiento del Juego de la vida\n");
    printf("3-Opciones del Juego\n");
    printf("4-Volver al Menu Principal\n");
    scanf("%d", &opcionp2);
    fgetc(stdin);
    return opcionp2;
}

///En esta función se ejecutan las opciones del Menú de Ayuda.
void ayuda(int opcionp2)
{
    int opcion,b;
    do
    {
        opcion=menu_ayuda(b);
        switch (opcion)
        {
            case 1:
            {
                system("cls");
                Historia();
                fgetc(stdin);
                break;
            }
            case 2:
            {
                system("cls");
                Funcionamiento();
                fgetc(stdin);
                break;
            }
            case 3:
            {
                system("cls");
                Opciones();
                fgetc(stdin);
                break;
            }
        }
    }
    while (opcion!=4);
}


///Esta Función nos Muestra el Menú Principal del Juego de la vida.
int Menujuego (int opcionp) //menú de la agenda
{
    system("cls");
    printf("\n\nMenu Inicial Juego de la vida\n\n");
    printf("1-Introduce Las celulas vivas manualmente. \n");
    printf("2-Generando aleatoriamente la configuracion Inicial\n");
    printf("3-Introduciendo una figura predefinida\n");
    printf("4-Reglas y Ayuda\n");
    printf("5-FIN\n");
    scanf("%d", &opcionp);
    fgetc(stdin);
    return opcionp;
}



main()
{
    int a,b,opcion,opcionpat;
    int celulamadre[15][20];
    int celulahija[15][20];
    system ("color 0E");
    do
    {
        opcion=Menujuego(a);
        switch (opcion)
        {
            case 1:
            {
                inicio_partida(celulamadre,celulahija);
                introcelulas(celulahija);
                duplicado_tablero(celulamadre,celulahija);
                tipo_evolucion(celulamadre,celulahija);
                mostrar_evolucion(celulamadre);
                break;
            }
            case 2:
            {
                inicio_partida(celulamadre,celulahija);
                mostrar_evolucion(celulahija);
                introcelulasrandom(celulahija);
                duplicado_tablero(celulamadre,celulahija);
                tipo_evolucion(celulamadre,celulahija);
                break;
            }
            case 3:
            {
                inicio_partida(celulamadre,celulahija);
                opcionpat=menupatrones(b);
                patronescogido(celulahija,opcionpat);
                mostrar_evolucion_provisional(celulahija);
                duplicado_tablero(celulamadre,celulahija);
                tipo_evolucion(celulamadre,celulahija);
                break;
            }
            case 4:
            {
                ayuda(b);
                break;
            }
        }
    }
    while (opcion!=5);
}















