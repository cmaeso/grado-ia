//
// Created by c.maeso.2017 on 30/11/2023.
//

#ifndef ED1TWITTER_TWEETS_H
#define ED1TWITTER_TWEETS_H

typedef struct lista{
    char tweet[141];
    struct lista * sig;
} tLista;

typedef struct nodo{
    char hashtag[141];
    struct nodo* izq;
    struct nodo*der;
    tLista *listaTweets;
}tNodo;

typedef tNodo* tArbol;
int esArbolVacio (tArbol a);

void crearArbolVacio(tArbol * arbol);
void crearNodo(tArbol* arbol, char hashtag[141]);
void addTweet(tArbol * arbol, char tweet[141]);
int esMayor(char tweet1[141], char tweet2[141]);
void insertarNodo(tArbol* arbol, char hashtag[141]);
int pertenece(tArbol arbol, char ht[141]);
void imprimirElemento(char ht[141]);
void imprimirArbol(tArbol a);
#endif //ED1TWITTER_TWEETS_H
