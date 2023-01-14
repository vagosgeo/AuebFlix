#include "App.h"
#include "Film.h"
#include "tinyxml2.h"
#include <iostream>

using namespace tinyxml2;
using namespace std;

void readFilmData(list<Film*>& list) {

    XMLDocument doc;
    const char* path = "assets/test.xml";
    char amountText[100];
    // Load the XML file into the Doc instance
    doc.LoadFile(path);
    // Get root Element
    
    XMLElement* pRootElement = doc.RootElement();
    
    if (NULL != pRootElement) {
        
        //Get 'films' Child
        XMLElement* pAccounts = pRootElement->FirstChildElement("Films");
        if (NULL != pAccounts) {
            //Get 'film' Child
            
            

            XMLElement* pAccount = pAccounts->FirstChildElement("Film");
            while (pAccount) {
               
                Film* film = new Film();      // CREATES NEW FILM OBJECT
                

                XMLElement* pAccountNo = pAccount->FirstChildElement("title");
                if (NULL != pAccountNo) {
                    //film title 
                    
                    film->setTitle( pAccountNo->GetText());
                }
                // SETS FILMS DESCRIPTION
                XMLElement* pDescr = pAccount->FirstChildElement("description");
                if (NULL != pDescr) {
                    film->setDescription( pDescr->GetText());
                }
                //---------------------
                
                //SETS IMAGE PATH
                XMLElement* pImage = pAccount->FirstChildElement("image");
                if (NULL != pImage) {
                    film->setPath(pImage->GetText());
                }
                //---------------------

                // SETS FILM'S GENRE 
                XMLElement* pGenre = pAccount->FirstChildElement("genre");
                if (NULL != pGenre) {
                    film->setGenre(pGenre->GetText());
                }
                //---------------------

                //SETS FILM'S ISSUE DATE
                XMLElement* pDate = pAccount->FirstChildElement("date");
                if (NULL != pDate) {
                    film->setDate(pDate->GetText());
                }
                //-----------------------

                // SETS FILM'S ACTORS' NAMES
                XMLElement* pActors = pAccount->FirstChildElement("actors");
                if (NULL != pActors) {
                    film->setActors(pActors->GetText());
                }
                //-----------------------

                

                list.push_back(film);

                std::string descr = film->getDescription();
                int counter = 0;
                for (const char ch : descr) {
                    if (ch == '\\') {
                        descr.replace(counter, 3, "\n");
                    }
                    counter++;
                }
                film->setDescription(descr);
                

                pAccount = pAccount->NextSiblingElement("Film");


            }
        }
    }

    
	
}

