//
// Created by amina on 5/8/2021.
//

#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <Service/MovieService.h>
#include <QPushButton>
#include <QTextBrowser>
#include <QLineEdit>

#ifndef A89_913_DIACONU_ANA_GUI_H
#define A89_913_DIACONU_ANA_GUI_H


class GUI : public QWidget  {

    Q_OBJECT

private:
    MovieService& _service;
    Movie _working_mov;

    //graphical elements
    QPushButton *UserButton, *AdminButton;
    QPushButton *BarChart;
    QPushButton *exit, *exitAdminMode, *exitUserMode;
    QPushButton *updateTitle, *updateGenre, *updateTrailer, *updateYear, *updateLikes;
    QPushButton *seeWatchList, *removeMovieUser, *seeDatabase, *seeCSVHTML;
    //QListWidget *movieListWidget;
    QPushButton *addMovie, *deleteMovie, *updateMovie,  *listMovie;
    QPushButton  *addButton;
   // QPushButton *updateTitle, *updateGenre, *updateTrailer, *updateLikes, *updateYear;
    QWidget *UserWidget, *AdministratorWidget;
    QWidget *updateWidget;

//
   // QWidget* MovieWidget;
  //  QVBoxLayout* MovieVL;
  //  QFormLayout* MovieLayout;
//
  //  QLineEdit* title, *genre, *trailer, *year, *likes;

public:
    GUI(MovieService& s);

private:
    void initGUI();
    void connectGUI();
    void adminMenuGUI();
    void userMenuGUI();
    void listMovies();
    void showMovieFormLayout();
    static std::string toString(Movie& mov);

    void addMovieF();

    void addMovieAux();
    void deleteMovieAux();
    void updateMenu();

    void updateTitleAux();
    void updateGenreAux();
    void updateTrailerAux();
    void updateYearAux();
    void updateLikesAux();

    void seeWatchListAux();
    void seeDatabaseAux();
    void removeMovieUserAux();
    void seeCSVHTMLAux();

    void viewBarChart();



signals:
    void exitAdmin();
    void addMovieSignal(Movie mov );
};


#endif //A89_913_DIACONU_ANA_GUI_H
