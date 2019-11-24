#include "library.h"

#define NUM_CHARS 256
#define SIZE_INDEX_TABLE 100


Artist *artist_directoy[NUM_CHARS];
Snode *index_directoy[SIZE_INDEX_TABLE];
int num_index;

void print_song(Song *s);
void print_artist(Artist *a);
void insert_snode(Artist *artist, Snode *snode);
void insert_to_index_directory(Song *song);
Artist *find_artist(char* name);
void destory_song(Song*song);
void remove_snode(Artist *artist, Snode *snode);
void save_song(Song *s, FILE *fp);
void save_artist(Artist *a, FILE *fp);

void initialize() {
	for (int i = 0; i < NUM_CHARS; i++)
		artist_directoy[i] = NULL;

	for (int i = 0; i < SIZE_INDEX_TABLE; i++)
		index_directoy[i] = NULL;
}

Artist *create_artist_instance(char*name) {
	Artist*ptr_artist = (Artist*)malloc(sizeof(Artist));

	ptr_artist->name = name;
	ptr_artist->head = NULL;
	ptr_artist->next = NULL;
	ptr_artist->tail = NULL;
	return ptr_artist;
}

Song *create_song_instance(Artist *artist, char *title, char *path) {
	Song *ptr_song = (Song*)malloc(sizeof(Song));

	ptr_song->artist = artist;
	ptr_song->title = title;
	ptr_song->path = path;
	ptr_song->index = num_index++;
	return ptr_song;
}

Snode *create_snode_instance(Song *song) {
	Snode *ptr_snode = (Snode*)malloc(sizeof(Snode));
	ptr_snode->song = song;
	ptr_snode->next = NULL;
	ptr_snode->prev = NULL;
	return ptr_snode;
}

Artist *add_artist(char* name) {
	Artist *ptr_artist = create_artist_instance(name);
	Artist*p = artist_directoy[(unsigned char)name[0]];
	Artist*q = NULL;

	if (p != NULL && strcmp(p->name, name) < 0) {
		q = p;
		p = p->next;
	}

	if (p == NULL && q == NULL) {
		artist_directoy[(unsigned char)name[0]] = ptr_artist;
	}
	else if (q == NULL) { // 이름이 같은건 find_artist에서 처리되었음
		ptr_artist->next = p;
		artist_directoy[(unsigned char)name[0]] = ptr_artist;
	}
	else { // add_after(q)
		ptr_artist->next = p;
		q->next = ptr_artist;
	}
	return ptr_artist;
}

void add_song(char *artist, char*title, char*path) {
	Artist *ptr_artist = find_artist(artist);

	if (ptr_artist == NULL) { // 없으면 만들어서 넣어준다.
		ptr_artist = add_artist(artist);
	}

	// 이미 곡이 존재할 경우 예외처리 필요,, find_song(artist,title)을 추가해도 되고 이 구문에서 바로 해결도 가능
	Song*ptr_song = create_song_instance(ptr_artist, title, path);
	Snode*ptr_snode = create_snode_instance(ptr_song);

	insert_snode(ptr_artist, ptr_snode);
	insert_to_index_directory(ptr_song);
}

void insert_to_index_directory(Song *song) {
	Snode *snode = create_snode_instance(song);

	int index = song->index % SIZE_INDEX_TABLE;

	Snode*p = index_directoy[index];
	Snode*q = NULL;
	while (p != NULL && strcmp(p->song->title, song->title) < 0) {
		q = p;
		p = p->next;
	}

	if (q == NULL) {
		snode->next = p;
		index_directoy[index] = snode;
	}
	else {
		snode->next = p;
		q->next = snode;
	}
}

void insert_snode(Artist *artist, Snode *snode) {
	Snode *p = artist->head;

	if (p != NULL && strcmp(p->song->title, snode->song->title) < 0) {
		p = p->next;
	}

	if (artist->head == NULL) { //empty
		artist->head = snode;
		artist->tail = snode;
	}
	else if (p == artist->head) { // front
		snode->next = p;
		p->prev = snode;
		artist->head = snode;
	}
	else if (p == NULL) { // end
		snode->prev = artist->tail;
		artist->tail->next = snode;
		artist->tail = snode;
	}
	else { // middle
		snode->next = p;
		snode->prev = p->prev;
		p->prev->next = snode;
		p->prev = snode;
	}
}

Artist *find_artist(char* name) {
	Artist *p = artist_directoy[(unsigned char)name[0]]; // 예를들어 IU라면 첫글자 'I' 를 정수로 변환하여 인덱스로 저장한다.

	while (p != NULL && strcmp(p->name, name) < 0) {
		p = p->next;
	}

	if (p != NULL && strcmp(p->name, name) == 0)
		return p;
	else
		return NULL;
}

Snode *find_snode(Artist *artist, char* title) {
	Snode*p = artist->head;
	while (p != NULL && strcmp(p->song->title, title) != 0) {
		p = p->next;
	}

	if (p != NULL && strcmp(p->song->title, title) == 0)
		return p;
	else
		return NULL;
}


void status() {
	int flag = 1;
	for (int i = 0; i < NUM_CHARS; i++) {
		Artist *p = artist_directoy[i];
		while (p != NULL) {
			print_artist(p);
			p = p->next;
			flag = 0;
		}
	}
	if (flag) {
		printf("Nothing\n");
	}
}

void print_artist(Artist *a) {
	Snode*sn = a->head;
	while (sn != NULL) {
		print_song(sn->song);
		sn = sn->next;
	}
}

void print_song(Song *s) {
	printf("    %d: %s, %s, %s\n", s->index, s->artist->name, s->title, s->path);
}


void play(int index) {
	Snode*p = index_directoy[index%SIZE_INDEX_TABLE];
	while (p != NULL && p->song->index != index) {
		p = p->next;
	}

	if (p == NULL)
		printf("not found song\n");
	else
		printf("%s, %s is now playing\n", p->song->artist->name, p->song->title);
}

void my_remove(int index) {
	Snode*p = index_directoy[index%SIZE_INDEX_TABLE];
	Snode*q = NULL;
	while (p != NULL && p->song->index != index) {
		q = p;
		p = p->next;
	}

	if (p == NULL) {
		printf("not found song\n");
	}
	Song*song = p->song;
	if (q == NULL) { // front
		index_directoy[index%SIZE_INDEX_TABLE] = p->next;
	}
	else { // middle
		q->next = p->next;
	}
	free(p);

	Artist*artist = song->artist;
	Snode *snode = find_snode(artist, song->title);
	if (snode == NULL) {
		printf("error - someting wrong\n");
		return;
	}

	remove_snode(artist, snode);
	destory_song(song);

}

void destory_song(Song*song) {
	if (song->title != NULL)
		free(song->title);
	if (song->path != NULL)
		free(song->path);
	free(song);
}

void remove_snode(Artist *artist, Snode *s) {
	Snode *first = artist->head;
	Snode *tail = artist->tail;


	if (first == s && tail == s) {
		artist->head = NULL;
		first = NULL;
		tail = NULL;
	}
	else if (first == s) {
		first->next->prev = NULL;
		first = first->next;
		artist->head = first;
	}
	else if (tail == s) {
		tail->prev->next = NULL;
		tail = tail->prev;
		artist->tail = tail;
	}
	else {
		s->next->prev = s->prev;
		s->prev->next = s->next;
	}
	free(s);
}

void save(FILE* fp) {
	for (int i = 0; i < NUM_CHARS; i++) {
		Artist *p = artist_directoy[i];
		while (p != NULL) {
			save_artist(p,fp);
			p = p->next;
		}
	}
}

void save_artist(Artist *a,FILE *fp) {
	Snode*sn = a->head;
	while (sn != NULL) {
		save_song(sn->song,fp);
		sn = sn->next;
	}
}

void save_song(Song *s,FILE *fp) {
	if (s->artist != NULL)
		fprintf(fp, "%s#", s->artist->name);
	else
		fprintf(fp, " #");

	if (s->title != NULL)
		fprintf(fp, "%s#", s->title);
	else
		fprintf(fp, " #");

	if (s->path != NULL)
		fprintf(fp, "%s#", s->path);
	else
		fprintf(fp, " #\n");
}
