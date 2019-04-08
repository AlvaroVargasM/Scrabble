//
// Created by jonathangarcia on 08/04/19.
//

#ifndef QUEUE_USING_OOP_UNITTEST_H
#define QUEUE_USING_OOP_UNITTEST_H


#include <iostream>
#include "Logic/Tile.h"
#include "Logic/GameBoard.h"
#include "Logic/LinkedList.h"
#include "Logic/Organizer.h"
#include "Logic/Searcher.h"
#include "Logic/Stack.h"
#include "Networking/PackTile.h"
#include "Networking/Server.h"
#include "NetPackage.h"
#include "libraries/rapidjson/document.h"
#include "libraries/rapidjson/writer.h"
#include "libraries/rapidjson/stringbuffer.h"

using namespace std;
int UnitTestingLogic(){
    cout<< "\n";
    cout<< "\n";
    std::cout<< "//////////////////test Class Linked Stack////////////////// \n";
    cout<< "\n";
    cout<< "\n";
    PackTile*packTile= new PackTile('o',1);
    Stack *stack= new Stack;
    stack->push(packTile);
    stack->push(packTile);
    if(stack->size()==2){
        cout<< " Insersión de los "<< stack->size()<<" tiles acertadas mediante el método push(packTile)\n";
        cout << "accepted  OK \n";
    }
    else
        std:: cout <<"error";
    stack->pop();
    if (stack->size()==1){
        cout << "El metodo pop() se ejecutó con éxito: En nuevo tamaño  es de "<< stack->size()<<"\n";
        cout<< "\n";
        cout << "accepted   Ok\n";
    }
    cout<< "Prueba Metodo generate(), size esperado  elementos 99\n";
    stack->generate();
    if(stack->size()==99){
        cout<< "\n";
        cout<<" función  correcta del metodo Generate\n";
        cout<< "\n";
        cout << "accepted   Ok\n";
    }
    else
        cout <<"fatal error\n";


    cout<< "Comprobación de metodo Swap\n";

    PackTile*packTile1= new PackTile('.',-1);
    static  PackTile array[]={*packTile1,*packTile1,*packTile1,*packTile1,*packTile1,*packTile1,*packTile1};
    stack->swap(array);
    if (array[0].getLetter()!=array[1].getLetter()!=array[1].getLetter()){
        cout<< "\n";
        cout << "Prueba  de aleatoriedad acertada\n accepted  OK \n";
    }
    else
        cout<<"error Faltal";
    cout<< "\n";
    cout<< "\n";
    std::cout<< "//////////////////test Class Tile////////////////// \n";
    cout<< "\n";
    cout<< "\n";


    Tile *tile= new Tile();
    cout<< "\n";
    cout<< " Se crea un Tile  para ser asignado a la Linked List\n";

    tile->setColumn(1);
    cout<< "  Una inserción de columna, Valor  esperado  es posición 1\n";
    if(tile->getColumn()==1){
        cout<< "\n";
        cout << "accepted  OK\n";
    }
    else
        "Error  de algortimo\n";
    tile->setRow(1);
    cout<< "\n";
    cout<< " Una inserción  de fila, valor  esperado 1 \n";
    if (tile->getRow()==1){
        cout<< "\n";
        cout << "accepted  OK\n";
    }
    else
        "Error  de algortimo\n";

    tile->setLetter('X');
    cout<< "\n";
    cout<< "   Se inserta en el Tile  un  caracter  (-X-) se espera que la función  reciba  un  X de respuesta\n";
    if(tile->getLetter()=='X'){
        cout << "True\n";
        cout << "accepted  OK\n";

    }
    tile->setPoints(8);
    cout<< "   Se inserta en el Tile  un valor  númerico, el valor  esperado es : (-8-) \n";
    if(tile->getPoints()==8){
        cout << "True\n";
        cout << "accepted  OK\n";

    }
    cout<< "Finaliza el test de Clase Tile";
    cout<< "\n";
    cout<< "\n";
    std::cout<< "//////////////////test Class Linked List////////////////// \n";
    cout<< "\n";
    cout<< "\n";
    LinkedList *linkedList= new  LinkedList;
    Tile *tile1= new Tile();
    tile1->setLetter('c');
    tile1->setPoints(4);
    tile1->setRow(1);
    tile1->setColumn(2);
    tile1->setMultiplier(4);


    linkedList->addFront(*tile);
    linkedList->addFront(*tile1);
    if(linkedList->getSize()==2){
        cout<< "\n";
        cout<< "\n";
        cout<< " El Método addFront  se ha ejecutado correctamente en LinkedList se espera un size de  valor 2\n";
        cout<< "\n";
        cout<< "\n";
        cout<<  "El tamaño de la lista Enlazada  es de "<< linkedList->getSize()<<"\n";
        cout<< "\n";
        cout<< "\n";
        cout<<"Se comprueba  que el proceso de inserciones de  la lista se raliza correctamente\n";


        cout << "accepted   Ok\n";}
    else
        cout << "fatal error";

    cout<< "\n";
    cout<< "\n";
    cout << " Se insertan  Dos Tiles,   ubicados en las posiciones [I][J] 11 y 12\n";
    cout<< "\n";
    cout<< "\n";
    cout<< " se ejecuta el método  isHorizontal() que compara si la palabra que se va a  formar es  horizontal\n";

    if(linkedList->isHorizontal()){
        cout<< "True\n";
        cout << "accepted   Ok\n";
    }
    else
        cout <<"False, Palabra vertical\n";
    cout<< "\n";
    cout<< "\n";

    linkedList->printList();
    cout<< "\n";
    cout<< "\n";
    cout <<"Testing método DeleteEndNode";
    cout<< "\n";
    cout<< "\n";
    cout<< "Se espera que  al final la lista tenga un tamaño  de 1";
    cout<< "\n";
    cout<< "\n";
    linkedList->deleteEndNode();

    if (linkedList->getSize()==1){
        cout << "\n";

        cout << "el Size de la lista es de " << linkedList->getSize();
        cout << "\n";

        cout << "accepted   Ok\n";
        cout << "\n";

        linkedList->printList();
    }
    else

        cout<< "error";
    cout << "\n";
    cout <<" /////////////////////////////FIn test Clase Linked List//////////////////////////////";
    cout << "\n";
    cout << "\n";


    cout<< "///////////////////////TEST CLASE GAMEBOARD//////////////////////////////////////" ;
    cout << "\n";

    GameBoard* gameBoard=new GameBoard();
    cout << "\n";
    cout << "\n";

    cout<< "Se  insertan  dos Tile en la matriz GameBoard";
    cout << "\n";

    gameBoard->changeTile(0,0,'X',8);
    gameBoard->changeTile(1,0,'A',3);

    cout << "\n";
    cout<< "Se comprueba la que se insertaron dos elementos  en la matriz GameBoard\n";

    cout << "\n";
    gameBoard->printLetters();
    cout << "\n";

    cout << "El valor de retorno esperado es una letra (-A-)\n";

    if (gameBoard->getTile(1,0).getLetter()=='A'){
        cout << "accepted   Ok\n";
        cout << "\n";
        cout<< "Método GetTile Funciona de forma Correcta, la letra insertada es:\n "<< gameBoard->getTile(1,0).getLetter()<<"\n";
        cout << "\n";

    }

    cout << "El valor de retorno esperado es una letra (-X-)\n";
    if (gameBoard->getTile(0,0).getLetter()=='X'){
        cout << "accepted   Ok\n";
        cout << "\n";
        cout<< "Método GetTile Funciona de forma Correcta, la letra insertada es: \n "<< gameBoard->getTile(0,0).getLetter()<<"\n";
        cout << "\n";



    }


    cout<< "///////////////////////Fin TEST  clase  Gameboard //////////////////////////////////////" ;
    cout << "\n";



    cout<< "///////////////////////INICIO DE PRUEBA DE LA CLASE SEARCHER //////////////////////////////////////" ;
    cout << "\n";
    LinkedList *linkedList3= new LinkedList;
    Searcher *searcher= new Searcher;




    return 0;
}

int UnitTestingNetworking(){


    cout<< "\n";
    cout<< "\n";
    std::cout<< "//////////////////Test Class PackTile////////////////// \n";
    cout<< "\n";
    cout<< "\n";
    PackTile *pt= new  PackTile(1,3,'A',3);

    cout<< " se crea un test de un objeto Packtile que tendrá  en sus valores de input PackTile(1,3,'A',3).\n";
    cout<< " Se espera  que los valores de Salida   al consultar los métodos sean los  de La instancia  anterior\n";


    if(  pt->getLetter()=='A'){
        cout<< "True\n";
        cout<< "Accepted    Ok\n";
        cout<< "El  caracter que se intertó  fue\n"<<pt->getLetter();
        cout<< "\n";

    }
    if(pt->getValue()==3){
        cout<< "True\n";
        cout<< "Accepted    Ok\n";
        cout<< "El  valor que se intertó  fue\n"<<pt->getValue()<<"\n";
        cout<< "\n";
    }
    if(  pt->getRow()==1){
        cout<< "True\n";
        cout<< "Accepted    Ok\n";
        cout<< "El valor  de  la FILA  en la que se intertó fue\n"<<pt->getRow()<<"\n";
        cout<< "\n";
    }
    if(  pt->getColumn()==3){
        cout<< "True\n";
        cout<< "Accepted    Ok\n";
        cout<< "El  valor de la COLUMNA que se intertó  fue\n"<<pt->getLetter()<<"\n";
        cout<< "\n";
    }
    else
        cout<<"error de Algoritmo";

    cout<< "\n";
    cout<< "\n";
    std::cout<< "//////////////////Final del test PackTile////////////////// \n";
    cout<< "\n";
    cout<< "\n";
    cout<< "\n";
    cout<< "\n";
    std::cout<< "//////////////////Test Class PackTile////////////////// \n";
    cout<< "\n";
    cout<< "\n";






    return  0;

}

#endif //QUEUE_USING_OOP_UNITTEST_H
