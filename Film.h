#pragma once
#include "widget.h"
#include <string>

class Film : public Widget {
	std::string IconPath;
	int counter ;
	std::string title;
	std::string actors;
	std::string description;
	std::string genre;
	std::string date;
	
public:
	void update();
	void draw();
	void setPath(std::string path) { IconPath = path; };
	std::string getPath() { return IconPath; };
	std::string getTitle() { return title; }
	void setTitle(std::string t) { title = t; }
	std::string getActors() { return actors; }
	void setActors(std::string act) { actors = act; }
	std::string getDescription() { return description; }
	void setDescription(std::string descr) { description = descr; }
	std::string getGenre() { return genre; }
	void setGenre(std::string gen) { genre = gen; }
	std::string getDate() { return date; }
	void setDate(std::string d) { date = d; }
	


};
