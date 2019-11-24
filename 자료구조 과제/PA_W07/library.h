#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 200

typedef struct song Song;
typedef struct snode Snode;
typedef struct artist Artist;

struct song
{
	Artist *artist;
	char *title;
	char *path;
	int index;
};

struct snode
{	
	Snode *next, *prev;
	Song *song;
};

struct artist
{
	char *name;
	Artist *next;
	Snode *head, *tail;
};

void initialize();
void add_song(char *artist, char*title, char*path);
void search_song(char* name, char* title);
void load(FILE *fp);
Artist *create_artist_instance(char*name);
void status();
Artist *add_artist(char* name);
void play(int index);
void my_remove(int index);
void save(FILE* fp);

