#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include "string_tools.h"
#include "library.h"

void process_command();
void handle_add();
void handle_search();
void handle_load();
void handle_play();
void handle_remove();
void handle_save();

int main() {
	initialize();
	handle_load();
	process_command();
}

void load(FILE *fp) {
	char buffer[BUFFER_LENGTH];
	char *name, *title, *path;
	
	while (1) {
		if (read_line(fp, buffer, BUFFER_LENGTH) <= 0)
			break;

		name = strtok(buffer, "#");
		if (strcmp(name, " ") == 0)
			name = NULL;
		else
			name = strdup(name);

		title = strtok(NULL, "#");
		if (strcmp(title, " ") == 0)
			title = NULL;
		else
			title = strdup(title);

		path = strtok(NULL, "#");
		if (strcmp(path, " ") == 0)
			path = NULL;
		else
			path = strdup(path);

		add_song(name, title, path);
	}
}

void handle_load() {
	char file_name[BUFFER_LENGTH];
	printf("Data file name ? ");
	if (read_line(stdin, file_name, BUFFER_LENGTH) <= 0)
		return;

	FILE *fp = fopen(file_name, "r");
	if (fp == NULL) {
		printf("not found file\n");
		return;
	}
	else
		load(fp);
	fclose(fp);
}

void process_command() {
	char command_line[BUFFER_LENGTH];
	char*command;

	while (1) {
		printf("$ ");
		if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0)
			continue;
		command = strtok(command_line, " ");
		if (strcmp(command, "add") == 0)
			handle_add();
		else if (strcmp(command, "search") == 0)
			handle_search();
		else if (strcmp(command, "play") == 0)
			handle_play();
		else if (strcmp(command, "remove") == 0)
			handle_remove();
		else if (strcmp(command, "save") == 0) {
			char *tmp = strtok(NULL, " ");
			if(strcmp(tmp,"as")==0)
				handle_save();
		}
		else if (strcmp(command, "status") == 0)
			status();
		else if (strcmp(command, "exit") == 0)
			break;
	}
}

void handle_add() {
	char buffer[BUFFER_LENGTH];
	char *artist = NULL, *title = NULL, *path = NULL;

	printf("    Artist: ");
	if (read_line(stdin, buffer, BUFFER_LENGTH) > 0) // 반환값이 0보다 크면 한글자 이상
		artist = strdup(buffer);

	printf("    Title: ");
	if (read_line(stdin, buffer, BUFFER_LENGTH) > 0)
		title = strdup(buffer);

	printf("    Path: ");
	if (read_line(stdin, buffer, BUFFER_LENGTH) > 0)
		path = strdup(buffer);

	add_song(artist, title, path);
}

void handle_remove() {
	int number = atoi(strtok(NULL, " "));
	my_remove(number);
}

void handle_search() {
	char name[BUFFER_LENGTH], title[BUFFER_LENGTH];

	printf("    Artist: ");
	if (read_line(stdin, name, BUFFER_LENGTH) <= 0) {
		printf("not found name");
		return;
	}

	printf("    Title: ");
	int title_len = read_line(stdin, title, BUFFER_LENGTH);

	if (title_len <= 0)
		search_song(name,NULL);
	else
		search_song(name,title);
}

void handle_play() {
	int number = atoi(strtok(NULL, " "));
	play(number);
}

void handle_save() {
	char *file_name = strtok(NULL, " ");
	FILE *fp = fopen(file_name, "w");
	save(fp);
	fclose(fp);
}

void search_song(char* name, char* title) {
	Artist *ptr_artist = find_artist(name);
	if (ptr_artist == NULL) {
		printf("not found artist\n");
		return;
	}

	if (title == NULL) {
		printf("Found:\n");
		print_artist(ptr_artist);
	}
	else {
		Snode *ptr_snode = ptr_artist->head;
		while (ptr_artist != NULL && strcmp(ptr_snode->song->title, title) != 0)
			ptr_snode = ptr_snode->next;

		if (ptr_snode != NULL && strcmp(ptr_snode->song->title, title) == 0) {
			printf("Found:\n");
			print_song(ptr_snode->song);
		}
		else {
			printf("not found song\n");
			return;
		}
	}
}
